/*-- Stack.h ---------------------------------------------------
 
  This header file defines a Stack data type.
  Basic operations:
    constructor:  Constructs an empty stack
    empty:        Checks if a stack is empty
    push:         Modifies a stack by adding a value at the top
    top:          Accesses the top stack value; leaves stack
                    unchanged
    pop:          Modifies stack by removing the value at the
                    top
    display:      Displays all the stack elements

  Class Invariant:
    1. The stack elements (if any) are stored in positions
       0, 1, . . ., myTop of myArray.
    2. -1 <= myTop < myCapacity 

--------------------------------------------------------------*/

#include <iostream>
using namespace std;

#ifndef STACK
#define STACK

typedef int StackElement;

class Stack
{
   public:
      /***** Function Members *****/
      /***** Constructors *****/
      Stack(int numElements = 128);
      /*----------------------------------------------------------
        Construct a Stack object.

        Precondition:  None.
        Postcondition: An empty Stack object has been constructed
            (myTop is initialized to -1 and myArray is an array
            with numElements (default 128) elements of type 
            StackElement).
      -----------------------------------------------------------*/

      Stack(const Stack & original);
      /*----------------------------------------------------------
        Copy Constructor 

        Precondition:  original is the stack to be copied and 
            is received as a const reference parameter.
        Postcondition: A copy of original has been constructed.
      -----------------------------------------------------------*/

     /***** Destructor *****/
      ~Stack(); 
      /*----------------------------------------------------------
        Class destructor 

        Precondition:  None
        Postcondition: The dynamic array in the stack has been 
          deallocated.
      -----------------------------------------------------------*/

      /***** Assignment *****/
      Stack & operator= (const Stack & original);
      /*----------------------------------------------------------
        Assignment Operator 
    
       Precondition:  original is the stack to be assigned and 
           is received as a const reference parameter.
       Postcondition: The current stack becomes a copy of 
           original and a reference to it is returned.
      -----------------------------------------------------------*/

      bool empty() const;
      /*-----------------------------------------------------------
        Check if stack is empty.
        Precondition: None
        Postcondition: Returns true if stack is empty and 
            false otherwise.
       -----------------------------------------------------------*/

      void push(const StackElement & value);
      /*-----------------------------------------------------------
        Add a value to a stack.

        Precondition:  value is to be added to this stack
        Postcondition: value is added at top of stack provided 
            there is space; otherwise, a stack-full message is 
            displayed and execution is terminated.
       -----------------------------------------------------------*/

      void display(ostream & out) const;
      /*-----------------------------------------------------------
      Display values stored in the stack. 

        Precondition:  ostream out is open.
        Postcondition: Stack's contents, from top down, have
            been output to out.
       -----------------------------------------------------------*/

      StackElement top() const;
      /*-----------------------------------------------------------
        Retrieve value at top of stack (if any).

        Precondition:  Stack is nonempty
        Postcondition: Value at top of stack is returned, unless
            the stack is empty; in that case, an error message is
            displayed and a "garbage value" is returned.
       ----------------------------------------------------------*/

      void pop();
      /*-----------------------------------------------------------
        Remove value at top of stack (if any).

        Precondition:  Stack is nonempty.
        Postcondition: Value at top of stack has been removed, 
            unless the stack is empty; in that case, an error 
            message is displayed and execution allowed to proceed.
       ----------------------------------------------------------*/ 

   private:
      /***** Data Members *****/
      int myCapacity,           // capacity of stack
          myTop;                // top of stack
      StackElement * myArray;   // dynamic array to store elements

}; // end of class declaration

#endif
