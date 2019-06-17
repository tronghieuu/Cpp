#include "Patient.h"
#include "FluVirus.h"
#include "DengueVirus.h"
#include <stdlib.h>
#include <time.h>
#include <iostream>
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
	virusnum = rand() % 11 + 10;
	for (int i = 0; i < virusnum; i++)
	{
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
	// Remove viruses are dead from m_virusList
	list<Virus*>::iterator i = m_virusList.begin();
	while (i != m_virusList.end())
	{
		(*i)->ReduceResistance(medicine_resistance);
		if ((*i)->Getm_resistance() <= 0)
		{
			delete (*i);
			i = m_virusList.erase(i);
		}
		else
		{
			i++;
		}
	}
	//get last element in m_virusList and clone all viruses are alive from last to begin
	if (m_virusList.begin() != m_virusList.end())
	{
		list<Virus*>::iterator temp, lastelement = --m_virusList.end();
		for (i = lastelement; i != m_virusList.begin();)
		{
			temp = i--;
			m_virusList.splice(m_virusList.end(), (*temp)->DoClone());
		}
		m_virusList.splice(m_virusList.end(), (*i)->DoClone());
	}
	if (m_resistance < GetVirusesResistance())
	{
		m_state = 0;
	}
}

void Patient::DoDie()
{
	for (list<Virus*>::iterator i = m_virusList.begin(); i != m_virusList.end(); i++)
	{
		delete (*i);
	}
	m_virusList.clear();
	m_state = 0;
}

int Patient::GetState()
{
	return m_state;
}

void Patient::Display()
{
	int count = 1;
	cout << "\n       -------VIRUSES LIST-------\n";
	for (list<Virus*>::iterator i = m_virusList.begin(); i != m_virusList.end(); i++)
	{
		cout << "       " << count << ". ";
		(*i)->Display();
		cout << "\n";
		count++;
	}
	cout << "       STATUS--------------------";
	cout << "\n       Body Resistance: " << GetResistance();
	cout << "\n       Viruses Resistance: " << GetVirusesResistance() << "\n";
}

int Patient::GetVirusesResistance()
{
	int virusresistance = 0;
	for (list<Virus*>::iterator i = m_virusList.begin(); i != m_virusList.end(); i++)
	{
		virusresistance += (*i)->Getm_resistance();
	}
	return virusresistance;
}

int Patient::GetResistance()
{
	return m_resistance;
}