#include "FluVirus.h"
#include <time.h>
#include <stdlib.h>

FluVirus::FluVirus()
{
	DoBorn();
}

FluVirus::~FluVirus()
{

}

FluVirus::FluVirus(const Virus* v)
{

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

Virus * FluVirus::DoClone()
{
	return nullptr;
}

void FluVirus::DoDie()
{

}

void FluVirus::InitResistance()
{

}



