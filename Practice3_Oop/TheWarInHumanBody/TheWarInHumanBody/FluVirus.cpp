#include "FluVirus.h"
#include <time.h>
#include <stdlib.h>

FluVirus::FluVirus()
{
	DoBorn();
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
	int turn = rand() % 2;
	if (turn)
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
	delete this;
}

void FluVirus::InitResistance()
{

}



