#include "DengueVirus.h"

DengueVirus::DengueVirus()
{

}

DengueVirus::~DengueVirus()
{

}

DengueVirus::DengueVirus(const DengueVirus* dv)
{

}

void DengueVirus::DoBorn()
{

}

list<Virus*> DengueVirus::DoClone()
{
	list<Virus*> clonedlist;
	Virus *v1 = new DengueVirus(this);
	Virus *v2 = new DengueVirus(this);
	clonedlist.push_back(v1);
	clonedlist.push_back(v2);
	return clonedlist;
}

void DengueVirus::DoDie()
{

}

void DengueVirus::InitResistance()
{

}
