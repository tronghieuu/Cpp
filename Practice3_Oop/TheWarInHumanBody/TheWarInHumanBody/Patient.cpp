#include "Patient.h"
#include "FluVirus.h"
#include "DengueVirus.h"
#include <stdlib.h>
#include <time.h>

Patient::Patient()
{
	m_state = 1;
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

void Patient::TakeMedicine(int medicine_resistance)
{
	/*list<Virus*>::iterator begin = m_virusList.begin(), end = m_virusList.end();
	int virusresistance = 0;
	for (list<Virus*>::iterator i = begin; i != end; i++)
	{
		(*i)->ReduceResistance(medicine_resistance);
		if ((*i)->m_resistance <= 0)
		{
			delete (*i);
			m_virusList.remove(*i);
		}
		else
		{
			m_virusList.splice(m_virusList.end(), (*i)->DoClone());
		}
	}
	for (list<Virus*>::iterator i = m_virusList.begin(); i != m_virusList.end(); i++)
	{
		virusresistance += (*i)->m_resistance;
	}
	if (m_resistance < virusresistance)
	{
		m_state = 0;
	}*/
}

void Patient::DoDie()
{
	//delete this;
}

int Patient::GetState()
{
	return m_state;
}