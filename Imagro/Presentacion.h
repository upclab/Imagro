#pragma once
#include "MyForm.h"

namespace Imagro {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Presentacion
	/// </summary>
	public ref class Presentacion : public System::Windows::Forms::Form
	{
	public:
		Presentacion(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Presentacion()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  btnEmpezar;
	protected:

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Presentacion::typeid));
			this->btnEmpezar = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// btnEmpezar
			// 
			this->btnEmpezar->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnEmpezar.BackgroundImage")));
			this->btnEmpezar->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnEmpezar->ForeColor = System::Drawing::Color::White;
			this->btnEmpezar->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnEmpezar.Image")));
			this->btnEmpezar->Location = System::Drawing::Point(257, 442);
			this->btnEmpezar->Name = L"btnEmpezar";
			this->btnEmpezar->Size = System::Drawing::Size(102, 35);
			this->btnEmpezar->TabIndex = 8;
			this->btnEmpezar->Text = L"Empezar";
			this->btnEmpezar->UseVisualStyleBackColor = true;
			this->btnEmpezar->Click += gcnew System::EventHandler(this, &Presentacion::btnEmpezar_Click);
			// 
			// Presentacion
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(600, 500);
			this->Controls->Add(this->btnEmpezar);
			this->MaximizeBox = false;
			this->MaximumSize = System::Drawing::Size(616, 538);
			this->MinimumSize = System::Drawing::Size(616, 538);
			this->Name = L"Presentacion";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->ResumeLayout(false);

		}
#pragma endregion
		private: System::Void btnEmpezar_Click(System::Object^  sender, System::EventArgs^  e) 
		{
			MyForm ^ miFormPrincipal = gcnew MyForm();
			miFormPrincipal->btnAbrir_Click(sender, e);
			if (miFormPrincipal->HayImagen)
			{
				this->Hide();
				
				miFormPrincipal->Show();
				ActualizarHistograma("ElResultadoActualizado.jpeg", miFormPrincipal->miPanel->CreateGraphics());
			}
		}

	};
}
