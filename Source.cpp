/*
|	Author: Matthew Schmidt
|	Date: 2/16/2013
|	Program Identification: Stacks and Queue ADTs
|	Abstract: This program tests the operations of the ADTs to
|	ensure that everything is working correctly.
*/

#include <iostream>
#include "Queue_dynamic.h"	// header for dynamic queue
#include "Queue_static_char.h"	// header for static queue
#include "Stack_dynamic.h"	// header for dynamic stack
#include "Stack_static.h"	// header for static stack
#include "Queue_dynamic.cpp" // The following cpp files are included
#include "Stack_dynamic.cpp" // because the compiler required them to be
#include "Queue_static_char.cpp" // for linking purposes.
#include "Stack_static.cpp"

using namespace std;

int main()
{
	cout << "Now testing static Queue ADT...\n" << endl;
	Queue_static_char<int> queue(10); // creation of int static queue object.

	cout << "In the following order we add 2, 4, 1, 8 into the queue." << endl;
	cout << "We now enqueue (2).\n";
	queue.enqueue(2);                  // all enqueue executions will place value in queue.
	queue.listQueue();                 // list what is currently in queue.
	cout << "We now enqueue (4).\n";
	queue.enqueue(4);
	queue.listQueue();
	cout << "We now enqueue (1).\n";
	queue.enqueue(1);
	queue.listQueue();
	cout << "We now enqueue (8).\n";
	queue.enqueue(8);
	queue.listQueue();
	cout << "We now dequeue the value from the front."  << endl;
	cout << queue.dequeue() << " has left the queue." << endl;
    queue.listQueue();
    // This tells us what value is at front position and back.
    // It is also the function that triggers peek() (front position)
	queue.whereIsEveryone();          
	cout << "We dequeue another." << endl;
	cout << queue.dequeue() << " has left the queue." << endl;
	queue.listQueue();
	queue.whereIsEveryone();
	cout << "We will now add 7 to the queue." << endl;
	queue.enqueue(7);
	queue.listQueue();
	queue.whereIsEveryone();
	cout << "We dequeue another." << endl;
	cout << queue.dequeue() << " has left the queue." << endl;
    queue.listQueue();
	queue.whereIsEveryone();
	cout << "We dequeue another." << endl;
	cout << queue.dequeue() << " has left the queue." << endl;
    queue.listQueue();
	queue.whereIsEveryone();
	cout << "We dequeue another." << endl;
	cout << queue.dequeue() << " has left the queue." << endl;
	queue.listQueue();
	cout << "We now attempt to dequeue when there is nothing to dequeue.\n";
	queue.dequeue();
	cout << "\nNow we will fill the queue up with 1-10 AND witness the wraparound.\n";
    cout << "backPos is at index 5 (array) since this is where the last enqueue was,\n"; 
    cout << "and is the spot to be at the front position, so 1 it will the sixth value in the list.\n";
	for(int i = 1; i < 11; i++) // For loop to fill up queue.
		queue.enqueue(i);
    queue.listQueue();
	queue.whereIsEveryone();
	cout << "We will test to see if the queue reports full by enqueing 32.\n";
    cout << "This is triggered when the front position has not left queue yet.\n";
    cout << "and no space is available in the array.\n";
	queue.enqueue(32);
	cout << "Queue testing successfully completed!" << endl;
	cout << "\n\n";

	Stack_static<int> stack(10); // Creation of static stack object
    // showTop() is also used in this section. It is shown to be working correctly.
	cout << "Now testing static Stack ADT...\n" << endl;
	cout << "In the following order we add 1, 2, 3, 4 into the stack.\nFirst element is the bottom of the stack." << endl;
	cout << "We push in (1).\n";
	stack.push(1);          // All push operations push the arguement into the stack.
	stack.listStack();      // All listStack operations list what is currently in the stack at that time.
	cout << "We push in (2).\n";
	stack.push(2);
	stack.listStack();
	cout << "We push in (3).\n";
	stack.push(3);
	stack.listStack();
	cout << "We push in (4).\n";
	stack.push(4);
	stack.listStack();                                  
	cout << "\nNow we remove the item on the top of the stack (" << stack.showTop() << ")." << endl;
	stack.pop();            // All pop operations pop whatever is on top of the stack at that time.
	stack.listStack();
	cout << "Now we remove the item on the top of the stack (" << stack.showTop() << ")." << endl;
	stack.pop();
	stack.listStack();
	cout << "Now we remove the item on the top of the stack (" << stack.showTop() << ")." << endl;
	stack.pop();
	stack.listStack();
	cout << "Now we remove the item on the top of the stack (" << stack.showTop() << ")." << endl;
	stack.pop();
	stack.listStack();
	cout << "Now we try to pop again even though the stack has nothing in it." << endl;
	stack.pop();
	cout << "Now we will add 1-10 into our stack to fill our stack." << endl;
	for(int i = 1; i < 11; i++) {
		cout << "We push in (" << i << ")\n";
		stack.push(i);
		stack.listStack(); }
	cout << "Now we will try to add one more to our full stack." << endl;
	cout << "We push in (22)\n";
	stack.push(22);
	cout << "Stack testing successfully completed!" << endl;

	Queue_dynamic<int> queueD; // Creation of int dynamic queue object.

	cout << "\n\nNow testing Dynamic Queue ADT...\n" << endl;
	cout << "In the following order we add 2, 4, 1, 8 into the queue where 2 is in front." << endl;
	cout << "We now enqueue 2.\n";
	queueD.enqueue(2);
	queueD.listQueue();
	cout << "We now enqueue 4.\n";
	queueD.enqueue(4);
	queueD.listQueue();
	cout << "We now enqueue 1.\n";
	queueD.enqueue(1);
	queueD.listQueue();
	cout << "We now enqueue 8.\n";
	queueD.enqueue(8);
	queueD.listQueue(); // queue.peek(0) tells us what is in the front position.
	cout << "Now we dequeue the first in line, which is (" << queueD.peek(0) << ").\n";
	queueD.dequeue();
	queueD.listQueue();
	cout << "Now we dequeue the first in line, which is (" << queueD.peek(0) << ").\n";
	queueD.dequeue();
	queueD.listQueue();
	cout << "Now we dequeue the first in line, which is (" << queueD.peek(0) << ").\n";
	queueD.dequeue();
	queueD.listQueue();
	cout << "Now we dequeue the first in line which is the last one.\n";
	queueD.dequeue();
	queueD.listQueue();
	cout << "We will now attempt to dequeue with nothing in queue." << endl;
	queueD.dequeue();
	cout << "Now we will enqueue 1-10\n";
	for(int i = 1; i < 11; i++)
		queueD.enqueue(i);
	queueD.listQueue();
	cout << "Since this queue is dynamic, we can enqueue one or more.\n";
	queueD.enqueue(213);
	queueD.listQueue();
	cout << "Dynamic Queue testing successfully completed!" << endl;

	Stack_dynamic<int> stackD;  // Creation of int dynamic stack.

	cout << "\n\nNow testing Dynamic Stack ADT...\n" << endl;
	cout << "In the following order we add 1, 2, 3, 4 into the stack." << endl;
	cout << "We now push (1) into the stack" << endl;
	stackD.push(1);
	stackD.listStack();
	cout << "We now push (2) into the stack" << endl;
	stackD.push(2);
	stackD.listStack();
	cout << "We now push (3) into the stack" << endl;
	stackD.push(3);
	stackD.listStack();
	cout << "We now push (4) into the stack" << endl;
	stackD.push(4);
	stackD.listStack();
	cout << "Now we remove the item on the top of the stack (" << stackD.showTop() << ")." << endl;
	stackD.pop();
	stackD.listStack();
	cout << "Now we remove the item on the top of the stack (" << stackD.showTop() << ")." << endl;
	stackD.pop();
	stackD.listStack();
	cout << "Now we remove the item on the top of the stack (" << stackD.showTop() << ")." << endl;
	stackD.pop();
	stackD.listStack();
	cout << "Now we remove the item on the top of the stack (" << stackD.showTop() << ")." << endl;
	stackD.pop();
	stackD.listStack();
	cout << "Now we push a 88 in the stack...\n";
	stackD.push(88);
	stackD.listStack();
	cout << "Now we remove the item on the top of the stack (88)." << endl;
	stackD.pop();
	stackD.listStack();
	cout << "Now we try to pop again even though the stack has nothing in it." << endl;
	stackD.pop();
	cout << "Stack testing successfully completed!" << endl;


	return 0;
}