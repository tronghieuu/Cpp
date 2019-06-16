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
	void DoStart();                              //Init m_virusList
	void InitResistance();                       //Init patient resistance
	void DoDie();                                //Destroy Patient object
public:
	Patient();                                   //Constructor
	~Patient();                                  //Destructor
	void TakeMedicine(int medicine_resistance);  //Reduce virus resistance, destroy or clone them depend on their resistance 
	int GetState();                              //Return status of patient (dead or alive)
	void Display();                              //Show list viruses are alive currently
	int GetVirusesResistance();                  //Return sum of all viruses in current m_virusList
	int GetResistance();                         //Return patient's resistance
};
#endif
