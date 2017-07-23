#pragma once
#include "Windows.h"
#include <gdiplus.h>
#pragma comment(lib,"gdiplus.lib")
#include <string.h>

enum TipoDeImagen{Original, EnGrises, Actualizada};

using namespace System;
using namespace System::Drawing;
using namespace Gdiplus;

const wchar_t *GetWC(const char *c)
{
	const size_t cSize = strlen(c) + 1;
	wchar_t* wc = new wchar_t[cSize];
	mbstowcs(wc, c, cSize);

	return wc;
}

int GetEncoderClsid(const WCHAR* format, CLSID* pClsid)
{
	UINT  num = 0;          // number of image encoders
	UINT  size = 0;         // size of the image encoder array in bytes

	ImageCodecInfo* pImageCodecInfo = NULL;

	GetImageEncodersSize(&num, &size);
	if (size == 0)
		return -1;  // Failure

	pImageCodecInfo = (ImageCodecInfo*)(malloc(size));
	if (pImageCodecInfo == NULL)
		return -1;  // Failure

	GetImageEncoders(num, size, pImageCodecInfo);

	for (UINT j = 0; j < num; ++j)
	{
		if (wcscmp(pImageCodecInfo[j].MimeType, format) == 0)
		{
			*pClsid = pImageCodecInfo[j].Clsid;
			free(pImageCodecInfo);
			return j;  // Success
		}
	}

	free(pImageCodecInfo);
	return -1;  // Failure
}

int MinimoValor;
int MaximoValor;
int * MatrizValores;
int * CantidaDePixelesPorGris;
int * CantidaDePixelesActualizadosPorGris;

void ConvertirAEscalaDeGrises(char* DireccionDeLaImagenOriginal)
{
	Gdiplus::GdiplusStartupInput si;
	ULONG_PTR token;
	Gdiplus::GdiplusStartup(&token, &si, 0);

	MatrizValores = new int[256];
	for (int i = 0; i <= 255; i++)
		MatrizValores[i] = 0;

	CantidaDePixelesPorGris = new int[256];
	for (int i = 0; i <= 255; i++)
		CantidaDePixelesPorGris[i] = 0;

	// load image, any formats supported
	Gdiplus::Bitmap image(GetWC(DireccionDeLaImagenOriginal), false);
	Gdiplus::Bitmap ImagenEnGrises(GetWC(DireccionDeLaImagenOriginal), false);
	Gdiplus::Color ElColorDelPixel;
	int ElAnchoDeLaImagen = image.GetWidth();
	int ElAltoDeLaImagen = image.GetHeight();

	int ElRedDelPixel;
	int ElGreenDelPixel;
	int ElBlueDelPixel;
	int ElGrisDelPixel;

	for (int fila = 1; fila <= ElAltoDeLaImagen; fila++)
	{
		for (int columna = 1; columna <= ElAnchoDeLaImagen; columna++)
		{
			image.GetPixel(columna, fila, &ElColorDelPixel);

			ElRedDelPixel = ElColorDelPixel.GetRed();
			ElGreenDelPixel = ElColorDelPixel.GetGreen();
			ElBlueDelPixel = ElColorDelPixel.GetBlue();

			ElGrisDelPixel = (ElRedDelPixel + ElBlueDelPixel + ElGreenDelPixel) / 3;

			ImagenEnGrises.SetPixel(columna, fila, Gdiplus::Color(ElGrisDelPixel, ElGrisDelPixel, ElGrisDelPixel));
			MatrizValores[ElGrisDelPixel] = MatrizValores[ElGrisDelPixel] + 1;
			CantidaDePixelesPorGris[ElGrisDelPixel] = CantidaDePixelesPorGris[ElGrisDelPixel] + 1;
		}
	}
	CLSID pngClsid;
	GetEncoderClsid(L"image/jpeg", &pngClsid);
	ImagenEnGrises.Save(L"ElResultadoEnGrises.jpeg", &pngClsid, NULL);
}

void ConvertirAImagenActualizada(char* DireccionDeLaImagenEnGrises)
{
	Gdiplus::Bitmap ImagenEcualizada(GetWC(DireccionDeLaImagenEnGrises), false);
	Gdiplus::Color ElColorDelPixel;

	int ElAnchoDeLaImagen = ImagenEcualizada.GetWidth();
	int ElAltoDeLaImagen = ImagenEcualizada.GetHeight();
	int ColorEcualizadoDelPixel;

	int PrimerValor;

	for (int i = 0; i <= 255; i++)
	{
		if (MatrizValores[i] != 0)
			PrimerValor = i;
		break;
	}


	int contsaltos = 0;


	for (int i = PrimerValor + 1; i <= 255; i++)
	{
		if (MatrizValores[i] != 0)
		{
			MatrizValores[i] = MatrizValores[i] + MatrizValores[i - contsaltos - 1];
			contsaltos = 0;
		}
		else
			contsaltos++;
	}

	MinimoValor = MatrizValores[PrimerValor];

	for (int i = PrimerValor + 1; i <= 255; i++)
		if (MatrizValores[i] < MinimoValor && MatrizValores[i] != 0)
			MinimoValor = MatrizValores[i];

	CantidaDePixelesActualizadosPorGris = new int[256];
	for (int i = 0; i <= 255; i++)
		CantidaDePixelesActualizadosPorGris[i] = 0;

	for (int fila = 1; fila <= ElAltoDeLaImagen; fila++)
	{
		for (int columna = 1; columna <= ElAnchoDeLaImagen; columna++)
		{
			ImagenEcualizada.GetPixel(columna, fila, &ElColorDelPixel);
			ColorEcualizadoDelPixel = (MatrizValores[ElColorDelPixel.GetRed()] - MinimoValor) * 255 / ((ElAltoDeLaImagen * ElAnchoDeLaImagen) - MinimoValor);
			CantidaDePixelesActualizadosPorGris[ColorEcualizadoDelPixel] = CantidaDePixelesActualizadosPorGris[ColorEcualizadoDelPixel] + 1;
			ImagenEcualizada.SetPixel(columna, fila, Gdiplus::Color(ColorEcualizadoDelPixel, ColorEcualizadoDelPixel, ColorEcualizadoDelPixel));
		}
	}
	CLSID pngClsid;
	GetEncoderClsid(L"image/jpeg", &pngClsid);
	ImagenEcualizada.Save(L"ElResultadoActualizado.jpeg", &pngClsid, NULL);
}

void ActualizarHistograma(char* DireccionDeLaImagen, System::Drawing::Graphics^ miGraphic)
{
	Gdiplus::Bitmap ImagenEcualizada(GetWC(DireccionDeLaImagen), false);
	int ElAnchoDeLaImagen = ImagenEcualizada.GetWidth();
	int ElAltoDeLaImagen = ImagenEcualizada.GetHeight();

	int TotalDePixeles = ElAltoDeLaImagen * ElAltoDeLaImagen;
	int ValorDeBarraParaHistograma;

	if (strcmp(DireccionDeLaImagen, "ElResultadoEnGrises.jpeg") == 0)
	{
		MaximoValor = CantidaDePixelesPorGris[0];

		for (int i = 1; i <= 255; i++)
		{
			if (CantidaDePixelesPorGris[i] > MaximoValor)
				MaximoValor = CantidaDePixelesPorGris[i];
		}
		miGraphic->Clear(System::Drawing::Color::White);
		for (int i = 0; i <= 255; i++)
		{
			ValorDeBarraParaHistograma = (CantidaDePixelesPorGris[i]) * 300 / (MaximoValor);
			miGraphic->FillRectangle(gcnew System::Drawing::SolidBrush(System::Drawing::Color::Black), i * 2, 300 - ValorDeBarraParaHistograma, 1, ValorDeBarraParaHistograma);
		}
	}

	else if (strcmp(DireccionDeLaImagen, "ElResultadoActualizado.jpeg") == 0)
	{
		MaximoValor = CantidaDePixelesActualizadosPorGris[0];

		for (int i = 1; i <= 255; i++)
		{
			if (CantidaDePixelesActualizadosPorGris[i] > MaximoValor)
				MaximoValor = CantidaDePixelesActualizadosPorGris[i];
		}
		miGraphic->Clear(System::Drawing::Color::White);
		for (int i = 0; i <= 255; i++)
		{
			ValorDeBarraParaHistograma = (CantidaDePixelesActualizadosPorGris[i]) * 300 / (MaximoValor);

			miGraphic->FillRectangle(gcnew System::Drawing::SolidBrush(System::Drawing::Color::Black), i * 2, 300 - ValorDeBarraParaHistograma, 1, ValorDeBarraParaHistograma);
		}
	}
	

}