#ifndef FLUVIRUS_H
#define FLUVIRUS_H
#include "Virus.h"
class FluVirus :public Virus
{
private:
	int m_color;
private:
	void DoBorn();                    //Call LoadADNInformantion() from base class (Virus class), init m_color
	void DoDie();                     //Destroy FluVirus object
	void InitResistance();            //Init Flu virus's resistance
public:
	FluVirus();                       //Constructor
	~FluVirus();                      //Destructor
	FluVirus(const FluVirus* fv);     //Copy constructor
	list<Virus*> DoClone();           //Return a list cloned viruses
	void Display();                   //Show status of Flu virus (name, color, resistance)
	int GetColor();                   //Just in case anyone want to get color's value of Flu virus
};
#endif
