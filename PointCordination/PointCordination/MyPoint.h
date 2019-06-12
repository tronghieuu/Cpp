#ifndef MYPOINT_H
#define MYPOINT_H
class MyPoint
{
private:
	int mPosX = 0;
	int mPosY = 0;

	void Display();
	void SetX(int);
	int GetX();
	void SetY(int);
	int GetY();
	float Distance(MyPoint p);

public:
	MyPoint();
	MyPoint(int, int);
	~MyPoint();
};
#endif