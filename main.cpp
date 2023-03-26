#include "customer.h"
#include "qeue.h"
#include "mechanic.h"
#include "workshop.h"
#include <fstream>

using namespace std;


int main() {
	//a normal main
	
	workshop test;// create object test of class workshop

	ifstream mech;
	mech.open("mechanics.txt");
	//will input the mechanics from file mechanics/ bonus question
	//the file is shown in the word document
	int s = 0;
	while (!(mech.eof()) && (s < test.getsizem())) {
		string name;
		string id;
		int age;

		mech >> name;
		mech >> age;
		mech >> id;
		//will input the data one by one

		mechanic x(name, id, age);
		//will create a mechanic object with the data in each line

		test.setmechanic(s, x);//will put the mechanic in the array of mechanics in object test

		s++;//used as index for setmechanic and also to make sure we didnt exceed 3
	}


	mech.close();

	ifstream cus;
	cus.open("customers.txt");
	//now we will input the customers
	//file in word document too 

	int c = 0;

	while (!(cus.eof())&&c<test.getsizec()) {
		string name;
		string id;
		int age;
		appointment app;
	

		cus >> name;
		cus >> age;
		cus >> id;
		cus >> app.hour;
		cus >> app.minute;
	    //will input the cystomers data one by one
		

		customer z(name, id, age, app);
		//we then create an object of customer called z


		if (test.assign(z))c++;
		//we then put z in the assign function 
		//it will check if z has a place then it will assign it an add to the array of assigned customers if it has a place
		//if it returned true meaning that it was assigned then c will be incremented
		//c will is used above in the while to make sure we dont assign more ustomers than acceptable

		
	}



	test.sortcustomers();//we then sort the assigned array of customers

	qeue<customer> store(test.getcounter());
	//create a qeue of type customer

	for (int i = 0; i < test.getcounter(); i++) {
		store.push(test.getcustomer(i));
		//we push each customer from the sorted array to the qeue
	}
	
	for (int i = 0; i < test.getcounter(); i++) {
		customer t;
		store.pop(t);
		//we then pop each customer by order first in first out

		cout << t.getname() << " should be assigned to ";
		for (int i = 0; i < test.getsizem(); i++) {
			if (t.getMid() == test.getmechanic(i).getid()) {
				cout << test.getmechanic(i).getname() << " at " << t.getapp().hour<<":"<<t.getapp().minute << endl;
			}
		}
		//the above for loop is used to get the mechanic with the mehcanicid that the customer has to print them together 

	}
	
	return 0;
}