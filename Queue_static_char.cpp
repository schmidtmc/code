#include <iostream>
#include "Queue_static_char.h"

using namespace std;

/* Static Queue Constructor
	This sets frontPos of the method to zero, the
	backPos to -1 and the currentSize of the array
	to be zero, which is how many are in queue.

	This also fills our array with NULL. An int n
    is passed so that we know what size the array
    is to be.
*/
template <class T>
Queue_static_char<T>::Queue_static_char(int n)
{
	 qArray = new T[n];
	 SIZE = n;
	 frontPos = 0;
	 backPos = -1;
	 currentSize = 0;
	 for (int i = 0; i < SIZE; i++)
	 {
		 qArray[i] = NULL;
	 }
}

/* Static Queue Destructor
	Destroys the object by deleting the array.
*/
template <class T>
Queue_static_char<T>::~Queue_static_char(void)
{
	delete [] qArray;
}

/* Enqueue Function
	This places the passed value to the front
	of the array, or the location following the
	last value in line.

    A template is used here, so T represents 
    whatever type is sent over. x represents
    that value.
*/
template <class T>
void Queue_static_char<T>::enqueue(T x)
{
	if(isFull() == false)
	{
		currentSize++;
		backPos = (backPos + 1) % SIZE;
		qArray[backPos] = x;
	} else 
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
template <class T>
T Queue_static_char<T>::dequeue()
{
	if(isEmpty() == true)
	{
		cout << "There is nothing to dequeue!\n";
        return NULL;
	} else {
	    T temp;
	    currentSize--;
	    temp = qArray[frontPos];
	    qArray[frontPos] = NULL;
        frontPos = (frontPos + 1) % SIZE;
	    return temp;
	}
}

/* listQueue Function
	This just prints out the current Queue as 
	it is when the method is called.*/
template <class T>
void Queue_static_char<T>::listQueue()
{
	for(int i = 0; i < SIZE; i++) {
        if(qArray[i] != 0)  // Print only if ACSII is not NULL.
		    cout << qArray[i] << " ";
	}
	cout << endl;
	
}

/* Peek Function
	It just returns the integer of the current
	value in the front position. No Args passed.
*/
template <class T>
int Queue_static_char<T>::peek()
{
	return qArray[frontPos];
}

/* getBackPos Function
	This is used for testing purposes. It
	just returns the integer of the current
	value in the back position.
*/
template <class T>
int Queue_static_char<T>::getbackPos()
{
	return qArray[backPos];
}

/* whereIsEveryone Function
	This is used for testing purposes. It just 
	calls on both getBackPos and peek.
*/
template <class T>
void Queue_static_char<T>::whereIsEveryone()
{
	cout << "The number currently at the front is: " << peek() << endl;
	cout << "The number currently at the back is: " << getbackPos() << "\n\n";
}

/* isFull Function
	This checks the array to see if it is full 
	or not. If it is full, it will return true.
	if it is not full, it will return false.
*/
template <class T>
bool Queue_static_char<T>::isFull()
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
template <class T>
bool Queue_static_char<T>::isEmpty()
{
	if(currentSize == 0)
		return true;
	else
		return false;
}