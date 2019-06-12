#include "MyPoint.h"
#include <math.h>
#include <iostream>
using namespace std;

MyPoint::MyPoint() {}

MyPoint::MyPoint(int x, int y)
{
	this->mPosX = x;
	this->mPosY = y;
}

MyPoint::~MyPoint() {}

void MyPoint::Display()
{
	cout << "X position: " << mPosX;
	cout << "\nY position: " << mPosY << "\n";
}

void MyPoint::SetX(int x)
{
	mPosX = x;
}

int MyPoint::GetX()
{
	return mPosX;
}

void MyPoint::SetY(int y)
{
	mPosY = y;
}

int MyPoint::GetY()
{
	return mPosY;
}

double MyPoint::Distance(MyPoint p)
{
	return sqrt(pow(mPosX - p.mPosX, 2) + pow(mPosY - p.mPosY, 2));
}