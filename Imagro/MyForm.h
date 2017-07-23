#pragma once
#include"Funciones.h"
#include<iostream>
#include<stdio.h>
#include "ImagenZoom.h"

namespace Imagro {

	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace std;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			DireccionImagen = new char[150];
			HayImagen = false;
			AnchoVentanaZoom = 1200;
			AltoVentanaZoom = 600;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
			DireccionImagen = NULL;
		}
	private: System::Windows::Forms::PictureBox^  pctEcualizado;
	protected:

	private: System::Windows::Forms::PictureBox^  pctOriginal;
	private: System::Windows::Forms::PictureBox^  pctGrises;
	protected:


	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Button^  btnAbrir;


	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Button^  btnGuardarBN;
	private: System::Windows::Forms::Button^  btnGuardarAjustada;



	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>

		char* DireccionImagen;

		int AnchoVentanaZoom;
		int AltoVentanaZoom;

	public:	bool HayImagen;

	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::GroupBox^  groupBox2;
	private: System::Windows::Forms::GroupBox^  groupBox3;
	private: System::Windows::Forms::GroupBox^  groupBox5;
	private: System::Windows::Forms::GroupBox^  groupBox4;
	public: System::Windows::Forms::Panel^  miPanel;
	private: System::Windows::Forms::RadioButton^  rdNormal;
	private: System::Windows::Forms::RadioButton^  rdAjustado;
	private: System::Windows::Forms::Label^  lblValorGris;
	private: System::Windows::Forms::Label^  lblCantidadGris;
	private: System::ComponentModel::BackgroundWorker^  backgroundWorker1;
	private: System::Windows::Forms::PictureBox^  pictureBox1;


			 System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
			 /// <summary>
			 /// Required method for Designer support - do not modify
			 /// the contents of this method with the code editor.
			 /// </summary>
			 void InitializeComponent(void)
			 {
				 System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
				 this->pctEcualizado = (gcnew System::Windows::Forms::PictureBox());
				 this->pctOriginal = (gcnew System::Windows::Forms::PictureBox());
				 this->pctGrises = (gcnew System::Windows::Forms::PictureBox());
				 this->label1 = (gcnew System::Windows::Forms::Label());
				 this->label2 = (gcnew System::Windows::Forms::Label());
				 this->label3 = (gcnew System::Windows::Forms::Label());
				 this->btnAbrir = (gcnew System::Windows::Forms::Button());
				 this->label4 = (gcnew System::Windows::Forms::Label());
				 this->btnGuardarBN = (gcnew System::Windows::Forms::Button());
				 this->btnGuardarAjustada = (gcnew System::Windows::Forms::Button());
				 this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
				 this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
				 this->groupBox4 = (gcnew System::Windows::Forms::GroupBox());
				 this->groupBox5 = (gcnew System::Windows::Forms::GroupBox());
				 this->miPanel = (gcnew System::Windows::Forms::Panel());
				 this->rdNormal = (gcnew System::Windows::Forms::RadioButton());
				 this->rdAjustado = (gcnew System::Windows::Forms::RadioButton());
				 this->lblValorGris = (gcnew System::Windows::Forms::Label());
				 this->lblCantidadGris = (gcnew System::Windows::Forms::Label());
				 this->backgroundWorker1 = (gcnew System::ComponentModel::BackgroundWorker());
				 this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pctEcualizado))->BeginInit();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pctOriginal))->BeginInit();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pctGrises))->BeginInit();
				 this->groupBox5->SuspendLayout();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
				 this->SuspendLayout();
				 // 
				 // pctEcualizado
				 // 
				 this->pctEcualizado->BackColor = System::Drawing::Color::Transparent;
				 this->pctEcualizado->Location = System::Drawing::Point(227, 201);
				 this->pctEcualizado->Name = L"pctEcualizado";
				 this->pctEcualizado->Size = System::Drawing::Size(300, 300);
				 this->pctEcualizado->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
				 this->pctEcualizado->TabIndex = 0;
				 this->pctEcualizado->TabStop = false;
				 this->pctEcualizado->DoubleClick += gcnew System::EventHandler(this, &MyForm::pctEcualizado_DoubleClick);
				 // 
				 // pctOriginal
				 // 
				 this->pctOriginal->BackColor = System::Drawing::Color::Transparent;
				 this->pctOriginal->Location = System::Drawing::Point(12, 75);
				 this->pctOriginal->Name = L"pctOriginal";
				 this->pctOriginal->Size = System::Drawing::Size(200, 200);
				 this->pctOriginal->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
				 this->pctOriginal->TabIndex = 1;
				 this->pctOriginal->TabStop = false;
				 this->pctOriginal->DoubleClick += gcnew System::EventHandler(this, &MyForm::pctOriginal_DoubleClick);
				 // 
				 // pctGrises
				 // 
				 this->pctGrises->BackColor = System::Drawing::Color::Transparent;
				 this->pctGrises->Location = System::Drawing::Point(12, 309);
				 this->pctGrises->Name = L"pctGrises";
				 this->pctGrises->Size = System::Drawing::Size(200, 200);
				 this->pctGrises->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
				 this->pctGrises->TabIndex = 2;
				 this->pctGrises->TabStop = false;
				 this->pctGrises->DoubleClick += gcnew System::EventHandler(this, &MyForm::pctGrises_DoubleClick);
				 // 
				 // label1
				 // 
				 this->label1->AutoSize = true;
				 this->label1->BackColor = System::Drawing::Color::Transparent;
				 this->label1->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->label1->Location = System::Drawing::Point(11, 50);
				 this->label1->Name = L"label1";
				 this->label1->Size = System::Drawing::Size(82, 22);
				 this->label1->TabIndex = 3;
				 this->label1->Text = L"Original";
				 // 
				 // label2
				 // 
				 this->label2->AutoSize = true;
				 this->label2->BackColor = System::Drawing::Color::Transparent;
				 this->label2->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->label2->Location = System::Drawing::Point(12, 282);
				 this->label2->Name = L"label2";
				 this->label2->Size = System::Drawing::Size(165, 22);
				 this->label2->TabIndex = 4;
				 this->label2->Text = L"Escala De Grises";
				 // 
				 // label3
				 // 
				 this->label3->AutoSize = true;
				 this->label3->BackColor = System::Drawing::Color::Transparent;
				 this->label3->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->label3->Location = System::Drawing::Point(223, 176);
				 this->label3->Name = L"label3";
				 this->label3->Size = System::Drawing::Size(183, 22);
				 this->label3->TabIndex = 5;
				 this->label3->Text = L"Imagen Ecualizada";
				 // 
				 // btnAbrir
				 // 
				 this->btnAbrir->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnAbrir.BackgroundImage")));
				 this->btnAbrir->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->btnAbrir->ForeColor = System::Drawing::Color::White;
				 this->btnAbrir->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnAbrir.Image")));
				 this->btnAbrir->Location = System::Drawing::Point(12, 12);
				 this->btnAbrir->Name = L"btnAbrir";
				 this->btnAbrir->Size = System::Drawing::Size(102, 35);
				 this->btnAbrir->TabIndex = 6;
				 this->btnAbrir->Text = L"Abrir Imagen";
				 this->btnAbrir->UseVisualStyleBackColor = true;
				 this->btnAbrir->Click += gcnew System::EventHandler(this, &MyForm::btnAbrir_Click);
				 // 
				 // label4
				 // 
				 this->label4->AutoSize = true;
				 this->label4->BackColor = System::Drawing::Color::Transparent;
				 this->label4->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->label4->Location = System::Drawing::Point(539, 176);
				 this->label4->Name = L"label4";
				 this->label4->Size = System::Drawing::Size(116, 22);
				 this->label4->TabIndex = 8;
				 this->label4->Text = L"Histograma";
				 // 
				 // btnGuardarBN
				 // 
				 this->btnGuardarBN->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnGuardarBN.BackgroundImage")));
				 this->btnGuardarBN->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->btnGuardarBN->ForeColor = System::Drawing::Color::White;
				 this->btnGuardarBN->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnGuardarBN.Image")));
				 this->btnGuardarBN->Location = System::Drawing::Point(12, 519);
				 this->btnGuardarBN->Name = L"btnGuardarBN";
				 this->btnGuardarBN->Size = System::Drawing::Size(102, 35);
				 this->btnGuardarBN->TabIndex = 9;
				 this->btnGuardarBN->Text = L"Guardar B/N";
				 this->btnGuardarBN->UseVisualStyleBackColor = true;
				 this->btnGuardarBN->Click += gcnew System::EventHandler(this, &MyForm::btnGuardarBN_Click);
				 // 
				 // btnGuardarAjustada
				 // 
				 this->btnGuardarAjustada->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnGuardarAjustada.BackgroundImage")));
				 this->btnGuardarAjustada->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->btnGuardarAjustada->ForeColor = System::Drawing::Color::White;
				 this->btnGuardarAjustada->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnGuardarAjustada.Image")));
				 this->btnGuardarAjustada->Location = System::Drawing::Point(227, 515);
				 this->btnGuardarAjustada->Name = L"btnGuardarAjustada";
				 this->btnGuardarAjustada->Size = System::Drawing::Size(119, 35);
				 this->btnGuardarAjustada->TabIndex = 10;
				 this->btnGuardarAjustada->Text = L"Guardar Imagen";
				 this->btnGuardarAjustada->UseVisualStyleBackColor = true;
				 this->btnGuardarAjustada->Click += gcnew System::EventHandler(this, &MyForm::btnGuardarAjustada_Click);
				 // 
				 // groupBox1
				 // 
				 this->groupBox1->BackColor = System::Drawing::Color::Transparent;
				 this->groupBox1->Location = System::Drawing::Point(9, 67);
				 this->groupBox1->MinimumSize = System::Drawing::Size(200, 200);
				 this->groupBox1->Name = L"groupBox1";
				 this->groupBox1->Size = System::Drawing::Size(207, 212);
				 this->groupBox1->TabIndex = 11;
				 this->groupBox1->TabStop = false;
				 // 
				 // groupBox3
				 // 
				 this->groupBox3->BackColor = System::Drawing::Color::Transparent;
				 this->groupBox3->Location = System::Drawing::Point(9, 301);
				 this->groupBox3->Name = L"groupBox3";
				 this->groupBox3->Size = System::Drawing::Size(207, 212);
				 this->groupBox3->TabIndex = 12;
				 this->groupBox3->TabStop = false;
				 // 
				 // groupBox4
				 // 
				 this->groupBox4->BackColor = System::Drawing::Color::Transparent;
				 this->groupBox4->Location = System::Drawing::Point(224, 193);
				 this->groupBox4->Name = L"groupBox4";
				 this->groupBox4->Size = System::Drawing::Size(307, 312);
				 this->groupBox4->TabIndex = 13;
				 this->groupBox4->TabStop = false;
				 // 
				 // groupBox5
				 // 
				 this->groupBox5->BackColor = System::Drawing::Color::Transparent;
				 this->groupBox5->Controls->Add(this->miPanel);
				 this->groupBox5->Location = System::Drawing::Point(537, 198);
				 this->groupBox5->Name = L"groupBox5";
				 this->groupBox5->Size = System::Drawing::Size(518, 312);
				 this->groupBox5->TabIndex = 0;
				 this->groupBox5->TabStop = false;
				 // 
				 // miPanel
				 // 
				 this->miPanel->Location = System::Drawing::Point(3, 8);
				 this->miPanel->Name = L"miPanel";
				 this->miPanel->Size = System::Drawing::Size(512, 300);
				 this->miPanel->TabIndex = 8;
				 this->miPanel->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::miPanel_MouseMove);
				 // 
				 // rdNormal
				 // 
				 this->rdNormal->AutoCheck = false;
				 this->rdNormal->AutoSize = true;
				 this->rdNormal->BackColor = System::Drawing::Color::Transparent;
				 this->rdNormal->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->rdNormal->Location = System::Drawing::Point(709, 181);
				 this->rdNormal->Name = L"rdNormal";
				 this->rdNormal->Size = System::Drawing::Size(160, 20);
				 this->rdNormal->TabIndex = 14;
				 this->rdNormal->TabStop = true;
				 this->rdNormal->Text = L"Histograma Normal";
				 this->rdNormal->UseVisualStyleBackColor = false;
				 this->rdNormal->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::rdNormal_MouseClick);
				 // 
				 // rdAjustado
				 // 
				 this->rdAjustado->AutoCheck = false;
				 this->rdAjustado->AutoSize = true;
				 this->rdAjustado->BackColor = System::Drawing::Color::Transparent;
				 this->rdAjustado->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->rdAjustado->Location = System::Drawing::Point(883, 181);
				 this->rdAjustado->Name = L"rdAjustado";
				 this->rdAjustado->Size = System::Drawing::Size(187, 20);
				 this->rdAjustado->TabIndex = 15;
				 this->rdAjustado->TabStop = true;
				 this->rdAjustado->Text = L"Histograma Ecualizado";
				 this->rdAjustado->UseVisualStyleBackColor = false;
				 this->rdAjustado->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::rdAjustado_MouseClick);
				 // 
				 // lblValorGris
				 // 
				 this->lblValorGris->AutoSize = true;
				 this->lblValorGris->BackColor = System::Drawing::Color::Transparent;
				 this->lblValorGris->Font = (gcnew System::Drawing::Font(L"Palatino Linotype", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->lblValorGris->Location = System::Drawing::Point(540, 519);
				 this->lblValorGris->Name = L"lblValorGris";
				 this->lblValorGris->Size = System::Drawing::Size(88, 17);
				 this->lblValorGris->TabIndex = 16;
				 this->lblValorGris->Text = L"Valor del Gris: ";
				 // 
				 // lblCantidadGris
				 // 
				 this->lblCantidadGris->AutoSize = true;
				 this->lblCantidadGris->BackColor = System::Drawing::Color::Transparent;
				 this->lblCantidadGris->Font = (gcnew System::Drawing::Font(L"Palatino Linotype", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->lblCantidadGris->Location = System::Drawing::Point(652, 519);
				 this->lblCantidadGris->Name = L"lblCantidadGris";
				 this->lblCantidadGris->Size = System::Drawing::Size(105, 17);
				 this->lblCantidadGris->TabIndex = 17;
				 this->lblCantidadGris->Text = L"Cantidad del Gris:";
				 // 
				 // pictureBox1
				 // 
				 this->pictureBox1->BackColor = System::Drawing::Color::Transparent;
				 this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
				 this->pictureBox1->Location = System::Drawing::Point(771, -74);
				 this->pictureBox1->Name = L"pictureBox1";
				 this->pictureBox1->Size = System::Drawing::Size(321, 336);
				 this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
				 this->pictureBox1->TabIndex = 18;
				 this->pictureBox1->TabStop = false;
				 // 
				 // MyForm
				 // 
				 this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
				 this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
				 this->BackColor = System::Drawing::Color::White;
				 this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
				 this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
				 this->ClientSize = System::Drawing::Size(1066, 562);
				 this->Controls->Add(this->lblCantidadGris);
				 this->Controls->Add(this->lblValorGris);
				 this->Controls->Add(this->rdAjustado);
				 this->Controls->Add(this->rdNormal);
				 this->Controls->Add(this->groupBox5);
				 this->Controls->Add(this->btnGuardarAjustada);
				 this->Controls->Add(this->btnGuardarBN);
				 this->Controls->Add(this->label4);
				 this->Controls->Add(this->btnAbrir);
				 this->Controls->Add(this->label3);
				 this->Controls->Add(this->label2);
				 this->Controls->Add(this->label1);
				 this->Controls->Add(this->pctEcualizado);
				 this->Controls->Add(this->pctOriginal);
				 this->Controls->Add(this->groupBox1);
				 this->Controls->Add(this->pctGrises);
				 this->Controls->Add(this->groupBox3);
				 this->Controls->Add(this->groupBox4);
				 this->Controls->Add(this->pictureBox1);
				 this->MaximizeBox = false;
				 this->MaximumSize = System::Drawing::Size(1082, 600);
				 this->MinimumSize = System::Drawing::Size(1082, 600);
				 this->Name = L"MyForm";
				 this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
				 this->Text = L"Imagro";
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pctEcualizado))->EndInit();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pctOriginal))->EndInit();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pctGrises))->EndInit();
				 this->groupBox5->ResumeLayout(false);
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
				 this->ResumeLayout(false);
				 this->PerformLayout();

			 }

#pragma endregion

	public: System::Void btnAbrir_Click(System::Object^  sender, System::EventArgs^  e)
	{
		//Se crea una ventana para poder escoger una imagen
		OpenFileDialog^ VentanaParaAbrirImagenes = gcnew OpenFileDialog;
		VentanaParaAbrirImagenes->Filter = "Image Files|*.jpg;*.jpeg;*.png;*.bmp;*.gif|JPEG Files (*.jpeg)|*.jpeg|PNG Files (*.png)|*.png|JPG Files (*.jpg)|*.jpg|BMP Files (*.bmp)|*.bmp";

		//El siguiente if es para cuando se escoja una imagen
		if (VentanaParaAbrirImagenes->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			//Se copia la direccion de la imagen a "DireccionImagen" con la funcion "sprintf"
			sprintf(DireccionImagen, "%s", VentanaParaAbrirImagenes->FileName);
			//Se utiliza "DireccionImagen" para mostrar LA IMAGEN ORIGINAL en "pctOriginal"
			pctOriginal->ImageLocation = gcnew System::String(DireccionImagen);

			ConvertirAEscalaDeGrises(DireccionImagen);
			pctGrises->ImageLocation = gcnew System::String("ElResultadoEnGrises.jpeg");

			ConvertirAImagenActualizada("ElResultadoEnGrises.jpeg");
			pctEcualizado->ImageLocation = gcnew System::String("ElResultadoActualizado.jpeg");

			ActualizarHistograma("ElResultadoActualizado.jpeg", miPanel->CreateGraphics());

			HayImagen = true;
			rdNormal->Checked = false;
			rdAjustado->Checked = true;
		}
		
	}

	private: System::Void rdNormal_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)
	{
		rdAjustado->Checked = false;
		if (HayImagen)
		{
			ActualizarHistograma("ElResultadoEnGrises.jpeg", miPanel->CreateGraphics());
			rdNormal->Checked = true;
		}
	}

	private: System::Void rdAjustado_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)
	{
		rdNormal->Checked = false;
		if (HayImagen)
		{
			ActualizarHistograma("ElResultadoActualizado.jpeg", miPanel->CreateGraphics());
			rdAjustado->Checked = true;
		}
	}

	private: System::Void miPanel_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)
	{
		if (rdNormal->Checked)
		{
			lblValorGris->Text = "Valor del Gris: " + ((e->X) / 2).ToString();
			lblCantidadGris->Text = "Cantidad del Gris: " + CantidaDePixelesPorGris[(e->X) / 2].ToString();
		}
		if (rdAjustado->Checked)
		{
			lblValorGris->Text = "Valor del Gris: " + ((e->X) / 2).ToString();
			lblCantidadGris->Text = "Cantidad del Gris: " + CantidaDePixelesActualizadosPorGris[(e->X) / 2].ToString();
		}
	}

	public: void CambiarAnchoYAltoDeVentanaZoom(TipoDeImagen ElTipoDeImagen)
	{
		Gdiplus::Bitmap ImagenOriginal(GetWC(DireccionImagen), false);
		Gdiplus::Bitmap ImagenEnGrises(GetWC("ElResultadoEnGrises.jpeg"), false);
		Gdiplus::Bitmap ImagenActualizada(GetWC("ElResultadoActualizado.jpeg"), false);

		switch (ElTipoDeImagen)
		{
		case Original:


			AnchoVentanaZoom = ImagenOriginal.GetWidth();
			AltoVentanaZoom = ImagenOriginal.GetHeight();

			break;

		case EnGrises:


			AnchoVentanaZoom = ImagenEnGrises.GetWidth();
			AltoVentanaZoom = ImagenEnGrises.GetHeight();

			break;

		case Actualizada:


			AnchoVentanaZoom = ImagenActualizada.GetWidth();
			AltoVentanaZoom = ImagenActualizada.GetHeight();

			break;
		}

		if (AnchoVentanaZoom >= 2 * AltoVentanaZoom)
		{
			AltoVentanaZoom *= 1200.0 / AnchoVentanaZoom;
			AnchoVentanaZoom = 1200;
		}
		else
		{
			AnchoVentanaZoom *= 600.0 / AltoVentanaZoom;
			AltoVentanaZoom = 600;
		}
	}

	private: System::Void pctOriginal_DoubleClick(System::Object^  sender, System::EventArgs^  e)
	{
		CambiarAnchoYAltoDeVentanaZoom(TipoDeImagen::Original);
		ImagenZoom ^ vntOriginal = gcnew ImagenZoom();
		vntOriginal->YaCambioDeTamanio = false;
		vntOriginal->ClientSize = System::Drawing::Size(AnchoVentanaZoom, AltoVentanaZoom);
		vntOriginal->pctImagen->Size = System::Drawing::Size(AnchoVentanaZoom, AltoVentanaZoom);
		vntOriginal->MaximumSize = System::Drawing::Size(AnchoVentanaZoom + 16, AltoVentanaZoom + 38);
		vntOriginal->YaCambioDeTamanio = true;
		vntOriginal->pctImagen->Location = System::Drawing::Point(0, 0);
		vntOriginal->pctImagen->ImageLocation = gcnew System::String(DireccionImagen);
		vntOriginal->Text = L"Imagen Original";
		vntOriginal->Show();

	}

	private: System::Void pctGrises_DoubleClick(System::Object^  sender, System::EventArgs^  e)
	{
		CambiarAnchoYAltoDeVentanaZoom(TipoDeImagen::EnGrises);
		ImagenZoom ^ vntGrises = gcnew ImagenZoom();
		vntGrises->YaCambioDeTamanio = false;
		vntGrises->ClientSize = System::Drawing::Size(AnchoVentanaZoom, AltoVentanaZoom);
		vntGrises->pctImagen->Size = System::Drawing::Size(AnchoVentanaZoom, AltoVentanaZoom);
		vntGrises->MaximumSize = System::Drawing::Size(AnchoVentanaZoom + 16, AltoVentanaZoom + 38);
		vntGrises->YaCambioDeTamanio = true;
		vntGrises->pctImagen->Location = System::Drawing::Point(0, 0);
		vntGrises->pctImagen->ImageLocation = gcnew System::String("ElResultadoEnGrises.jpeg");
		vntGrises->Text = L"Imagen En Grises";
		vntGrises->Show();
	}

	private: System::Void pctEcualizado_DoubleClick(System::Object^  sender, System::EventArgs^  e)
	{
		CambiarAnchoYAltoDeVentanaZoom(TipoDeImagen::Actualizada);
		ImagenZoom ^ vntActualizada = gcnew ImagenZoom();
		vntActualizada->YaCambioDeTamanio = false;
		vntActualizada->ClientSize = System::Drawing::Size(AnchoVentanaZoom, AltoVentanaZoom);
		vntActualizada->pctImagen->Size = System::Drawing::Size(AnchoVentanaZoom, AltoVentanaZoom);
		vntActualizada->MaximumSize = System::Drawing::Size(AnchoVentanaZoom + 16, AltoVentanaZoom + 38);
		vntActualizada->YaCambioDeTamanio = true;
		vntActualizada->pctImagen->Location = System::Drawing::Point(0, 0);
		vntActualizada->pctImagen->ImageLocation = gcnew System::String("ElResultadoActualizado.jpeg");
		vntActualizada->Text = L"Imagen Actualizada";
		vntActualizada->Show();
	}

	private: System::Void btnGuardarBN_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		SaveFileDialog^ VentanaParaGuardarImagenes = gcnew SaveFileDialog();
		VentanaParaGuardarImagenes->FileName = "Imagen";
		VentanaParaGuardarImagenes->Title = "Guardar Imagen Blanco y Negro";
		VentanaParaGuardarImagenes->DefaultExt = "jpeg";
		VentanaParaGuardarImagenes->ValidateNames = true;
	
		VentanaParaGuardarImagenes->Filter = "JPEG Image (.jpeg)|*.jpeg|Bitmap Image (.bmp)|*.bmp|Gif Image (.gif)|*.gif|Png Image (.png)|*.png";

		if (VentanaParaGuardarImagenes->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			Gdiplus::Bitmap ImagenEnGrises(GetWC("ElResultadoEnGrises.jpeg"), false);
			CLSID pngClsid;

			if (VentanaParaGuardarImagenes->FilterIndex == 1)
			{
				GetEncoderClsid(L"image/jpeg", &pngClsid);
				char* DireccionDelArchivo = (char*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(VentanaParaGuardarImagenes->FileName).ToPointer();
				ImagenEnGrises.Save(GetWC(DireccionDelArchivo), &pngClsid, NULL);
				System::Runtime::InteropServices::Marshal::FreeHGlobal((IntPtr)DireccionDelArchivo);
			}
			else if (VentanaParaGuardarImagenes->FilterIndex == 2)
			{
				GetEncoderClsid(L"image/bmp", &pngClsid);
				char* DireccionDelArchivo = (char*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(VentanaParaGuardarImagenes->FileName).ToPointer();
				ImagenEnGrises.Save(GetWC(DireccionDelArchivo), &pngClsid, NULL);
				System::Runtime::InteropServices::Marshal::FreeHGlobal((IntPtr)DireccionDelArchivo);
			}
			else if (VentanaParaGuardarImagenes->FilterIndex == 3)
			{
				GetEncoderClsid(L"image/gif", &pngClsid);
				char* DireccionDelArchivo = (char*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(VentanaParaGuardarImagenes->FileName).ToPointer();
				ImagenEnGrises.Save(GetWC(DireccionDelArchivo), &pngClsid, NULL);
				System::Runtime::InteropServices::Marshal::FreeHGlobal((IntPtr)DireccionDelArchivo);
			}
			else if (VentanaParaGuardarImagenes->FilterIndex == 4)
			{
				GetEncoderClsid(L"image/png", &pngClsid);
				char* DireccionDelArchivo = (char*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(VentanaParaGuardarImagenes->FileName).ToPointer();
				ImagenEnGrises.Save(GetWC(DireccionDelArchivo), &pngClsid, NULL);
				System::Runtime::InteropServices::Marshal::FreeHGlobal((IntPtr)DireccionDelArchivo);
			}
			
		}
	}

	private: System::Void btnGuardarAjustada_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		SaveFileDialog^ VentanaParaGuardarImagenes = gcnew SaveFileDialog();
		VentanaParaGuardarImagenes->FileName = "Imagen";
		VentanaParaGuardarImagenes->Title = "Guardar Imagen Actualizada";
		VentanaParaGuardarImagenes->DefaultExt = "jpeg";
		VentanaParaGuardarImagenes->ValidateNames = true;

		VentanaParaGuardarImagenes->Filter = "JPEG Image (.jpeg)|*.jpeg|Bitmap Image (.bmp)|*.bmp|Gif Image (.gif)|*.gif|Png Image (.png)|*.png";

		if (VentanaParaGuardarImagenes->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			Gdiplus::Bitmap ImagenEnGrises(GetWC("ElResultadoActualizado.jpeg"), false);
			CLSID pngClsid;

			if (VentanaParaGuardarImagenes->FilterIndex == 1)
			{
				GetEncoderClsid(L"image/jpeg", &pngClsid);
				char* DireccionDelArchivo = (char*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(VentanaParaGuardarImagenes->FileName).ToPointer();
				ImagenEnGrises.Save(GetWC(DireccionDelArchivo), &pngClsid, NULL);
				System::Runtime::InteropServices::Marshal::FreeHGlobal((IntPtr)DireccionDelArchivo);
			}
			else if (VentanaParaGuardarImagenes->FilterIndex == 2)
			{
				GetEncoderClsid(L"image/bmp", &pngClsid);
				char* DireccionDelArchivo = (char*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(VentanaParaGuardarImagenes->FileName).ToPointer();
				ImagenEnGrises.Save(GetWC(DireccionDelArchivo), &pngClsid, NULL);
				System::Runtime::InteropServices::Marshal::FreeHGlobal((IntPtr)DireccionDelArchivo);
			}
			else if (VentanaParaGuardarImagenes->FilterIndex == 3)
			{
				GetEncoderClsid(L"image/gif", &pngClsid);
				char* DireccionDelArchivo = (char*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(VentanaParaGuardarImagenes->FileName).ToPointer();
				ImagenEnGrises.Save(GetWC(DireccionDelArchivo), &pngClsid, NULL);
				System::Runtime::InteropServices::Marshal::FreeHGlobal((IntPtr)DireccionDelArchivo);
			}
			else if (VentanaParaGuardarImagenes->FilterIndex == 4)
			{
				GetEncoderClsid(L"image/png", &pngClsid);
				char* DireccionDelArchivo = (char*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(VentanaParaGuardarImagenes->FileName).ToPointer();
				ImagenEnGrises.Save(GetWC(DireccionDelArchivo), &pngClsid, NULL);
				System::Runtime::InteropServices::Marshal::FreeHGlobal((IntPtr)DireccionDelArchivo);
			}

		}
	}
};
}