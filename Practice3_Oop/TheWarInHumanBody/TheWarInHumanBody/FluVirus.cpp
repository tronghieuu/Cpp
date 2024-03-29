#include "FluVirus.h"
#include <stdlib.h>
#include <string>
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
	//nothing to delete
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
	string color;
	if (m_color == 0x0000ff)
	{
		color = "blue";
	}
	else
	{
		color = "red";
	}
	cout << "Flu virus (" << color << "), resistance: " << m_resistance;
}

int FluVirus::GetColor()
{
	return m_color;
}



