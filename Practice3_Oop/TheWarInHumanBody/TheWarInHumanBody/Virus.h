#ifndef VIRUS_H
#define VIRUS_H
#include <list>
using namespace std;
class Virus
{
protected:
	char *m_dna;
	int m_resistance;
protected:
	virtual void DoBorn() = 0;
	virtual void InitResistance() = 0;
	virtual void DoDie() = 0;
	int Length(char* c);
	void CopyDNA(char* c, int length);
public:
	Virus();
	virtual ~Virus();
	Virus(const Virus* v);
	void LoadADNInformation();
	void ReduceResistance(int medicine_resistance);
	virtual list<Virus*> DoClone() = 0;
};
#endif