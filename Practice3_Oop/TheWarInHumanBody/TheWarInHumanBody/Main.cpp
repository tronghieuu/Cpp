#include "Patient.h"
#include <iostream>
int choice, min = 1, max = 60, medicine_resistance;
Patient *p = new Patient();

void Interface()
{
	cout << "\n       Patient Resistance: " << p->GetResistance();
	cout << "\n       Viruses Resistance: " << p->GetVirusesResistance();
	cout << "\n       1. Take Medicine";
	cout << "\n       2. Display viruses list";
	cout << "\n----------------------------------------------------------------------------";
	cout << "\n  Choose: ";
	cin >> choice;
	switch (choice)
	{
	case 1:
		system("cls");
		medicine_resistance = min + (rand() % (int)(max - min + 1));
		cout << "\n       Medicine Resistance: " << medicine_resistance;
		cout << "\n--------------------------";
		cout << "\n       BEFORE";
		p->Display();
		p->TakeMedicine(medicine_resistance);
		cout << "--------------------------\n";
		cout << "       AFTER";
		p->Display();
		system("pause");
		system("cls");
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
void main()
{
	cout << "\n-------THE WAR BETWEEN VIRUSES ARMY AND THE MEDICINE IN HUMAN'S BODY!-------";
	cout << "\n----------------------------------------------------------------------------";
	do
	{
		if (p->GetVirusesResistance() == 0)
		{
			break;
		}
		Interface();
	} while (p->GetState() == 1);
	system("cls");
	if (p->GetState() == 0)
	{
		cout << "\n*************PATIENT'S DEAD!*************\n";
	}
	else
	{
		cout << "\n*************PATIENT HAS BEEN CURED SUCCESSFULLY!*************\n";
	}
	system("pause");
}