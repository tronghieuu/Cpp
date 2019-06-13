#ifndef VIRUS_H
#define VIRUS_H
#include <list>
using namespace std;
class Virus
{
protected:
	char *m_dna;
	int m_resistance;
public:
	Virus();
	virtual ~Virus();
	Virus(const Virus* v);
	void LoadADNInformation();
	void ReduceResistance(int medicine_resistance);
	virtual void DoBorn() = 0;
	virtual list<Virus> DoClone() = 0;
	virtual void DoDie() = 0;
	virtual void InitResistance() = 0;
};
#endif