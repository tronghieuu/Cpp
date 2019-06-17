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
	virtual void DoBorn() = 0;                               //Need override in derived class
	virtual void InitResistance() = 0;                       //Need override in derived class
	virtual void DoDie() = 0;                                //Need override in derived class
	int Length(char* c);                                     //Return length of a char* array
	void CopyDNA(char* c, int length);                       //Copy a char* array to another
public:
	Virus();                                                 //Constructor
	virtual ~Virus();                                        //Destructor
	Virus(const Virus* v);                                   //Copy constructor
	void LoadADNInformation();                               //Load content in ATGX.bin file into m_dna
	virtual void ReduceResistance(int medicine_resistance);  //Reduce virus resistance depend on medicine resistance
	virtual list<Virus*> DoClone() = 0;                      //Need override in derived class
	virtual void Display() = 0;                              //Need override in derived class
	virtual int Getm_resistance();                           //Return virus resistance
	string GetDNA();                                         //Just in case anyone want to get dna's data of virus
};
#endif