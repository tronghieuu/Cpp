#include "DengueVirus.h"
#include <stdlib.h>
#include <cstring>
#include <iostream>
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
	m_resistance = dv->m_resistance;
	CopyDNA(dv->m_dna, Length(dv->m_dna));
	strcpy_s(m_protein, dv->m_protein);
}

void DengueVirus::DoBorn()
{
	LoadADNInformation();
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
	//nothing to delete
}

void DengueVirus::InitResistance()
{
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

void DengueVirus::Display()
{
	cout << "Dengue virus (" << m_protein << "), resistance: " << m_resistance;
}

string DengueVirus::GetProtein()
{
	return m_protein;
}

