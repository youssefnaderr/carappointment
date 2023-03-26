#include "mechanic.h"
using namespace std;

mechanic::mechanic()
	:person()//default constructor of person
{
	counter = 0;
	arr = new appointment[24];//will borrow from the heap, aggregation

}



mechanic::mechanic(string h, string j,int k) :person(h,j,k)
{
	counter = 0;
	arr = new appointment[24];
	
}




bool mechanic::isavailable(appointment r) {
	bool res = true;
	for (int i = 0; i < counter; i++) {
		if ((arr[i].hour == r.hour) && (arr[i].minute == r.minute)) {
			res = false;
			//this function willl compare the given appointment with the appointments in the mechanics array
			//to check if theres a match for not to see if he is available at this time 
		}
	}
	return res;
}




void mechanic::setcounter(int x) {
	counter = x;
}

int mechanic::getcounter() {
	return counter;
}

//setters and getters for counter 



appointment mechanic::getappoint(int c) {
	return arr[c];
}



void mechanic::setappoint(appointment q) {
	if (isavailable(q) && counter < maxim) {
		//will first check if hes available and if he didnt reach the maximum number of appointments which is 24
		counter++;
		//if not he will increment counter by one and add the new appointment to his array
		arr[counter] = q;
	}
}


void mechanic::printf() {
	cout << "name: " << name << endl;
	cout << "id: " << id << endl;
	cout << "age: " << age << endl;
}
//over ridden to print the mechanic's information
