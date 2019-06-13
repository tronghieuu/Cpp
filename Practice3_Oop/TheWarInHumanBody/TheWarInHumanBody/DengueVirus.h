#ifndef DENGUEVIRUS_H
#define DENGUEVIRUS_H
#include "Virus.h"
class DengueVirus : public Virus
{
private:
	char m_protein[4];
public:
	DengueVirus();
	~DengueVirus();
	DengueVirus(const DengueVirus* dv);
	void DoBorn();
	list<Virus*> DoClone();
	void DoDie();
	void InitResistance();
};
#endif
