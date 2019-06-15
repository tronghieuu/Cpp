#ifndef FLUVIRUS_H
#define FLUVIRUS_H
#include "Virus.h"
class FluVirus :public Virus
{
private:
	int m_color;
private:
	void DoBorn();
	void DoDie();
	void InitResistance();
public:
	FluVirus();
	~FluVirus();
	FluVirus(const FluVirus* fv);
	list<Virus*> DoClone();
};
#endif
