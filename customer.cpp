#include "customer.h"
#include<iostream>


using namespace std;




void customer::setapp(int h, int m) {
	app.hour = h;
	app.minute = m;
}

appointment customer::getapp() {

	return app;
}


void customer::setMid(string h) {
	mechanicalid = h;
}

string customer::getMid() {
	return mechanicalid;
}

//above are just the implementation for the setters and getters


void customer::printf() {
	cout << "name: " << name << endl;
	cout << "id: " << id << endl;
	cout << "age: " << age << endl;
	cout << "mechanical id: " << mechanicalid << endl;
	cout << "time of appointment: " << app.hour << ":" << app.minute << endl;
}
//i over rided the print function to print the customers information




bool customer::operator == (customer u){
	if ((this->getapp().hour == u.getapp().hour)&&(this->getapp().minute == u.getapp().minute)){
		return true;
	}
	else return false;
}




bool customer::operator > (customer u) {
	bool res = false;
	if (this->getapp().hour > u.getapp().hour) {
		res = true;
	}
	else if ((this->getapp().hour == u.getapp().hour) && (this->getapp().minute > u.getapp().minute)) {
		res = true;
	}

	return res;
}



bool customer::operator < (customer u) {
	bool res = false;
	if (this->getapp().hour < u.getapp().hour) {
		res = true;
	}
	else if ((this->getapp().hour == u.getapp().hour) && (this->getapp().minute < u.getapp().minute)) {
		res = true;
	}

	return res;
}
//the above three functions are to compare between customer's appointments it will be used it sorting




customer::customer()
	:person() {
	mechanicalid = "";
}

customer::customer(string n, string i,int s,  string m, appointment ap)
	:person(n, i,s) {
	mechanicalid = m;
	app = ap;
}




customer::customer(string n, string i, int s, appointment ap)//this will be the main one used because usually we will know the mechanical id after we assign the customer to his mechanic
	:person(n, i, s) {
	app = ap;
}


//above three are constructors 






