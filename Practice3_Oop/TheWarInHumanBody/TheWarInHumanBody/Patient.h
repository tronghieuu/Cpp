#ifndef PATIENT_H
#define PATIENT_H
#include "Virus.h"
#include <list>
using namespace std;
class Patient
{
private:
	int m_resistance;
	list<Virus*> m_virusList;
	int m_state;
private:
	void DoStart();
	void InitResistance();
	void DoDie();
public:
	Patient();
	~Patient();
	void TakeMedicine(int medicine_resistance);
	int GetState();
	void Display();
	int GetVirusesResistance();
	int GetResistance();
};
#endif
