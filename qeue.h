#pragma once
using namespace std;

/*
this is a normal qeue template class implementation 
i think it doesnt need and explination*/

template<class t>
class qeue
{
private:
	int front;
	int rear;
	int counter;
	int maxSize;
	t* values;


public:
	qeue() {
		values = new t[10];
		maxSize = 10;
		counter = 0;
	}


	qeue(int n) {
		values = new t[n];
		maxSize = n;
		counter = 0;
	}


	bool IsEmpty() {
		if (counter!=0)	return false;
		else			return true;
	}


	bool IsFull() {
		if (counter < maxSize)	return false;
		else				return true;
	}


	bool push(t x) {
		if (IsFull()) {
			cout << "Error: the queue is full." << endl;
			return false;
		}
		else {

			rear = (rear + 1) % maxSize;

			values[rear] = x;

			counter++;
			return true;
		}
	}




		bool pop(t& x) {
		if (IsEmpty()) {
			cout << "Error: the queue is empty." << endl;
			return false;
		}
		else {

			x = values[front];

			front = (front + 1) % maxSize;

			counter--;
			return true;
		}
	}









};

