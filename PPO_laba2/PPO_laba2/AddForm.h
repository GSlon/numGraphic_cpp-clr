#pragma once

namespace PPOlaba2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for AddForm
	/// </summary>
	public ref class AddForm : public System::Windows::Forms::Form
	{
	public:
		AddForm(void)
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
		~AddForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  Edit;
	protected:

	protected:
	private: System::Windows::Forms::Label^  label;
	private: System::Windows::Forms::Button^  Button;


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
			this->Edit = (gcnew System::Windows::Forms::TextBox());
			this->label = (gcnew System::Windows::Forms::Label());
			this->Button = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// Edit
			// 
			this->Edit->Location = System::Drawing::Point(150, 27);
			this->Edit->MaxLength = 4;
			this->Edit->Name = L"Edit";
			this->Edit->Size = System::Drawing::Size(100, 20);
			this->Edit->TabIndex = 0;
			this->Edit->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &AddForm::Edit_KeyDown);
			// 
			// label
			// 
			this->label->AutoSize = true;
			this->label->Location = System::Drawing::Point(56, 27);
			this->label->MinimumSize = System::Drawing::Size(70, 20);
			this->label->Name = L"label";
			this->label->Size = System::Drawing::Size(70, 20);
			this->label->TabIndex = 1;
			this->label->Text = L"Your number:";
			// 
			// Button
			// 
			this->Button->Location = System::Drawing::Point(60, 80);
			this->Button->Name = L"Button";
			this->Button->Size = System::Drawing::Size(190, 25);
			this->Button->TabIndex = 2;
			this->Button->Text = L"Ñonfirm";
			this->Button->UseVisualStyleBackColor = true;
			this->Button->Click += gcnew System::EventHandler(this, &AddForm::Button_Click);
			// 
			// AddForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(304, 141);
			this->Controls->Add(this->Button);
			this->Controls->Add(this->label);
			this->Controls->Add(this->Edit);
			this->MaximumSize = System::Drawing::Size(320, 180);
			this->MinimumSize = System::Drawing::Size(320, 180);
			this->Name = L"AddForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Editor";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private:
		int newElem;

	public: int AddDialog()
	{
		
		this->ShowDialog();
		return newElem;
	}

	private: System::Void Button_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		try
		{
			newElem = Convert::ToInt32(this->Edit->Text);
		}
		catch (System::FormatException ^ex)
		{
			newElem = 0;
		}

		this->Close();
	}

	private: System::Void Edit_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) 
	{
		//MessageBox::Show(Convert::ToString(e->KeyValue));

		if (e->KeyValue == 13)
		{
			this->Button_Click(sender, e);
		}
	}
};
}
