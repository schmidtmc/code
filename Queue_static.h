/*
|	Author: Matthew Schmidt
|	Date: 2/16/2013
|	Program Identification: Static Queue header file
|	Abstract: This is the header file that contains the 
|	declaration of our class data members and methods.
*/


#pragma once
class Queue_static
{
private:
	int SIZE; // Size of array
	int *qArray;
	int frontPos;	// Holds location of front of queue.
	int backPos;	// Holds location of back of queue.
	int currentSize;	// This retains how many elements are in the queue.

public:
	// Class constructor
	Queue_static(int);
	// Class destructor
	~Queue_static(void);
	// Enqueue method. This passes an integer to the method, which then
	// places it at the end of the queue.
	void enqueue(int x);
	// Dequeue method. This removes the element in frontPos and returns
	// the int value.
	int dequeue();
	// listQueue method. This prints out the queue.
	void listQueue();
	// getFrontPos method. This is for testing purposes. It just displays
	// where the front of the queue is and returns an int of it.
	int getfrontPos();
	// getbackPos method. This is for testing purposes. It just displays
	// where the front of the queue is and returns an int of it.
	int getbackPos();
	// whereIsEveryone method is the method that calls both getfrontpos
	// method and the getbackpos method.
	void whereIsEveryone();
	// isFull method.  This checks to see if the array is full and returns
	// a bool value that is used to determine what to do.
	bool isFull();
	// isEmpty method.  This checks to see if the array is empty and returns
	// a bool value that is used to determine what to do.
	bool isEmpty();
};

