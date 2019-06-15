#ifndef DENGUEVIRUS_H
#define DENGUEVIRUS_H
#include "Virus.h"
class DengueVirus : public Virus
{
private:
	char m_protein[4];
private:
	void DoBorn();
	void DoDie();
	void InitResistance();
public:
	DengueVirus();
	~DengueVirus();
	DengueVirus(const DengueVirus* dv);
	list<Virus*> DoClone();
};
#endif
