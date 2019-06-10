#include <iostream>
#include <string>
using namespace std;
short choice;

struct student
{
	int id;
	string name;
	float score;
};

void Menu()
{
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
		break;
	case 2:
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
}