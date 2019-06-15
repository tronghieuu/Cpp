#include "Patient.h"
#include <iostream>
void main()
{
	int choice, min = 1, max = 60, medicine_resistance;
	cout << "\n-------THE WAR BETWEEN VIRUSES ARMY AND THE MEDICINE IN HUMAN'S BODY!-------";
	cout << "\n----------------------------------------------------------------------------";
	Patient *p = new Patient();
	while (p->GetState() == 1)
	{
		cout << "\n-------1. Take Medicine";
		cout << "\n-------2. Display viruses list and their resistance";
		cout << "\n----------------------------------------------------------------------------";
		cout << "\n  Choose: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			medicine_resistance = min + (rand() % (int)(max - min + 1));
			p->TakeMedicine(medicine_resistance);
			break;
		case 2:
			system("cls");
			p->Display();
			system("pause");
			system("cls");
			break;
		default:;
		}
	}
	system("pause");
}