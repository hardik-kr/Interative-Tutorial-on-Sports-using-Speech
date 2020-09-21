#include "dirent.h"
#include "Test_train.h"
#include "Sports.h"
#include "Training.h"
#include "HMM.h"
#include<iostream>
#include<cstring>
#include<cstdlib>

using namespace std;
int CLRproj1 :: Test_train :: count_files(string directory){
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
		//printf("%s\n", de->d_name);

	}

	closedir(dr);
	return levelsize;
}
void CLRproj1::Test_train::speak()
{
		
		while (1) {
			//label4->Text = "Speak NOW . . .";
			System::Threading::Thread::Sleep(4000);
			//system("PAUSE");
			label4->Text = L"Speak NOW . . .";
			this->Hide();
			this->Show();
			this->Refresh();
			//int levelsize = count_files("Home") - 3;
			int levelsize = 2;
			cout << levelsize << endl;
			//insert recording module here 
			system("Record_Module\\Recording_Module.exe 4 Record_Module\\Voice\\test.wav Record_Module\\Voice\\test.txt");

			CLRproj1::HMM hmm;

			int index = hmm.start("Record_Module\\Voice\\test.txt", "Home\\Modelpara\\finalA.txt",
				"Home\\Modelpara\\finalB.txt", "Home\\Modelpara\\finalPI.txt",
				"Home\\Modelpara\\codebook.txt", levelsize);
			//system("PAUSE");

			//if index == 0 then testing else training
			if (index == -1){
				this->label4->Text = L"We didn't recognize what you said. Wait for 4 seconds to speak again";
				this->Hide();
				this->Show();
				this->Refresh();
				continue;
			}
			else if (index == 0) {

				this->label4->Text = L"Please Wait . . .";
				this->Refresh();
				this->Close();

				CLRproj1::Sports sp;
				sp.Show();
				sp.Refresh();
				sp.speak();
				break;
			}
			else {
				CLRproj1::Training tr;
				tr.ShowDialog();
				break;
			}
		}
		//system("PAUSE");
		//System::Threading::Thread::Sleep(2500);

		

}
