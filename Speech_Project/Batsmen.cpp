#include "Batsmen.h"

#include "Cricket_country.h"
#//include "Football_country.h"
#include "dirent.h"
#include "Test_train.h"
#include "Sports.h"
#include "HMM.h"
#include<iostream>
#include<cstring>
#include<cstdlib>
#include "India.h"
#include "Virat.h"
#include "Warner.h"
using namespace std;

int CLRproj1::Batsmen ::count_files(string directory) {
	int levelsize;
	struct dirent* de;  // Pointer for directory entry 

	// opendir() returns a pointer of DIR type.
	char* cstr = new char[directory.length() + 1];
	std::strcpy(cstr, directory.c_str());
	DIR* dr = opendir(cstr);

	if (dr == NULL)  // opendir returns NULL if couldn't open directory 
	{
		printf("Could not open current directory");
		return 0;
	}

	while ((de = readdir(dr)) != NULL) {
		levelsize++;
		printf("%s\n", de->d_name);

	}

	closedir(dr);
	return levelsize;
}

void CLRproj1::Batsmen::speak(string str)
{
	if (str == "India") {
		while (1) {
			label1->Text = L"List of INDIA Batsmen";
			label2->Text = L"Virat";
			label3->Text = L"Dhoni";
			label4->Text = L"Rohit";
			label5->Text = L"Shikhar";

			this->Show();
			this->Refresh();
			System::Threading::Thread::Sleep(4000);
			//system("PAUSE");
			label7->Text = "Speak NOW . . .";
			this->Hide();
			this->Show();
			this->Refresh();
			//int levelsize = count_files("Sports") - 2;
			int levelsize = 5;
			cout << levelsize << endl;
			//insert recording module here 
			system("Record_Module\\Recording_Module.exe 4 Record_Module\\Voice\\test.wav Record_Module\\Voice\\test.txt");

			CLRproj1::HMM hmm;

			/*int index = hmm.start("Record_Module\\Voice\\test.txt", "Sports\\Cricket\\India\\Batsmen\\Modelpara\\finalA.txt",
				"Sports\\Cricket\\India\\Batsmen\Modelpara\\finalB.txt", "Sports\\Cricket\\India\\Batsmen\Modelpara\\finalPI.txt",
				"Sports\\Cricket\\India\\Batsmen\Modelpara\\codebook.txt", levelsize);*/
			int index = 0;
			if (index == -1) {
				this->label7->Text = L"We didn't recognize what you said. Wait for 4 seconds to speak again";
				this->Hide();
				this->Show();
				this->Refresh();
				continue;
			}
			else if (index == 0) {
				//Virat
				this->label5->Text = L"Please Wait . . .";
				this->Refresh();
				this->Close();
				CLRproj1::Virat vi;
				vi.Show();
				vi.Refresh();
				system("PAUSE");

			}
			else if (index == 1) {
				//Dhoni
			}
			else if (index == 2) {
				//Rohit
			}
			else if (index == 3) {
				//Shikhar
			}
			else {
				//Back

			}
		}
	}
	else {
		while (1) {
			label1->Text = L"List of Australia Batsmen";
			label2->Text = L"Warner";
			label3->Text = L"Smith";
			label4->Text = L"Finch";
			label5->Text = L"Marsh";

			this->Show();
			this->Refresh();
			System::Threading::Thread::Sleep(4000);
			//system("PAUSE");
			label7->Text = "Speak NOW . . .";
			this->Hide();
			this->Show();
			this->Refresh();
			//int levelsize = count_files("Sports") - 2;
			int levelsize = 5;
			cout << levelsize << endl;
			//insert recording module here 
			system("Record_Module\\Recording_Module.exe 4 Record_Module\\Voice\\test.wav Record_Module\\Voice\\test.txt");

			CLRproj1::HMM hmm;

			/*int index = hmm.start("Record_Module\\Voice\\test.txt", "Sports\\Cricket\\India\\Batsmen\\Modelpara\\finalA.txt",
				"Sports\\Cricket\\India\\Batsmen\Modelpara\\finalB.txt", "Sports\\Cricket\\India\\Batsmen\Modelpara\\finalPI.txt",
				"Sports\\Cricket\\India\\Batsmen\Modelpara\\codebook.txt", levelsize);*/
			int index = 0;

			if (index == -1) {
				this->label7->Text = L"We didn't recognize what you said. Wait for 4 seconds to speak again";
				this->Hide();
				this->Show();
				this->Refresh();
				continue;
			}
			else if (index == 0) {
				//Warner
				this->label5->Text = L"Please Wait . . .";
				this->Refresh();
				this->Close();
				CLRproj1::Warner wa;
				wa.Show();
				wa.Refresh();
				system("PAUSE");



			}
			else if (index == 1) {
				//Smith
			}
			else if (index == 2) {
				//Finch
			}
			else if (index == 3) {
				//Marsh
			}
			else {
				//Back
			}
		}

	}
	system("PAUSE");

}