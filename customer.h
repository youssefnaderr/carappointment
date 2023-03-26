#pragma once
#include "person.h"

class customer : public person
{
protected:
	string mechanicalid;
	appointment app;
	// the mechanic id and appointment for the customer



public:

	customer();
	customer(string, string,int , string,appointment); //constructor 
	customer(string, string, int, appointment);// constructor that will not put the mechanical id



	void setapp(int, int);
	appointment getapp();
	// setters and getters for appointment

	void setMid(string);
	string getMid();
	//setters and getters for mechanical id

	void printf();

	

	bool operator == (customer );

	bool operator >(customer );

	bool operator <(customer );
	//i over loaded the operators to help me while sorting
};

