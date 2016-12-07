#include "Queue_dynamic.h"

/* Static Queue Constructor
	This sets the head and tail pointer
	to equal null.
*/
template <class T>
Queue_dynamic<T>::Queue_dynamic(void)
{
	head = NULL;
	tail = NULL;
}

/* Static Queue Destructor
	Destroys the object
*/
template <class T>
Queue_dynamic<T>::~Queue_dynamic(void)
{
    LinkList *node = head; // Start at head of list

	while (node != NULL)
     {
        LinkList *trash = node;
        node = node->next;
        delete trash;       // delete the node.
     }
}

/* Enqueue Function
	This uses a list to place the passed value
	into a node. It first checks if head exists,
	and if it doesn't, it creates a node.

	If we already have an element in queue,
	we use tail to point directly to the last
	position in line. This reduces the running 
	time needed to traverse the list.
*/
template <class T>
void Queue_dynamic<T>::enqueue(T x)
{
	LinkList *node;
        if(head == NULL) { // If no head exists...
            head = new LinkList(x);
			tail = head; // assign head to tail.
		} else {
			node = tail->next; // Go right to the tail
            tail->next = new LinkList(x,node);
			tail = tail->next; //
		}
	}

/* Dequeue Function
	This method goes into the list and then
	removes the current head of the list and
	returns its value and then set's head to the
	position right after the previous head.

	If queue is empty, it outputs a string informing
	the user that it is empty.
*/
template <class T>
int Queue_dynamic<T>::dequeue()
{
	LinkList *node;

                node = head;
				if(isEmpty() == true) {
					temp = node->value;
					head = head->next;
					delete node;
					return temp;
				} else {
					cout << "Nothing to dequeue!\n";
					return NULL;
				}
}

/* isEmpty Function
	This checks the list to see if it is empty
	or not. If it is empty, it will return true.
	If it is not empty, it will return false.
*/
template <class T>
bool Queue_dynamic<T>::isEmpty()
{
	if (head != NULL)
		return true;
	else
		return false;
}

/* listQueue Function
	This just prints out the current Queue as 
	it is when the method is called.*/
template <class T>
void Queue_dynamic<T>::listQueue()
{
	T p;      
	if(isEmpty() == true) {
    LinkList *node = head;
	while(node)
	{
		p = node->value;
        cout << p << " ";
        node = node->next;
	}
	cout << "\n";
	} else
		cout << "Nothing to display!\n";
}
/* peek function.
This is the peek function and it is an expanded
version of my own.  It offers the ability to
view what is currently in the front position,
but also in the second position.

There are two accepted ints that it takes. 
0 for first position
1 for the second position.
The int tells the function what position to return.
*/
template <class T>
T Queue_dynamic<T>::peek(int x)
{
	LinkList *node;
	node = head;
	if(x == 0) {
		return node->value;
	} else if(x == 1) {
		if(node != NULL) {
			node = node->next;
			return node->value;
			node = node->next;
		} else {
			return NULL;
		}
	} else {
		return NULL;
	}
}