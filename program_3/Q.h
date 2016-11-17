/*
 
 Q.h
 by Philip Westrich
 for Assignment #3
 CSC 2110-002
 Wednesday, April 3, 2013
 
 Description:
 This is the header file for the templated class Q. It contains all things
 required for its use.
 
 It is a special type of linked-list queue that keeps track of how long each
 item stays in line. The object/struct must have 2 public data members: an
 integer called wait for the wait time, and a pointer to itself called next.
 
 */

#ifndef Q_H
#define Q_H

#ifndef EXCEPTION

#define EXCEPTION
#include <exception>     //for bad_alloc
#endif

#ifndef NEW
#define NEW
#include <new>           //for NULL
#endif

#ifndef IOSTREAM
#define IOSTREAM
#include <iostream>      //for console in/out
#include <iomanip>
#endif

#ifndef STRING
#define STRING
#include <string>        //for strings
#endif

using namespace std;

template <class T>
class Q {
     
public:
     
     Q();                          //Default constructor
     ~Q();                         //Default destructor
     void Initialize();            //Initialize the Q
     
     bool NQ(T* newItem);          //Insert an item at the end of the Q
     bool DQ();                    //Remove the first item in the Q
     bool isFull();                //Checks if the Q is full
     bool isEmpty();               //Checks if Q is empty
     bool incrementWait();         //Increments each object's wait time in line by 1
     
     int getLength();              //Gets current length of Q
     int getTotalServed();         //Gets the total number of items DQ'd
     int getTotalWait();           //Gets total wait time for all items removed
     
     double getAverageWait();      //Gets the average wait time for all items ever removed from the Q
     
     T* getFirstItem();            //Gets the first item in the Q
     
private:
     
     int length;                   //The length of the Q
     int cumulativeWait;           //Cumulative wait times for all items in Q
     int itemsServed;              //Number of items removed from the Q
     
     T* first;                     //Pointer to the first item in line
     T* last;                      //Pointer to the last item
     T* currentItem;               //pointer used to cycle through elements
     
};

template <class T>
Q<T>::Q(){
     /*
      Pre:     The object is created
      Post:    Q is initialized to the empty state
      */
     
     first = last = currentItem = NULL;
     length = cumulativeWait = itemsServed = 0;
     
}

template <class T>
Q<T>::~Q(){
     /*
      Pre:     The object leaves scope
      Post:    All memory is deallocated.
      */
     
     while (first != NULL){ //Delete items while the first item isn't NULL
          
          currentItem = first;     //Move first item to be deleted
          first = first->next;     //Advance to next item
          delete currentItem;      //Delete the current item
          
     }
     
}

template <class T>
void Q<T>::Initialize(){
     /*
      Pre:     The object exists
      Post:    All items previously in the Q are deallocated
               The object is re-initialized to the empty state
      */
     
     while (first != NULL){ //Delete items while the first item isn't NULL
          
          currentItem = first;     //Move first item to be deleted
          first = first->next;     //Advance to next item
          delete currentItem;      //Delete the current item
          
     }
     
     first = last = currentItem = NULL;             //Reset pointers
     length = cumulativeWait = itemsServed = 0;     //Reset length
     
}

template <class T>
bool Q<T>::NQ(T* newItem){
     /*
      Pre:     The object exists
      Post:    One item is added to the end of the Q
               length is incremented
               Returns true for success or false for failure
      */
     
     if (!isFull()){
          
          if (first == NULL){ //If Q is empty, add this way
               
               first = last = newItem;
               
          }
          
          else { //Otherwise, add to the end of the list
               
               last->next = newItem;    //Last points to new
               newItem->next = NULL;    //New points to NULL
               last = newItem;          //New becomed last
          }
          
          length++;      //Increment current length
     
          
          return true;   //Return true for success
          
     }
     
     else return false;  //Return false for failure
     
}

template <class T>
bool Q<T>::DQ(){
     /*
      Pre:     At least one item is on the Q
      Post:    The first item in the Q is removed and deallocated
               Returns true for success and false for failure
      */
     
     if (!isEmpty()){ //Check to see if Q is empty
          //If it isn't, delete the first item in line, and dectement length
          
          currentItem = first;     
          first = first->next;                    //Advance first pointer
          cumulativeWait += currentItem->wait;    //Add the node's wait time to the cumulative total
                    
          delete currentItem;      //Delete first item
          length--;                //Decrement current length
          itemsServed++;           //Increment items served
          
          return true;             //Return true for success
          
     }
     
     else return false;            //Return false for failure
     
}

template <class T>
bool Q<T>::isFull(){
     /*
      Pre:     The object exists
      Post:    Check for enough memory to add a new item to the Q
               Returns true if not enough memory, false if there is
      */
     
     try { //Try to create a new item
          
          T* test = new T;
          delete test;
          
          return false;       //Return false if no exception is thrown
          
     }
     
     catch (bad_alloc& ba){ //Catch the bad_alloc and print, if thrown
          
          cerr << "Warning! Bad allocation exception caught: " << ba.what() << endl;
          cerr << "Queue is full!" << endl;
          return true;   //Return true for full list
          
     }
     
}

template <class T>
bool Q<T>::isEmpty(){
     
     /*
      Pre:     The object exists
      Post:    Returns true for empty Q, false if not.
      */
     
     return (length == 0);
     
}

template <class T>
bool Q<T>::incrementWait(){
     /*
      Pre:     At least one item in the Q
      Post:    Increments each items wait counter and returns true
               Returns false if no items are in list
      */
     
     currentItem = first; //Start from the beginning
     
     while (currentItem != NULL){ 
          //While we're not at the end of the Q, increment each item't wait time
          //then advance to the next item.
          
          currentItem->wait++;     
          currentItem = currentItem->next;
          
     }
          
     return true;   //Return true for success
     
     
}

template <class T>
int Q<T>::getLength(){
     /*
      Pre:     The object exists
      Post:    Returns the length of the Q
      */
     
     return length;
     
}

template <class T>
int Q<T>::getTotalServed(){
     /*
      Pre:     The object exists
      Post:    Returns total number of items DQ'd 
      */
     
     return itemsServed;
     
}

template <class T>
int Q<T>::getTotalWait(){
     /*
      Pre:     The object exists
      Post:    Returns the cumulative wait time for every object removed from the Q
      */
     
     return cumulativeWait;
     
}

template <class T>
double Q<T>::getAverageWait(){
     /*
      Pre:     The object exists
      Post:    Average wait time for all served items is calculated and returned
               If itemsServed = 0, an exception is thrown.
      */
          
     try { // If we're about to divide by zero, catch it
          
          if (itemsServed == 0) throw string ("Divide by zero.");
          
     }
     
     catch (string it){
          
          cerr << "Exception: " << it << endl;
          exit(EXIT_FAILURE);
          
     }
          
     //Otherwise, return the average wait time
     return ((static_cast<double> (cumulativeWait)) / (static_cast<double> (itemsServed)));
     
}

template <class T>
T* Q<T>::getFirstItem(){
     /*
      Pre:     The object exists
      Post:    Returns a reference to the first object in the Q
               Will return NULL for empty Q
      */
     
     return first;
     
}

#endif
