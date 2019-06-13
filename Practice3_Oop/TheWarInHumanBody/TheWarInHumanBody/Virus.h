#ifndef VIRUS_H
#define VIRUS_H
#include <list>
#include "Patient.h"
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
	virtual list<Virus*> DoClone() = 0;
	virtual void DoDie() = 0;
	virtual void InitResistance() = 0;
	int Length(char* c);
	void CopyDNA(char* c, int length);
	friend class Patient;
};
#endif