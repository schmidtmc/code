#include <iostream>
#include <vector>
#include "Stack_static.h"

using namespace std;


/* Class Constructor
	This will set top to be -1 and then
	loop through the array to set null.

	int n is passed in to set the size of the array.
*/
template <class T>
Stack_static<T>::Stack_static(int n)
{
	 top = -1;
	 sArray = new int[n];
	 SIZE = n;
	 for (int i = 0; i < SIZE; i++)
	 {
		 sArray[i] = NULL;
	 }
}

/* Classs Destructor
	Destroys the object.
*/
template <class T>
Stack_static<T>::~Stack_static(void)
{
	delete [] sArray;
}

/* push Function
	This checks to see if the array is full and
	if it isn't, it will take the passed integer
	and plug it in.  Otherwise, it will report
	an error stating that the array is full.

	It puts the value in the 0 index and continues
	to place each consecutive value after it.  The 
	last element is the top of the stack.
*/
template <class T>
void Stack_static<T>::push(int x)
{
	if(isFull() == false) // False means not full
	{
		top++;
		sArray[top] = x;
		
	} else
		cout << "The stack is full!" << endl;
}


/* pop Function
	This checks to see if the array is empty, and if
	the array is not empty it will go ahead and NULL
	whatever is being popped and then return that 
	value.

	If the array is empty, it will report an error.
*/
template <class T>
T Stack_static<T>::pop()
{
	if(isEmpty() == false)	// False = has something in stack.
	{
		T x = sArray[top];
		sArray[top] = NULL;
		top--;
		return x;
	}
	else {
		top = -1;
		cout << "There is nothing to pop!" << endl;
		return NULL;
	}

}

/* listStack Function
	This prints out what is in the stack
	at the moment the function is called.

	The right most value is the top.
*/
template <class T>
void Stack_static<T>::listStack()
{
	cout << "Now our stack consists of: ";
	for(int i = 0; i < SIZE; i++)
		cout << sArray[i] << " ";

	cout << endl;
}

/* isEmpty Function
	This checks the array to see if it is empty
	or not. If it is empty, it will return true.
	If it is not empty, it will return false.
*/
template <class T>
bool Stack_static<T>::isEmpty()
{
	if(top == -1)
		return true;
	else
		return false;
}

/* isFull Function
	This checks the array to see if it is full
	or not. If it is full, it will return true.
	If it is not full, it will return false.
*/
template <class T>
bool Stack_static<T>::isFull()
{
	if(top != (SIZE - 1))
		return false;
	else
		return true;
}

// This function serves as a "peek" function and will return
// the value of whatever is at the top of the stack. It
// takes no input, but returns whatever the datatype is that is stored.
template <class T>
T Stack_static<T>::showTop()
{
	return sArray[top];
}