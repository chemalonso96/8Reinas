#pragma once

#include"Principal.h"

namespace TrabajoParcialComplejidad {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	
	/// <summary>
	/// Resumen de frmTP
	/// </summary>
	public ref class frmTP : public System::Windows::Forms::Form
	{
	private:
		Principal *OBJ_PRINCIPAL;

	private: System::Windows::Forms::Timer^  timer1;
			 Bitmap^BMPQUEEN_1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  labCOMPUTADORA;
	private: System::Windows::Forms::Label^  labJUGADOR;
			 Bitmap^BMPBOARD;
	public:
		frmTP(void)
		{
			OBJ_PRINCIPAL = new Principal();
			BMPQUEEN_1 = gcnew Bitmap("reina.png");
			BMPBOARD = gcnew Bitmap("tablero.jpg");
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~frmTP()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::ComponentModel::IContainer^  components;
	protected:

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->labCOMPUTADORA = (gcnew System::Windows::Forms::Label());
			this->labJUGADOR = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &frmTP::timer1_Tick);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(478, 128);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(94, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"COMPUTADORA:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(478, 199);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(62, 13);
			this->label2->TabIndex = 1;
			this->label2->Text = L"JUGADOR:";
			// 
			// labCOMPUTADORA
			// 
			this->labCOMPUTADORA->AutoSize = true;
			this->labCOMPUTADORA->Location = System::Drawing::Point(481, 161);
			this->labCOMPUTADORA->Name = L"labCOMPUTADORA";
			this->labCOMPUTADORA->Size = System::Drawing::Size(16, 13);
			this->labCOMPUTADORA->TabIndex = 2;
			this->labCOMPUTADORA->Text = L"---";
			// 
			// labJUGADOR
			// 
			this->labJUGADOR->AutoSize = true;
			this->labJUGADOR->Location = System::Drawing::Point(481, 238);
			this->labJUGADOR->Name = L"labJUGADOR";
			this->labJUGADOR->Size = System::Drawing::Size(16, 13);
			this->labJUGADOR->TabIndex = 3;
			this->labJUGADOR->Text = L"---";
			// 
			// frmTP
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(584, 482);
			this->Controls->Add(this->labJUGADOR);
			this->Controls->Add(this->labCOMPUTADORA);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->ForeColor = System::Drawing::Color::Black;
			this->MaximumSize = System::Drawing::Size(600, 521);
			this->MinimumSize = System::Drawing::Size(600, 521);
			this->Name = L"frmTP";
			this->Text = L"frmTP";
			this->Load += gcnew System::EventHandler(this, &frmTP::frmTP_Load);
			this->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &frmTP::frmTP_MouseClick);
			this->MouseDoubleClick += gcnew System::Windows::Forms::MouseEventHandler(this, &frmTP::frmTP_MouseDoubleClick);
			this->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &frmTP::frmTP_MouseMove);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
		Graphics^gr = this->CreateGraphics();
		BufferedGraphicsContext^bgc = BufferedGraphicsManager::Current;
		BufferedGraphics^bg = bgc->Allocate(gr, this->ClientRectangle);
		OBJ_PRINCIPAL->SHOWALL(bg->Graphics,BMPQUEEN_1,BMPBOARD);
		bg->Render(gr);
		delete bg;
		delete bgc;
		delete gr;
	}
	private: System::Void frmTP_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
		this->Text = "X" + e->X.ToString() +"   " +  "Y" + e->Y.ToString();
	}
	private: System::Void frmTP_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
		int i = 1;
		int j = 1;
		if (e->X > 0 && e->X < 60) { i = 0; }
		if (e->X > 60 && e->X < 120) { i = 60; }
		if (e->X > 120 && e->X < 180) { i = 120; }
		if (e->X > 180 && e->X < 240) { i = 180; }
		if (e->X > 240 && e->X < 300) { i = 240; }
		if (e->X > 300 && e->X < 360) { i = 300; }
		if (e->X > 360 && e->X < 420) { i = 360; }
		if (e->X > 420 && e->X < 480) { i = 420; }

		if (e->Y > 0 && e->Y < 60) { j = 0; }
		if (e->Y > 60 && e->Y < 120) { j = 60; }
		if (e->Y > 120 && e->Y < 180) { j = 120; }
		if (e->Y > 180 && e->Y < 240) { j = 180; }
		if (e->Y > 240 && e->Y < 300) { j = 240; }
		if (e->Y > 300 && e->Y < 360) { j = 300; }
		if (e->Y > 360 && e->Y < 420) { j = 360; }
		if (e->Y > 420 && e->Y < 480) { j = 420; }

		OBJ_PRINCIPAL->MOVEHUMANO(i, j, BMPQUEEN_1);
		labCOMPUTADORA->Text = OBJ_PRINCIPAL->ScoreComputer.ToString();
		labJUGADOR->Text = OBJ_PRINCIPAL->ScorePlayer.ToString();
	}
	
	private: System::Void frmTP_MouseDoubleClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
		int i = 1;
		int j = 1;

		if (e->X > 0 && e->X < 60) { i = 0; }
		if (e->X > 60 && e->X < 120) { i = 60; }
		if (e->X > 120 && e->X < 180) { i = 120; }
		if (e->X > 180 && e->X < 240) { i = 180; }
		if (e->X > 240 && e->X < 300) { i = 240; }
		if (e->X > 300 && e->X < 360) { i = 300; }
		if (e->X > 360 && e->X < 420) { i = 360; }
		if (e->X > 420 && e->X < 480) { i = 420; }

		if (e->Y > 0 && e->Y < 60) { j = 0; }
		if (e->Y > 60 && e->Y < 120) { j = 60; }
		if (e->Y > 120 && e->Y < 180) { j = 120; }
		if (e->Y > 180 && e->Y < 240) { j = 180; }
		if (e->Y > 240 && e->Y < 300) { j = 240; }
		if (e->Y > 300 && e->Y < 360) { j = 300; }
		if (e->Y > 360 && e->Y < 420) { j = 360; }
		if (e->Y > 420 && e->Y < 480) { j = 420; }

		if (OBJ_PRINCIPAL->OBJ_VEC_MATRIZ->vec_Matriz[i/60][j/60] == 3) {
			OBJ_PRINCIPAL->ELIMINAR_MIO(i, j, BMPQUEEN_1);
		}
		else if (OBJ_PRINCIPAL->OBJ_VEC_MATRIZ->vec_Matriz[i / 60][j / 60] == 2) {
			OBJ_PRINCIPAL->ELIMINAR_OTRO(i, j, BMPQUEEN_1);
		}
		labJUGADOR->Text = OBJ_PRINCIPAL->ScorePlayer.ToString();
		labCOMPUTADORA->Text = OBJ_PRINCIPAL->ScoreComputer.ToString();
		if (OBJ_PRINCIPAL->ScorePlayer == 0) {
			MessageBox::Show("PERDISTE MEN", "PERDISTE MEN", MessageBoxButtons::OK);
		}
		int datovalidar = OBJ_PRINCIPAL->VALIDARGANADOR();
		if (datovalidar == 1) {
			MessageBox::Show("MAQUINA GANA", "MAQUINA GANA", MessageBoxButtons::OK);
		}
		if (datovalidar== -1) {
			MessageBox::Show("HUMANO GANA", "HUMANO GANA", MessageBoxButtons::OK);
		}
	}
private: System::Void frmTP_Load(System::Object^  sender, System::EventArgs^  e) {

}
};
}
