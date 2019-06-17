#ifndef DENGUEVIRUS_H
#define DENGUEVIRUS_H
#include "Virus.h"
class DengueVirus : public Virus
{
private:
	char m_protein[4];
private:
	void DoBorn();                       //Call LoadADNInformation() from base class (Virus class), init m_protein
	void DoDie();                        //Destroy DengueVirus object
	void InitResistance();               //Init Dengue virus's resistance
public:
	DengueVirus();                       //Constructor
	~DengueVirus();                      //Destructor
	DengueVirus(const DengueVirus* dv);  //Copy constructor
	list<Virus*> DoClone();              //Return list<Virus*> of cloned Dengue virus
	void Display();                      //Show status of Dengue virus (name , protein, resistance)
	string GetProtein();                 //Just in case anyone want to get protein's data of Dengue virus
};
#endif
