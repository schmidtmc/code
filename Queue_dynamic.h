/*
|	Author: Matthew Schmidt
|	Date: 2/16/2013
|	Program Identification: Dynamic Queue header file
|	Abstract: This is the header file that contains the 
|	declaration of our class data members and methods.
*/

#pragma once
#include <iostream>
using namespace std;
template <class T>
class Queue_dynamic
{
protected:
	// The structure of the linklist is found here.  The nodes
	// have a value and a pointer to the next linklist.

	struct LinkList
	{
	    int value;
        LinkList *next;
        LinkList(int value1, LinkList *next1 = NULL)
		{
            value = value1;
            next = next1;
		}
	};
    LinkList *head, *tail;   // Pointers that retain info of node locations
	char temp; // used as a temp storage for process of returning int.
public:
	// Class Constructor
	Queue_dynamic(void);
	// Class Deconstructor
	~Queue_dynamic(void);
	// Enqueue function.  This adds values to the dynamic queue. Templated.
	void enqueue(T x);
	// Dequeue function.  This removes values from the dynamic queue
	// and then returns an integer.
	int dequeue();
    // isEmpty is a function that checks to see if the queue is empty
	// and then returns a bool.
	bool isEmpty();
	// listQueue displays the current queue.
	void listQueue();
	// peek lets us see what is in the queue. An int is passed so we can determine how far 
	// into the peek we want to look. The integer parameter is explained in the cpp.
	T peek(int n);
	
};

