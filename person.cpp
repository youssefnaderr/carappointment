#include "person.h"
#include "person.h"


person::person() {
	name = "";
	id = "";
	age = 0;

}



person::person(string n, string m, int r) {
	name = n;
	id = m;
	age = r;

}





void person::setname(string q) {
	name = q;
}

string person::getname() {
	return name;
}




void person::setid(string u) {
	id = u;
}

string person::getid() {
	return id;
}



void person::setage(int q) {
	age = q;
}

int person::getage() {
	return age;
}

// these are the implementations for the person.h functions i think all of them are clear