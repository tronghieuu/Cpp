#include "Virus.h"
#include <fstream>
Virus::Virus()
{

}

Virus::~Virus()
{

}

int Length(char *c)
{
	int count = 1;
	while (*c != '\0')
	{
		c++;
		count++;
	}
	return count;
}

Virus::Virus(const Virus *v)
{
	int length = Length(v->m_dna);
	m_resistance = v->m_resistance;
	m_dna = new char[length];
	for (int i = 0; i < length - 1; i++)
	{
		m_dna[i] = v->m_dna[i];
	}
	m_dna[length - 1] = '\0';
}

void Virus::LoadADNInformation()
{
	char temp;
	int count = 1;
	ifstream read("ATGX.bin");
	if (read.is_open())
	{
		while (read >> temp)
		{
			count++;
		}
		read.close();
	}
	m_dna = new char[count];
	read.open("ATGX.bin");
	if (read.is_open())
	{
		read.getline(m_dna, count);
		read.close();
	}
}

void Virus::ReduceResistance(int medicine_resistance)
{
	m_resistance -= medicine_resistance;
}

