#pragma once

#include "RList.h"
#include "AddForm.h"

namespace PPOlaba2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

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
			list = gcnew RList<int>();

			//
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
		}
	private: System::Windows::Forms::MenuStrip^  Menu;
	protected:
	private: System::Windows::Forms::ToolStripMenuItem^  addToolStripMenuItem;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^  ChartCircle;

	private: System::Windows::Forms::ToolStripMenuItem^  deleteToolStripMenuItem;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^  ChartColumn;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;



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
			System::Windows::Forms::DataVisualization::Charting::ChartArea^  chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^  legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^  series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::ChartArea^  chartArea2 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^  legend2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^  series2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			this->Menu = (gcnew System::Windows::Forms::MenuStrip());
			this->addToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->deleteToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ChartCircle = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->ChartColumn = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->Menu->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ChartCircle))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ChartColumn))->BeginInit();
			this->SuspendLayout();
			// 
			// Menu
			// 
			this->Menu->BackColor = System::Drawing::SystemColors::ControlLight;
			this->Menu->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) { this->addToolStripMenuItem, this->deleteToolStripMenuItem });
			this->Menu->Location = System::Drawing::Point(0, 0);
			this->Menu->Name = L"Menu";
			this->Menu->Size = System::Drawing::Size(619, 24);
			this->Menu->TabIndex = 0;
			this->Menu->Text = L"menu";
			// 
			// addToolStripMenuItem
			// 
			this->addToolStripMenuItem->Name = L"addToolStripMenuItem";
			this->addToolStripMenuItem->Size = System::Drawing::Size(41, 20);
			this->addToolStripMenuItem->Text = L"Add";
			this->addToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::addToolStripMenuItem_Click);
			// 
			// deleteToolStripMenuItem
			// 
			this->deleteToolStripMenuItem->Name = L"deleteToolStripMenuItem";
			this->deleteToolStripMenuItem->Size = System::Drawing::Size(52, 20);
			this->deleteToolStripMenuItem->Text = L"Delete";
			this->deleteToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::deleteToolStripMenuItem_Click);
			// 
			// ChartCircle
			// 
			chartArea1->Name = L"ChartArea1";
			this->ChartCircle->ChartAreas->Add(chartArea1);
			legend1->Name = L"Legend1";
			this->ChartCircle->Legends->Add(legend1);
			this->ChartCircle->Location = System::Drawing::Point(0, 27);
			this->ChartCircle->Name = L"ChartCircle";
			series1->ChartArea = L"ChartArea1";
			series1->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Doughnut;
			series1->Legend = L"Legend1";
			series1->Name = L"RingListView";
			this->ChartCircle->Series->Add(series1);
			this->ChartCircle->Size = System::Drawing::Size(308, 308);
			this->ChartCircle->TabIndex = 1;
			this->ChartCircle->Text = L"Chart";
			// 
			// ChartColumn
			// 
			chartArea2->Name = L"ChartArea1";
			this->ChartColumn->ChartAreas->Add(chartArea2);
			legend2->Name = L"Legend1";
			this->ChartColumn->Legends->Add(legend2);
			this->ChartColumn->Location = System::Drawing::Point(314, 27);
			this->ChartColumn->Name = L"ChartColumn";
			this->ChartColumn->Palette = System::Windows::Forms::DataVisualization::Charting::ChartColorPalette::SeaGreen;
			series2->ChartArea = L"ChartArea1";
			series2->Legend = L"Legend1";
			series2->Name = L"RingListView";
			this->ChartColumn->Series->Add(series2);
			this->ChartColumn->Size = System::Drawing::Size(305, 308);
			this->ChartColumn->TabIndex = 2;
			this->ChartColumn->Text = L"chartCol";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(215, 40);
			this->label1->MaximumSize = System::Drawing::Size(19, 13);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(19, 13);
			this->label1->TabIndex = 3;
			this->label1->Text = L">0";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(215, 53);
			this->label2->MaximumSize = System::Drawing::Size(19, 13);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(19, 13);
			this->label2->TabIndex = 4;
			this->label2->Text = L"<0";
			this->label2->Click += gcnew System::EventHandler(this, &MyForm::label2_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(221, 66);
			this->label3->MaximumSize = System::Drawing::Size(19, 13);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(13, 13);
			this->label3->TabIndex = 5;
			this->label3->Text = L"0";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(619, 341);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->ChartColumn);
			this->Controls->Add(this->ChartCircle);
			this->Controls->Add(this->Menu);
			this->Cursor = System::Windows::Forms::Cursors::Hand;
			this->DoubleBuffered = true;
			this->MainMenuStrip = this->Menu;
			this->MaximumSize = System::Drawing::Size(635, 380);
			this->MinimumSize = System::Drawing::Size(635, 380);
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Ring List";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->Menu->ResumeLayout(false);
			this->Menu->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ChartCircle))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ChartColumn))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	// переменные
	private:
		RList<int> ^list;

	// функции
	private:
		RList<int>^ Sort(RList<int> ^list)
		{
			if (list->Size() == 0)
				return list;

			// сортируем
			vector<int> elements = list->getElem();
			sort(elements.begin(), elements.end());

			// заполняем
			RList<int>::Iterator ^iter = list->begin();
			for (int i = 0; i < list->Size(); i++)
			{
				*iter = elements[i];
				++iter;
			}

			return list;
		}

	private: System::Void addToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) 
	{		
		AddForm add;
		int newElem = add.AddDialog();
		list->add(newElem);

		this->DrawListView();
	}

	private: System::Void deleteToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		//AddForm add;
		//int delElem = add.AddDialog();
		//list->erase(delElem);

		list->erase();
		this->DrawListView();
	}

	private: Void DrawListView()
	{
		list = this->Sort(list);

		// очистка
		this->ChartCircle->Series["RingListView"]->Points->Clear();
		this->ChartColumn->Series["RingListView"]->Points->Clear();

		// проверка на не пустой лист 
		RList<int>::Iterator ^iter;
		try
		{
			iter = list->begin();
		}
		catch (const System::IndexOutOfRangeException ^ex)
		{
			return;
		}
		
		int poz = 0, neg = 0, zero = 0, temp = 0;
		do
		{
			temp = *iter;
			if (temp > 0)
				++poz;
			else
				if (temp < 0)
					++neg;
				else
					if (temp == 0)
						++zero;

			this->ChartColumn->Series["RingListView"]->Points->AddY(*iter);	// отрисовка столбиков
			++iter;
		} 
		while (iter != list->begin());
		
		// отрисовка диаграммы 
		this->ChartCircle->Series["RingListView"]->Points->AddXY(poz, poz);
		this->ChartCircle->Series["RingListView"]->Points->AddXY(neg, neg);
		this->ChartCircle->Series["RingListView"]->Points->AddXY(zero, zero);			
	}


private: System::Void label2_Click(System::Object^  sender, System::EventArgs^  e)
{
}
private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
}
};
}
