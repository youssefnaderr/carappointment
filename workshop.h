#include "person.h"
#include "mechanic.h"
#include "customer.h"
#include <iostream>

using namespace std;


/*
i decided to create a class called workshop
it will contain an array of mechanics containing the mechanics in this workshop
it will also include an array of customers which are the customers who have been assigned an appointment with a certain mechanic
*/

#pragma once
class workshop
{
	



private:
	mechanic * m;
	customer* c;
	//pointer to array of mechanics and array of assigned customers
	//aggregation relationship
	int sizem;
	int sizec;
	//size of mechanics and size of customers

	int counter = 0;
	//this is a counter of how many assigned customers 


public:
	bool assign(customer);
	//function to assign a customer to a mechanic 

	workshop();
	workshop(int);
	//constructors
    
	customer getcustomer(int);
	void setcustomer(customer);
	//setters and getters for the customer

	void setmechanic(int, mechanic);
	mechanic getmechanic(int);
	//setters and getters for mechanic

	int getsizem();
	int getsizec();
	//getters for both sizes 

	void sortcustomers();
	//function to sort the array of the assigned customers 

	int getcounter();
	//getter for the counter 

};

