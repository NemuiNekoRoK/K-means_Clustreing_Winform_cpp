#pragma once
#include <string>
#include <fstream>

#define k 3
#define num_data 20


int data[num_data][2];
int group[num_data];

void dataread();
void kmeans();
void printData();
void readfile();



namespace CppCLRWinformsProjekt {

	using namespace std;
	using namespace System;
	using namespace System::IO;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Zusammenfassung f? Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Konstruktorcode hier hinzuf?en.
			//
		}

	protected:
		/// <summary>
		/// Verwendete Ressourcen bereinigen.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ 파일;
	protected:

	private: System::Windows::Forms::ToolStripMenuItem^ 열기;
	private: System::Windows::Forms::ToolStripMenuItem^ 저장;
	private: System::Windows::Forms::RichTextBox^ richTextBox1;
	private: System::Windows::Forms::RichTextBox^ richTextBox2;
	private: System::Windows::Forms::Button^ 클러스터링;
	private: System::Windows::Forms::ToolStripMenuItem^ 그래프변환ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ 산점도ToolStripMenuItem;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ chart1;




	private:
		/// <summary>
		/// Erforderliche Designervariable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Erforderliche Methode f? die Designerunterst?zung.
		/// Der Inhalt der Methode darf nicht mit dem Code-Editor ge?dert werden.
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^ series2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^ series3 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->파일 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->열기 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->저장 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->그래프변환ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->산점도ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->richTextBox2 = (gcnew System::Windows::Forms::RichTextBox());
			this->클러스터링 = (gcnew System::Windows::Forms::Button());
			this->chart1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->menuStrip1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->BeginInit();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) { this->파일, this->그래프변환ToolStripMenuItem });
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(946, 24);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// 파일
			// 
			this->파일->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) { this->열기, this->저장 });
			this->파일->Name = L"파일";
			this->파일->Size = System::Drawing::Size(43, 20);
			this->파일->Text = L"파일";
			// 
			// 열기
			// 
			this->열기->Name = L"열기";
			this->열기->Size = System::Drawing::Size(98, 22);
			this->열기->Text = L"열기";
			this->열기->Click += gcnew System::EventHandler(this, &Form1::열기_Click);
			// 
			// 저장
			// 
			this->저장->Name = L"저장";
			this->저장->Size = System::Drawing::Size(98, 22);
			this->저장->Text = L"저장";
			// 
			// 그래프변환ToolStripMenuItem
			// 
			this->그래프변환ToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->산점도ToolStripMenuItem });
			this->그래프변환ToolStripMenuItem->Name = L"그래프변환ToolStripMenuItem";
			this->그래프변환ToolStripMenuItem->Size = System::Drawing::Size(23, 20);
			this->그래프변환ToolStripMenuItem->Text = L" ";
			// 
			// 산점도ToolStripMenuItem
			// 
			this->산점도ToolStripMenuItem->Name = L"산점도ToolStripMenuItem";
			this->산점도ToolStripMenuItem->Size = System::Drawing::Size(110, 22);
			this->산점도ToolStripMenuItem->Text = L"산점도";
			// 
			// richTextBox1
			// 
			this->richTextBox1->Location = System::Drawing::Point(12, 49);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->ReadOnly = true;
			this->richTextBox1->ScrollBars = System::Windows::Forms::RichTextBoxScrollBars::Vertical;
			this->richTextBox1->Size = System::Drawing::Size(246, 467);
			this->richTextBox1->TabIndex = 1;
			this->richTextBox1->Text = L"";
			// 
			// richTextBox2
			// 
			this->richTextBox2->BackColor = System::Drawing::SystemColors::Control;
			this->richTextBox2->Location = System::Drawing::Point(360, 49);
			this->richTextBox2->Name = L"richTextBox2";
			this->richTextBox2->ScrollBars = System::Windows::Forms::RichTextBoxScrollBars::Vertical;
			this->richTextBox2->Size = System::Drawing::Size(246, 467);
			this->richTextBox2->TabIndex = 2;
			this->richTextBox2->Text = L"";
			// 
			// 클러스터링
			// 
			this->클러스터링->Location = System::Drawing::Point(264, 251);
			this->클러스터링->Name = L"클러스터링";
			this->클러스터링->Size = System::Drawing::Size(90, 78);
			this->클러스터링->TabIndex = 3;
			this->클러스터링->Text = L"클러스터링";
			this->클러스터링->UseVisualStyleBackColor = true;
			this->클러스터링->Click += gcnew System::EventHandler(this, &Form1::클러스터링_Click);
			// 
			// chart1
			// 
			chartArea1->AxisX->Maximum = 30;
			chartArea1->AxisX->Minimum = 0;
			chartArea1->AxisY->Maximum = 30;
			chartArea1->AxisY->Minimum = 0;
			chartArea1->Name = L"ChartArea1";
			this->chart1->ChartAreas->Add(chartArea1);
			legend1->Name = L"Legend1";
			this->chart1->Legends->Add(legend1);
			this->chart1->Location = System::Drawing::Point(644, 114);
			this->chart1->Name = L"chart1";
			series1->ChartArea = L"ChartArea1";
			series1->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Point;
			series1->Legend = L"Legend1";
			series1->Name = L"group0";
			series2->ChartArea = L"ChartArea1";
			series2->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Point;
			series2->Legend = L"Legend1";
			series2->Name = L"group1";
			series3->ChartArea = L"ChartArea1";
			series3->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Point;
			series3->Legend = L"Legend1";
			series3->Name = L"group2";
			this->chart1->Series->Add(series1);
			this->chart1->Series->Add(series2);
			this->chart1->Series->Add(series3);
			this->chart1->Size = System::Drawing::Size(288, 303);
			this->chart1->TabIndex = 4;
			this->chart1->Text = L"chart1";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(946, 532);
			this->Controls->Add(this->chart1);
			this->Controls->Add(this->클러스터링);
			this->Controls->Add(this->richTextBox2);
			this->Controls->Add(this->richTextBox1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
//
	private: System::Void 열기_Click(System::Object^ sender, System::EventArgs^ e) {

		richTextBox1->Clear();

		int d;
		ifstream indata;
		indata.open("data.txt");

		for (int i = 0; i < num_data; i++) {
			for (int j = 0; j < 2; j++) {
				indata >> d;
				::data[i][j] = d;

				richTextBox1->Text += (Convert::ToString(::data[i][j]) + " " );
			}
			richTextBox1->Text += "\r\n";
		}

		kmeans();

		indata.close();

	}
//
	void kmeans() {
		double** means = new double* [k];

		for (int i = 0; i < k; i++)
			means[i] = new double[2];

		////  임의의 평균값 설정  ////
		for (int i = 0; i < k; i++)
			for (int j = 0; j < 2; j++)
				means[i][j] = ::data[i + 4][j];


		////  평균 계산  ////
		for (;;) {
			int flag = 0;

			for (int i = 0; i < num_data; i++) {
				double min_dis = 9999;
				int min = -1;

				// 거리 계산 //
				for (int j = 0; j < k; j++) {
					double dis = 0;
					for (int l = 0; l < 2; l++)
						dis += pow(float(::data[i][l] - means[j][l]), 2); // data 에서 means를 뺀 값의 제곱//
					if (dis < min_dis) {
						min_dis = dis;
						min = j;
					}
				}

				// 그룹 설정 //
				group[i] = min;
			}

			// 계산을 위한 메모리 할당 //
			double** temp = new double* [k];
			int* count = new int[k];

			for (int i = 0; i < k; i++) {
				count[i] = 0;
				temp[i] = new double[2];
				for (int j = 0; j < 2; j++)
					temp[i][j] = 0;
			}

			// 새로운 평균 계산 //
			for (int i = 0; i < num_data; i++) {
				count[group[i]]++;
				for (int j = 0; j < 2; j++)
					temp[group[i]][j] += ::data[i][j];
			}

			for (int i = 0; i < k; i++)
				for (int j = 0; j < 2; j++) {
					temp[i][j] /= count[i];
					if (fabs(temp[i][j] - means[i][j]) > 0.0001) {
						flag++;
						means[i][j] = temp[i][j];
					}
				}

			// break point //
			if (flag == 0)
				break;
		}

		////  freeing memory  ////
		for (int i = 0; i < k; i++)
			delete means[i];
		delete means;
	}

	private: System::Void 클러스터링_Click(System::Object^ sender, System::EventArgs^ e) {

		richTextBox2->Clear();
		//////  display function  //////
		for (int i = 0; i < num_data; i++) {
			richTextBox2->Text += "data" + (i + 1) + " : ";
			for (int j = 0; j < 2; j++)
				richTextBox2->Text += ::data[i][j] + " ";
			richTextBox2->Text += "	\tgroup : " + group[i] + "\r\n";

			this->chart1->Series["group" + group[i]]->Points->AddXY(::data[i][0], ::data[i][1]);
		}
	}
};
}

