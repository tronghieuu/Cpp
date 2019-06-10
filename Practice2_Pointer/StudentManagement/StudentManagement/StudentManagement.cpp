#include <iostream>
#include <string>
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

void Extend(int i)
{
	student *temp = new student[length + 1 + i];
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
		break;
	case 4:
		break;
	case 0:
		break;
	default:
		break;
	}
}

void main()
{
	do
	{
		Menu();
		system("cls");
	} while (choice != 0);
	system("pause");
}