#include "FluVirus.h"
#include <time.h>
#include <stdlib.h>
#include <iostream>
FluVirus::FluVirus()
{
	DoBorn();
	InitResistance();
}

FluVirus::~FluVirus()
{
	DoDie();
}

FluVirus::FluVirus(const FluVirus* fv)
{
	m_resistance = fv->m_resistance;
	CopyDNA(fv->m_dna, Length(fv->m_dna));
	m_color = fv->m_color;
}

void FluVirus::DoBorn()
{
	LoadADNInformation();
	srand(time(NULL));
	int color = rand() % 2;
	if (color)
	{
		m_color = 0x0000ff;//blue
	}
	else
	{
		m_color = 0xff0000;//red
	}
}

list<Virus*> FluVirus::DoClone()
{
	list<Virus*> clonedlist;
	Virus *v = new FluVirus(this);
	clonedlist.push_back(v);
	return clonedlist;
}

void FluVirus::DoDie()
{
	//delete this;
}

void FluVirus::InitResistance()
{
	if (m_color == 0x0000ff)
	{
		m_resistance = rand() % 6 + 10;
	}
	else if (m_color == 0xff0000)
	{
		m_resistance = rand() % 11 + 10;
	}
}

void FluVirus::Display()
{
	cout << "Flu virus, resistance: " << m_resistance;
}



