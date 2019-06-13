#ifndef FLUVIRUS_H
#define FLUVIRUS_H
#include "Virus.h"
class FluVirus :public Virus
{
private:
	int m_color;
public:
	FluVirus();
	~FluVirus();
	FluVirus(const FluVirus* v);
	void DoBorn();
	Virus* DoClone();
	void DoDie();
	void InitResistance();
};
#endif
