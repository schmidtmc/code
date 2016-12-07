/*
|	Author: Matthew Schmidt
|	Date: 2/16/2013
|	Program Identification: Infix to prefix
|	Abstract: This program is designed to take a string
|	infix and convert it to postfix, so we can remove
|	() while maintaining the proper order of operations.
*/

#include <iostream>			// Standard input/output library
#include "Queue_static.h"	// header for static queue
#include "Stack_static.h"	// header for static stack
#include "Queue_static_char.cpp" // Required to be included by compiler.
#include "Stack_static.cpp" // Required to be included by compiler.
#include <fstream>			// file stream library

using namespace std;

int precedence(char b);		// Function that checks order of precedence
int evaluate(int u, int v, char c);	// Function that evalutes the postfix

int main()
{
    Queue_static_char<char> infix(30), almost(30), prefix(30);
    Stack_static<int> intStack(30);
	Stack_static<char> opStack(30), prepStack(30), charStack(30);
	char c, d, oper;				// Char declaration
	int x, run = 1, runOp2 = 1, runOp = 1,u,p, byPass = 1; // int declaration
	ifstream fin;		// file in declaration
	

	fin.open("infixMercury2.dat");	// File to read from

	if(!fin)							
	{
		cout << "Cannot open infixMercury.dat" << endl;	// Test to see if file exists
		exit(1);
	}
 
	cout << "Welcome to infix converter.\n\n";		// Program's command output

	while(fin.good()) {

			while (run == 1)     // loop while extraction from file is possible
			{
				c = fin.get();       // get character from file
				if (c != ';' && c != '.')	// Test to see if char is not ; or .
				{
					if( c != ' ' && c != '\r' && c != '\n' && c != '\t') // If whitespace
						infix.enqueue(c);	   // enqueue to infix queue.		
				} else {
					fin.ignore();	// if the 'if' conditional fails, then ignore char and end.
					run = 0;		// break out of loop
				}
			}
			run = 1;				// Reset run to 1 so that the next round of char ins can be read
			// Output our infix queue.
			cout << "The original infix expression is: "; infix.listQueue();

			while(!infix.isEmpty())	// While infix is full execute
			{
				c = infix.dequeue();		// dequeue from infix to char c.
				prepStack.push(c);
			}

			while(!prepStack.isEmpty()) 
			{
				c = prepStack.pop();

				if(c != '+' && c != '-' && c != '/' && c != '*' && c != '(' && c != ')') { // Not an operator or ( )
					almost.enqueue(c);
				} else if ((c == '+' || c == '-' || c == '/' || c == '*') && opStack.isEmpty()) {
				    opStack.push(c);
				} else if (c == ')') {
                    opStack.push(c);
				} else if (c == '(') { 
					oper = opStack.pop();
					while (oper != ')') {
						almost.enqueue(oper);
						oper = opStack.pop();
					}
				} //If the scanned character is an operator and the stack is not empty and the 
				  //priority of the scanned character is more than that of the operator on top of the  stack then push the character on the stack.
				else if ((c == '+' || c == '-' || c == '/' || c == '*') && !opStack.isEmpty() && (precedence(c) >= precedence(opStack.showTop()))) {
					opStack.push(c);
				} /*If the scanned character is an operator and the stack is not empty and the priority of the scanned character is less than 
				  that of the operator on top of the  stack then pop the contents of the stack till this character can be pushed on to the stack.*/
				else if ((c == '+' || c == '-' || c == '/' || c == '*') && !opStack.isEmpty() && (precedence(c) < precedence(opStack.showTop()))) {
					oper = opStack.pop();
					almost.enqueue(oper);
					opStack.push(c);
				}
			}

			while (!opStack.isEmpty()) { // Convert our Stack to queue
				c = opStack.pop();
				almost.enqueue(c);
			}

			while (!almost.isEmpty()) { // convert queue back to stack
				c = almost.dequeue(); // This is just to simply reverse the ordering
				prepStack.push(c);
			}

			while (!prepStack.isEmpty()) {
				c = prepStack.pop(); // Put back into queue so that it is in prefix notation.
				prefix.enqueue(c);
			}

			// Output our postfix queue.
			cout << "The prefix expression is: "; prefix.listQueue();
		
			while(!prefix.isEmpty()) {
				c = prefix.dequeue();
				if(c == '-' || c == '+' || c == '*' || c == '/') { // If c is operator, push into charStk. Push indic into int.
					charStack.push(c);
					intStack.push(2147483647);
				} else if (c != '-' && c != '+' && c != '*' && c != '/') { // If operand, execute this section.
					if(charStack.isEmpty()) { // If operand is the ONLY input, execute this and break loop.
						p = atoi(&c);
						intStack.push(p);
						break;				// Break while loop because we only have one input.
					}	
					if( intStack.showTop() == 2147483647) {
						x = atoi(&c);
						intStack.push(x);		// Push to int if top is not operand.
                        if(!prefix.isEmpty()) {
                            byPass = 2;
						}
					} else if ( intStack.showTop() != 2147483647) { // If top is operand...
							p = atoi(&c);		// Convert char to int.
							intStack.push(p);   // Push int to intStack
						while( intStack.showTop() != 2147483647 && runOp == 1) {
							x = intStack.pop(); // We pop the int we just put in. This is for algorithm purpose only.
							p = intStack.pop(); // Pop the actual operand we are gonna perform on.
							intStack.pop();     // Gets rid of 'NUL'.
							d = charStack.pop();// Pop the operator we will perform on our operands.
							u = evaluate(p,x,d); // We evalute it.
                            if(d == '/' && x == 0) {
                                byPass = 0;
							}
							if( intStack.isEmpty() || intStack.showTop() == 2147483647) {
								intStack.push(u);	//If intStack is empty or top has indicator of an Operator, push to int.
								runOp = 0;			//Mark as 0 to exit out of whileLoop.
							} else {
								intStack.push(u);   //Push result back into Int. This is part of the algorithmn purpose above.
								runOp = 1;
							}
						}
						runOp = 1;	// Turn back on loop condition for next round.
					}
				}
			}
			if(byPass == 1) { // Default output
			    cout << "The prefix evaluted gives us: " << intStack.pop() << endl << endl;
			} else if(byPass == 0) { // Divided by zero output
                cout << "The prefix evaluted gives us: Undefined." << endl << endl;
                byPass = 1;
			} else if(byPass == 2) { // If we only have a single negative number input.
                cout << "The prefix evaluted gives us: " << charStack.pop() << intStack.pop() << endl << endl;
                byPass = 1;
			}
	}
	return 0;
}

/* Abstract: The precedence function is designed to tell the program
	the order of precednce of the operator being evaluted. It returns a 
	number that is used compare the char's number with another. The numbering
	is designed so that it follows precedence rules.

	Desc: char b is placed into a switch statement that will be matched
	to a case and then when matched, the function returns an int.*/
int precedence(char b)
{
	switch(b) {
	case '(': return 0;
	case '+': return 1;
	case '-': return 1;
	case '*': return 2; 
	case '/': return 2;
	default: return NULL;
	}
}

/* Abstract: This function actually executes the operations as signified
	by the char c. 

	Desc: char c tells the switch statement what type of operation is to 
	be performed. the ints u and v are the operands to be evaluted. It
	then returns an integer.
*/
int evaluate(int u, int v, char c) {

	switch(c) {
	case 42: return u * v;
	case 43: return u + v;
	case 45: return u - v;
	case 47: if( v != 0) { // TEST for Division by zero!
		        return u / v;
			 } else {
                 return NULL;
			 }
    default: return NULL;
	}

}