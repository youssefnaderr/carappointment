#pragma once
#include "person.h"
class mechanic : public person
{
protected:
	int counter;//number of appointments the mechanic have
	static const int maxim=24;//the maximum number of appointments for each mechanic is 24 slots as said in the document
	appointment* arr;// aggregation relation ship
	

public:

	mechanic();
	mechanic(string, string,int);
	//normal constructors 

	bool isavailable(appointment );
	//to check if controctor is available at that curtain appointment


	void setcounter(int);
	int getcounter();
	//setter and getter for count

	void printf();
	//over ridden the print function


	appointment getappoint(int);//will get the appointment at this curtain index int 
	void setappoint(appointment );
	//setters and getters for the appointment 
};

