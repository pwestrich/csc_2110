/*-- Stack.cpp----------------------------------------------------------
 
   This file implements Stack member functions.

-------------------------------------------------------------------------*/
 
#include <iostream>
#include <cassert>
#include <new>
using namespace std;

#include "Stack.h"

//--- Definition of Stack constructor
Stack::Stack(int numElements)
{
   assert (numElements > 0);  // check precondition
   myCapacity = numElements;  // set stack capacity
                     // allocate array of this capacity
   myArray = new(nothrow) StackElement[myCapacity];
   if (myArray != 0)          // memory available
      myTop = -1;
   else
   {
      cerr << "Inadequate memory to allocate stack \n"
              " -- terminating execution\n";
      exit(1);
   }               // or assert(myArray != 0);
}

//--- Definition of Stack copy constructor
Stack::Stack(const Stack & original)
: myCapacity(original.myCapacity), myTop(original.myTop)
{
   //--- Get new array for copy
   myArray = new(nothrow) StackElement[myCapacity];   
                                     // allocate array in copy

   if (myArray != 0)                 // check if memory available
      // copy original's array member into this new array
      for (int pos = 0; pos < myCapacity; pos++) 
         myArray[pos] = original.myArray[pos];
   else
   {
      cerr << "*Inadequate memory to allocate stack ***\n";
      exit(1);
   }
}

//--- Definition of Stack destructor
Stack::~Stack()
{ 
   delete [] myArray;
}

//--- Definition of assignment operator
Stack & Stack::operator=(const Stack & original)
{
  if (this != &original)                   // check that not st = st
   {
     //-- Allocate a new array if necessary
      if (myCapacity != original.myCapacity) 
      {
	delete[] myArray;                  // destroy previous array

	myCapacity = original.myCapacity;  // copy myCapacity
         myArray = new StackElement[myCapacity]; 
         if (myArray == 0)                  // check if memory available
         {
	   cerr << "*** Inadequate memory ***\n";
            exit(1);
         }
       }
      //--- Copy original's array into this myArray
      for (int pos = 0; pos < myCapacity; pos++) 
         myArray[pos] = original.myArray[pos];

      myTop = original.myTop;              // copy myTop member
   }
   return *this;
}

//--- Definition of empty()
bool Stack::empty() const
{ 
   return (myTop == -1); 
}

//--- Definition of push()
void Stack::push(const StackElement & value){
   
     if (myCapacity > myTop){
          
          myTop++;                      //Increment top
          myArray[myTop] = value;       //Add value to the stack
          
     }
     
     else {
          
          cout << "Error! Stack is full!" << endl;
          
     }
     
}

//--- Definition of display()
void Stack::display(ostream & out) const
{
   for (int i = myTop; i >= 0; i--) 
      out << myArray[i] << endl;
}

//--- Definition of top()
StackElement Stack::top() const{
   
     if (!empty()){      //If not empty, add item to stack
          
          return myArray[myTop];
     
     }
     
     else {              //Otherise, give error message
          
          cout << "Error! Stack is empty!" << endl;
          
     }
     
}

//--- Definition of pop()
void Stack::pop(){
   
     if (!empty()){      //If not empty, decrement myTop
          
          myTop--;
          
     }
     
     else {              //Otherwise, error
          
          cout << "Error! Stack is empty!" << endl;
          
     }
}
