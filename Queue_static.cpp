#include <iostream>
#include "Queue_static.h"

using namespace std;

/* Static Queue Constructor
	This sets frontPos of the method to zero, the
	backPos to -1 and the currentSize of the array
	to be zero, which is how many are in queue.

	This also fills our array with NULL.
*/
Queue_static::Queue_static(int n)
{
	 qArray = new int[n];   // Create new array of size n
	 SIZE = n;              // Assign SIZE n for use elsewhere
	 frontPos = 0;          
	 backPos = -1;
	 currentSize = 0;
	 for (int i = 0; i < SIZE; i++)
	 {
		 qArray[i] = NULL;
	 }
}

/* Static Queue Destructor
	Destroys the object
*/
Queue_static::~Queue_static(void)
{
	delete [] qArray;   // Delete array upon object destruction
}

/* Enqueue Function
	This places the passed value to the front
	of the array, or the location following the
	last value in line.
*/
void Queue_static::enqueue(int x)
{
	if(isFull() == false)   // if array
	{
		currentSize++;
		backPos++;
		qArray[backPos] = x;
	}
	else
		cout << "The queue is full! " << endl;

}

/* Dequeue Function
	This goes into the array and finds the value
	in the front position and removes it from the array
	and then returns the value as an integer.

	Otherwise, if empty, the program will reset the 
	frontPos and backPos, which is critical to the proper
	operation of dequeue. It will NOT operate correctly
	if removed.
*/
int Queue_static::dequeue()
{
	if(isEmpty() == true)
	{
		frontPos = 0;
		backPos = -1;
		cout << "There is nothing to dequeue!\n";
        return NULL;
	} else {
	int temp;
	currentSize--;
	temp = qArray[frontPos];
	qArray[frontPos] = NULL;
	frontPos++;
	return temp;
	}
}

/* listQueue Function
	This just prints out the current Queue as 
	it is when the method is called.*/
void Queue_static::listQueue()
{
	for(int i = 0; i < SIZE; i++) {
		cout << qArray[i] << " ";
	}
	cout << endl;
	
}

/* getFrontPos Function
	This is used for testing purposes. It
	just returns the integer of the current
	value in the front position.
*/
int Queue_static::getfrontPos()
{
	return qArray[frontPos];
}

/* getBackPos Function
	This is used for testing purposes. It
	just returns the integer of the current
	value in the back position.
*/
int Queue_static::getbackPos()
{
	return qArray[backPos];
}

/* whereIsEveryone Function
	This is used for testing purposes. It just 
	calls on both getBackPos and getFrontPos.
*/
void Queue_static::whereIsEveryone()
{
	cout << "The number currently at the front is: " << qArray[frontPos] << endl;
	cout << "The number currently at the back is: " << qArray[backPos] << endl;
}

/* isFull Function
	This checks the array to see if it is full 
	or not. If it is full, it will return true.
	if it is not full, it will return false.
*/
bool Queue_static::isFull()
{
	if(currentSize < SIZE)
		return false;
	else
		return true;
}

/* isEmpty Function
	This is used for testing purposes. It
	just returns the integer of the current
	value in the front position.
*/
bool Queue_static::isEmpty()
{
	if(currentSize == 0)
		return true;
	else
		return false;
}