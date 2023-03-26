#include <iostream>
using namespace std;

#pragma once

struct appointment {
	int hour;
	int minute;
};
//struct for appointment



class person
{
protected:

	string name;
	string id;
	int age;
	//info for the person


public:

	person();
	person(string, string, int);
	//constructors


	void setname(string);
	string getname();
	//set and get for name


	void setid(string);
	string getid();
	//set and get for id

	void setage(int);
	int getage();
	//set and get for age

	virtual void printf() = 0;
	//a pure virtual function to print 
	//abstract class


};
