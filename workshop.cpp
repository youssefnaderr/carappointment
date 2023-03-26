#include "workshop.h"
#include "mechanic.h"
#include "customer.h"
#include <iostream>

using namespace std;

bool workshop::assign(customer cus) {
	bool flag = false;
	appointment time = cus.getapp();
	//function to assign customers to their mechanic
	//it will take the customer then go through the loop to check the available mechanics

	for (int i = 0; i < sizem; i++) {

		//i used m[(counter+i)%sizem] to assign first to first and second to second
		//otherwise most of them would have been assigned to the first mechanic
		if (m[(counter + i) % sizem].isavailable(time) && flag == false) {
			flag = true;//this flag is used so each customer only get assigned once


			cus.setMid(m[(counter + i) % sizem].getid());
			m[(counter + i) % sizem].setappoint(time);
			

			setcustomer(cus);

			//if theres an available appointment for the customer then the mechanic id in the customer will be assigned his mechanics id
			// the appointment will be put in the machanics array
			//and the customer's appointment will be put in the array of assigned customers in the workshop(through the setcustomer function)
			
		}

	}

	if (flag == false) {//this will be executed if no appointment is found
	cout << "there is no mechanic available at this time, your appointment is cancelled" << endl;
}
	return flag;// if it returned true then it was assigned if not then it wasnt 

}




void workshop::sortcustomers() {
	// a selection sort function to sort the array of assigned customers according to their appointment
	for (int j = 0; j < counter; j++) {
		customer min = c[j];
		int index = j;

		for (int i = j; i < counter; i++) {
			if (c[i] < min) { min = c[i]; index = i; }
		}
		customer box = c[j];
		c[j] = min;
		c[index] = box;


	}

}


int workshop::getcounter() {
	return counter;
}
//to get counter


workshop::workshop(int x) {
	sizem = x;
	sizec = x*24;// the maximum each mechanic can take is 24

	m = new mechanic[x];
	c = new customer[x*24];
}

workshop::workshop() {
	sizem = 3;
	sizec = sizem * 24;

	m = new mechanic[sizem];
	c = new customer[sizec];
}
//the above are two overloaded constructors


void workshop::setcustomer(customer x){
	c[counter] = x;
	counter++;
}//function to put a customer in the array of assigned customers
//it  puts the customer in the index of counter and increments the counter



customer workshop::getcustomer(int n) {
	return c[n];
}



void workshop::setmechanic(int n, mechanic x) {
	m[n] = x;
}



mechanic workshop::getmechanic(int n) {
	return m[n];
}

int workshop::getsizem() {
	return sizem;
}

int workshop::getsizec() {
	return sizec;
}

//above are all normal setters and getters

