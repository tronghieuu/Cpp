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
	FluVirus(const FluVirus* fv);
	void DoBorn();
	list<Virus*> DoClone();
	void DoDie();
	void InitResistance();
};
#endif
