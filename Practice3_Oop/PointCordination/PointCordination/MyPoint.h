#ifndef MYPOINT_H
#define MYPOINT_H
class MyPoint
{
private:
	int mPosX = 0;
	int mPosY = 0;

public:
	MyPoint();
	MyPoint(int, int);
	~MyPoint();
	void Display();
	void SetX(int);
	int GetX();
	void SetY(int);
	int GetY();
	double Distance(MyPoint p);
};
#endif