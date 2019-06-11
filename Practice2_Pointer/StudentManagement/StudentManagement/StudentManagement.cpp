#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

struct student
{
	int id;
	string name;
	float score;
};

short choice;
student *list = new student[1];
int length = 0;

void Extend(int size);         //Extend size of student array
void Add(student s);           //Add a student object into student array list
bool CheckID(int id);          //Check student id whether be duplicated or not
void Input();                  //Input student information and add to array
void Display();                //Show list student in list array 
void FreeMemory();             //Release Memory has been allocated for list array
void LoadFile(string filename);//Load specify file with file name
void LoadFromFile();           //Handling Load from file function in Menu
void SaveFile(string filename);//Save into specify file with file name
void SaveToFile();             //Handling Save to file function in Menu
void Menu();                   //List funcitons that program provides

void Extend(int size)
{
	student *temp = new student[length + 1 + size];
	for (int i = 0; i < length; i++)
		temp[i] = list[i];
	delete[] list;
	list = temp;
}

void Add(student s)
{
	list[length] = s;
	length++;
	Extend(1);
}

bool CheckID(int id)
{
	for (int i = 0; i < length; i++)
		if (list[i].id == id)
			return false;
	return true;
}

void Input()
{
	system("cls");
	student s;
	cout << "Input ID: ";
	cin >> s.id;
	while (!CheckID(s.id))
	{
		cout << "Detected duplicated student ID, please input again: ";
		cin >> s.id;
	}
	cin.ignore();
	cout << "Input name: ";
	getline(cin, s.name);
	cout << "Input score: ";
	cin >> s.score;
	while (s.score < 0 || s.score > 10)
	{
		cout << "Score is out of range, please input again: ";
		cin >> s.score;
	}
	Add(s);
}

void Display()
{
	system("cls");
	cout << setw(4) << "ID";
	cout << setw(30) << "FULLNAME";
	cout << setw(16) << "SCORE\n";
	for (int i = 0; i < length; i++)
	{
		cout << setw(4) << list[i].id;
		cout << setw(30) << list[i].name;
		cout << setw(15) << list[i].score;
		cout << "\n";
	}
}

void FreeMemory()
{
	delete[] list;
	list = NULL;
}

void LoadFile(string filename)
{
	ifstream readingfile;
	readingfile.open(filename);
	if (readingfile.is_open())
	{
		readingfile >> length;
		FreeMemory();
		list = new student[length + 1];
		for (int i = 0; i < length; i++)
		{
			readingfile >> list[i].id;
			readingfile.ignore();
			getline(readingfile, list[i].name);
			readingfile >> list[i].score;
		}
		Display();
		readingfile.close();
	}
	else
	{
		system("cls");
		cout << "Could not open file!\n";
	}
	system("pause");
}

void LoadFromFile()
{
	short choice;
	cout << "------------------------------------------------------\n";
	cout << "        1. Load file template.txt";
	cout << "\n        2. Load other file";
	cout << "\n        Others to Exit";
	cout << "\nChoose: ";
	cin >> choice;
	switch (choice)
	{
	case 1:
		LoadFile("template.txt");
		break;
	case 2:
		system("cls");
		string filename;
		cout << "Enter your file name: ";
		cin >> filename;
		LoadFile(filename);
	}
}

void SaveFile(string filename)
{
	ofstream savingfile;
	savingfile.open(filename);
	if (savingfile.is_open())
	{
		savingfile << to_string(length) << "\n";
		for (int i = 0; i < length; i++)
		{
			savingfile << to_string(list[i].id) << "\n";
			savingfile << list[i].name << "\n";
			savingfile << to_string(list[i].score) << "\n";
		}
		savingfile.close();
		cout << "The data has been saved!";
	}
	else cout << "Could not open file!";
	cout << "\n";
	system("pause");
}

void SaveToFile()
{
	short choice;
	cout << "------------------------------------------------------\n";
	cout << "        1. Save into file template.txt";
	cout << "\n        2. Save as new file";
	cout << "\n        Others to Exit";
	cout << "\nChoose: ";
	cin >> choice;
	switch (choice)
	{
	case 1:
		system("cls");
		SaveFile("template.txt");
		break;
	case 2:
		system("cls");
		string filename;
		cout << "Enter your file name: ";
		cin >> filename;
		SaveFile(filename);
	}
}

void Menu()
{
	system("cls");
	cout << "-------------------------MENU-------------------------";
	cout << "\n        1. Input";
	cout << "\n        2. Display";
	cout << "\n        3. Save to file";
	cout << "\n        4. Load from file";
	cout << "\n        0. Exit";
	cout << "\n------------------------------------------------------\n";
	cout << "Choose: ";
	cin >> choice;
	switch (choice)
	{
	case 1:
		Input();
		break;
	case 2:
		Display();
		system("pause");
		break;
	case 3:
		SaveToFile();
		break;
	case 4:
		LoadFromFile();
		break;
	case 0:
		FreeMemory();
	}
}

void main()
{
	do
	{
		Menu();
		system("cls");
	} while (choice != 0);
}