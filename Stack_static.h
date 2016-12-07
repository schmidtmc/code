/*
|	Author: Matthew Schmidt
|	Date: 2/16/2013
|	Program Identification: Static stack header file
|	Abstract: This is the header file that contains the 
|	declaration of our class data members and methods.
*/

#pragma once

template <class T>
class Stack_static
{
private:
	int *sArray;	// The stack's array
	int SIZE;   // Set SIZE for the object so other functions know array size.
	int top;	// This holds how many elements are in the array.

public:
	// Class constructor
	Stack_static(int);
	// Class deconstructor
	~Stack_static(void);
	// Push method. This passes an integer to place
	// on top of the stack.
	void push(int x);
	// pop method. This returns a char of the 
	// value that the method removes from the stack.
	T pop();
	// listStack method.  This prints out the stack.
	void listStack();
	// isFull method.  This returns a bool value that
	// allows the program to determine if the stack is full.
	bool isFull();
	// isEmpty method.  This returns a bool value that
	// allows the program to determine if the stack is empty.
	bool isEmpty();
    // showTop method. This returns the value that is on top of the stack.
    T showTop();
	
};

