#include "Virus.h"
#include <fstream>
Virus::Virus()
{

}

Virus::~Virus()
{

}

int Virus::Length(char *c)
{
	int count = 1;
	while (*c != '\0')
	{
		c++;
		count++;
	}
	return count;
}

void Virus::CopyDNA(char* c, int length)
{
	m_dna = new char[length];
	for (int i = 0; i < length - 1; i++)
	{
		m_dna[i] = c[i];
	}
	m_dna[length - 1] = '\0';
}

Virus::Virus(const Virus *v)
{
	m_resistance = v->m_resistance;
	CopyDNA(v->m_dna, Length(v->m_dna));
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

