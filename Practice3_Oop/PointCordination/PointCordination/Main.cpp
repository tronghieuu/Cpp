#include "MyPoint.h"
#include <iostream>
using namespace std;

int ax, ay, bx, by;
MyPoint *p1, *p2;

void Input()
{
	cout << "Initialize point A.\n";
	cout << "Input X position: ";
	cin >> ax;
	cout << "Input Y position: ";
	cin >> ay;
	cout << "**************************\n";
	cout << "Initialize point B.\n";
	cout << "Input X position: ";
	cin >> bx;
	cout << "Input Y position: ";
	cin >> by;
	p1 = new MyPoint(ax, ay);
	p2 = new MyPoint();
	p2->SetX(bx);
	p2->SetY(by);
}

void main()
{
	Input();
	system("cls");
	cout << "Point A\n";
	p1->Display();
	cout << "**************************\n";
	cout << "Point B\n";
	p2->Display();
	cout << "**************************\n";
	cout << "Distance between A & B: " << p1->Distance(*p2) << "\n";
	delete p1, p2;
	system("pause");
}