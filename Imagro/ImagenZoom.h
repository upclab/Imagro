#pragma once

namespace Imagro {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for ImagenZoom
	/// </summary>
	public ref class ImagenZoom : public System::Windows::Forms::Form
	{
	public:
		ImagenZoom(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			YaCambioDeTamanio = false;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~ImagenZoom()
		{
			if (components)
			{
				delete components;
			}
		}
	public: System::Windows::Forms::PictureBox^  pctImagen;
	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
	public: bool YaCambioDeTamanio;

		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->pctImagen = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pctImagen))->BeginInit();
			this->SuspendLayout();
			// 
			// pctImagen
			// 
			this->pctImagen->Location = System::Drawing::Point(0, 0);
			this->pctImagen->Name = L"pctImagen";
			this->pctImagen->Size = System::Drawing::Size(1200, 600);
			this->pctImagen->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pctImagen->TabIndex = 0;
			this->pctImagen->TabStop = false;
			// 
			// ImagenZoom
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1200, 600);
			this->Controls->Add(this->pctImagen);
			this->MaximizeBox = false;
			this->MaximumSize = System::Drawing::Size(1216, 638);
			this->Name = L"ImagenZoom";
			this->Text = L"Imagro";
			this->SizeChanged += gcnew System::EventHandler(this, &ImagenZoom::ImagenZoom_SizeChanged);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pctImagen))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void ImagenZoom_SizeChanged(System::Object^  sender, System::EventArgs^  e)
	{
		if (YaCambioDeTamanio)
		{
			if (((this->Width) - 16)* 1.0 / ((this->Height) - 38) >= (this->MaximumSize.Width - 16)* 1.0 / (this->MaximumSize.Height - 38))
			{
				this->Height = (((this->Width)) - 16)* 1.0 *(this->MaximumSize.Height - 38) / (this->MaximumSize.Width - 16) + 38;
				pctImagen->Size = System::Drawing::Size((this->Width) - 16, (this->Height) - 38);
			}
			else
			{
				this->Width = ((this->Height) - 38)* 1.0 *(this->MaximumSize.Width - 16) / (this->MaximumSize.Height - 38) + 16;
				pctImagen->Size = System::Drawing::Size((this->Width) - 16, (this->Height) - 38);
			}
		}
	}

	};
}
