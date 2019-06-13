#include "DengueVirus.h"
#include <stdlib.h>
#include <time.h>
#include <cstring>

DengueVirus::DengueVirus()
{
	DoBorn();
	InitResistance();
}

DengueVirus::~DengueVirus()
{
	DoDie();
}

DengueVirus::DengueVirus(const DengueVirus* dv)
{

}

void DengueVirus::DoBorn()
{
	LoadADNInformation();
	srand(time(NULL));
	int protein = rand() % 3;
	if (protein == 0)
	{
		strcpy_s(m_protein, "NS3");
	}
	else if (protein == 1)
	{
		strcpy_s(m_protein, "NS5");
	}
	else if (protein == 2)
	{
		strcpy_s(m_protein, "E");
	}
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
	delete this;
}

void DengueVirus::InitResistance()
{
	srand(time(NULL));
	if (strcmp(m_protein, "NS3") == 0)
	{
		m_resistance = rand() % 10 + 1;
	}
	else if (strcmp(m_protein, "NS5") == 0)
	{
		m_resistance = rand() % 10 + 11;
	}
	else if (strcmp(m_protein, "E") == 0)
	{
		m_resistance = rand() % 10 + 21;
	}
}
