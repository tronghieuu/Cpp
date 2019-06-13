#include "Virus.h"
#include <fstream>
Virus::Virus()
{

}

Virus::~Virus()
{

}

Virus::Virus(const Virus *v)
{
	
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

