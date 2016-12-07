/*
|	Author: Matthew Schmidt
|	Date: 2/16/2013
|	Program Identification: Infix to postfix
|	Abstract: This program is designed to take a string
|	infix and convert it to postfix, so we can remove
|	() while maintaining the proper order of operations.
*/

#include <iostream>			// Standard input/output library
#include "Queue_static_char.h"	// header for static queue
#include "Stack_static.h"	// header for static stack
#include "Queue_static_char.cpp"
#include "Stack_static.cpp"
#include <fstream>			// file stream library

using namespace std;

int precedence(char b);		// Function that checks order of precedence
int evaluate(int u, int v, char c);	// Function that evalutes the postfix

int main()
{
	Queue_static_char<char> infix(25), postfix(25);	// Dynamic Queue creation
	Stack_static<char> opStack(25);			// Dynamic Stack creation. operator stack
	Stack_static<char> evalStack(25);		// Stack to be evaluated.
	char c, opToken;				// Char declaration
	int x, run = 1, runOp = 1, u, v, byPass = 1; // int declaration
	ifstream fin;					// file in declaration
	fin.open("infixMercury.dat");	// File to read from

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
					if( c != ' ' && c != '\r' && c != '\t' && c != '\n') // white space test
						infix.enqueue(c);	   // enqueue to infix queue.		
				} else {
					fin.ignore();	// if the 'if' conditional fails, then ignore char and end.
					run = 0;		// break out of loop
				}
			}
			run = 1;				// Reset run to 1 so that the next round of char ins can be read
			// Output our infix queue.
			cout << "The original infix expression is: "; infix.listQueue();

			while(infix.isEmpty() == false)	// While infix is full execute
			{
				c = infix.dequeue();		// dequeue from infix to char c.
      

				//Test to ensure that c is not an operator. if not, then enqueue to postfix.
				if(c != '+' && c != '-' && c != '/' && c != '*' && c != '(' && c != ')') {
					postfix.enqueue(c);
				} else if (c == '(') // if c is (, then push to opStack
					opStack.push(c);
				else if (c == ')') { // if c is ), then pop from opstack
					opToken = opStack.pop();
					// The first opToken from last statement is evaluated, which
					// enables the next while loop to activate. While keeps looping
					// until ( is reached. The ( is left remaining in opToken because
					// the next time around it will be reassigned anyways.
					while(opToken != '(') { 
						postfix.enqueue(opToken);
						opToken = opStack.pop();
					}
					// Else if to check if we have an operator.
				} else if (c == '+' || c == '-' || c == '/' || c == '*') {
					// If true, then it is true that it is NOT empty.
					while(opStack.isEmpty() == false && runOp == 1) {
						opToken = opStack.pop();
						// Check if opToken > c, then place in postfix if it is.
						// Push c into opStack and then kill while loop. This conditional
						// uses the precedence function. Please read there for how it works.
						if(precedence(opToken) >= precedence(c)) {
							postfix.enqueue(opToken);
							opStack.push(c);
							runOp = 0;
						} // if opToken < c, then push opToken to operator stack and then c.
						else if (precedence(opToken) <= precedence(c)) {
							opStack.push(opToken);
							opStack.push(c);
							//postfix.enqueue(c);
							runOp = 0;
						} else
							runOp = 0;
					}
					// if runOP is still one, push the remaining c into the op stack.
					if(runOp == 1)
						opStack.push(c);
					// Re-enable runOP so that the while loop can run again on next round.
					runOp = 1;
				}
	
			}
			// This while loop will empty out all remaining operators from
			//the opStack and enqueue it to the postfix.
			while(opStack.isEmpty() == false) {
				opToken = opStack.pop();
				postfix.enqueue(opToken);
			}
			// Output our postfix queue.
			cout << "The postfix expression is: "; postfix.listQueue();
			// While the postfix is NOT empty (I think in opposites here...)
			// dequeue from postfix to char c.  Use ASCII to determine what
			// operations to perform. if a number (48-57), change c to int
			// and push into evalStack. Otherwise, Pop out two from evalstack
			// and then evaluate it. The char c is used to signify what operation
			// is being performed to the function.
			while(postfix.isEmpty() == false) {
				c = postfix.dequeue();
				if(c >= 48 && c <= 57) {
					x = atoi(&c);	// convert char to int
					evalStack.push(x);
				} else {
					u = evalStack.pop();
					v = evalStack.pop();
					x = evaluate(v,u,c);
                    if(c == '/' && u == 0) { // If we divided by zero...
						byPass = 0;
					}
					evalStack.push(x);		// take return value and push back in.
				}
			}
			if(byPass == 1) {
			x = evalStack.pop(); // Pop out our answer and then output it.
			cout << "The postfix evaluted gives us: " << x << endl << endl;
			} else if (byPass == 0) { // Execute this if we have division by zero.
				cout << "The postfix evaluated gives us: Undefined.\n\n";
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