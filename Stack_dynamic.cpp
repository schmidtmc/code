#include "Stack_dynamic.h"
#include <iostream>
using namespace std;

/* Class Constructor
	This will set top to be -1 and then
	set size to zero. No arguements are passed.
*/
template <class T>
Stack_dynamic<T>::Stack_dynamic(void)
{
	head = NULL;
	size = 0;
}

/* Classs Destructor
	Destroys the object.

    This goes through the linked list and
    destroys each node.
*/
template <class T>
Stack_dynamic<T>::~Stack_dynamic(void)
{
    LinkList *node = head; // Start at head of list

	while (node != NULL)
     {
        LinkList *trash = node;
        node = node->next;
        delete trash;
     }
}

/* push Function
	This will create a new node and direct it to the
	next node and assign it to top.  Additional nodes
	will change top to whatever node was created last.

    char d is passed to put into a node a value of char type.
*/
template <class T>
void Stack_dynamic<T>::push(T d)
{
            head = new LinkList(d,head);
			//top = head;	
}

/* pop Function
	This function will return a char of whatever the
	value of top is and then delete the node.
*/
template <class T>
T Stack_dynamic<T>::pop()
{
	LinkList *node;
			if(isEmpty() == true)
			{
				T x;				// CODE for operators.
                node = head;
				x = node->value;
				head = head->next;
				delete node;
				return x;
			}
			else {
				return NULL;
			}

}


/* listStack Function
	This prints out what is in the stack
	at the moment the function is called.

	The right most value is the bottom.
*/
template <class T>
void Stack_dynamic<T>::listStack()
{
    T b;
    LinkList *node = head;
	cout << "The following is in Stack (last element is at bottom of stack): ";
	while(node)
	{
		b = node->value;
        cout << b << " ";
        node = node->next;
	}
	cout << "\n";
	
}

/* isEmpty Function
	This checks the list to see if it is empty
	or not. If it is empty, it will return false.
	If it is not empty, it will return true.
*/
template <class T>
bool Stack_dynamic<T>::isEmpty()
{
	if (head != NULL)
		return true;
	else
		return false;

}
// This function serves as a "peek" function and will return
// the value of whatever is at the top of the stack. It
// takes no input, but returns whatever the datatype is that is stored.
template <class T>
T Stack_dynamic<T>::showTop()
{
	return head->value;
}