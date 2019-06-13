#include "Patient.h"
#include <stdlib.h>
#include <time.h>
#include "FluVirus.h"
#include "DengueVirus.h"

Patient::Patient()
{
	InitResistance();
	DoStart();
}

Patient::~Patient()
{
	DoDie();
}

void Patient::InitResistance()
{
	srand(time(NULL));
	m_resistance = rand() % 8001 + 1000;
}

void Patient::DoStart()
{
	int virusnum, virustype;
	srand(time(NULL));
	virusnum = rand() % 11 + 10;
	for (int i = 0; i < virusnum; i++)
	{
		srand(time(NULL));
		virustype = rand() % 2;
		if (virustype == 1)
		{
			Virus *v = new FluVirus();
			m_virusList.push_back(v);
		}
		else
		{
			Virus *v = new DengueVirus();
			m_virusList.push_back(v);
		}
	}
}

void Patient::TakeMedicine()
{

}

void Patient::DoDie()
{
	delete this;
}

int Patient::GetState()
{
	return m_state;
}