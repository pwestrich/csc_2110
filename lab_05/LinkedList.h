/*--- LinkedList.h --------------------------------------------------------
  This header file contains the declarations of LinkedList, a class for
  singly-linked lists.
 
  Example provided by:   Larry R. Nyhoff
                           
  Add a list of the basic operations including brief descriptions.
   
  Add your names here.

 --------------------------------------------------------------------------*/

#ifndef LINKEDLIST
#define LINKEDLIST

#include <iostream>

using namespace std;

//----- Add typdef statement here

typedef int ElementType;

class LinkedList
{
 public:
   //------ LinkedList OPERATIONS

   // Prototype the class constructor here
     LinkedList();
  
  // Prototype and document the size() operation here
     int getSize();
     
  // Prototype and document display() here
     void displayList();
  
  // Prototype insert() here
     void insertItem(ElementType newItem);

private:
  class Node
  {
    public:

     //------ DATA MEMBERS OF Node
       ElementType data;
       Node* next;

     //------ Node OPERATIONS
       
       Node(ElementType newItem);

    
     /* --- The Node class constructor initializes a Node's data members.

        Precondition:  None
        Receive:       dataValue, an ElementType value;
        Postcondition: The data and next members have been set to
                       dataValue and 0, respectively.
     -------------------------------------------------------------------*/

   }; //--- end of Node class

   typedef Node *NodePointer;
   
   //------ DATA MEMBERS OF LinkedList
   // declare first as a pointer to a Node and declare mySize
     
     int size;
     Node* data;

}; //--- end of LinkedList class

#endif
