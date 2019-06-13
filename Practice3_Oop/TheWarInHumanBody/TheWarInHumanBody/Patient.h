#ifndef PATIENT_H
#define PATIENT_H
#include <list>
#include "Virus.h"
using namespace std;

class Patient
{
private:
	int m_resistance;
	list<Virus*> m_virusList;
	int m_state;
public:
	Patient();
	~Patient();
	void InitResistance();
	void DoStart();
	void TakeMedicine();
	void DoDie();
	int GetState();
};
#endif
