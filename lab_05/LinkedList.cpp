#include <iostream>

using namespace std;

#include "LinkedList.h"

/*LinkedList constructor

Precondition:	A LinkedList object must be constructed.
Postcondition:	Its data members have been initialized 
                appropriately for an empty list.
*******************************************************************/

// Put implementation of LinkedList constructor here
LinkedList::LinkedList(){
     //Pre:: Someone has declared an object
     //Post:: the new object has been initialized
     
     size = 0;
     data = NULL;
     
}

//add definition of other classes here

int LinkedList::getSize(){
     
     return size;
     
}

void LinkedList::displayList(){
     
     Node* location = data;
     
     cout << "Printing the list..." << endl;
     
     while (location != NULL){ //Print the data as long a we're not at the end of the list
          
          cout << (*location).data << endl;
          
          location = (*location).next;//Advance
          
     }
     
}

void LinkedList::insertItem(ElementType newItem){
     
     Node* nPtr = new Node(newItem);  //Create new node
     bool found = false;
     
     Node* predPtr = NULL; //Previous location
     Node* currPtr = data; //Current location
     
     while ((currPtr != NULL) && found){ //While we haven't found where the new node goes...
          
          if (currPtr->data > nPtr->data){ //... Try to find a match
               
               found = true; //If so, we found it
               
          }
          
          else { //Otherwise, advance the pointers.
               
               predPtr = currPtr;
               currPtr = currPtr->next;
               
          }
          
     }
     
     if (predPtr == NULL){
          
          nPtr->next = data;
          data = nPtr;
          
     }
     
     else {
          
          nPtr->next = predPtr->next;
          predPtr->next = nPtr;
          
     }
     
     size++; //Increment the size
     
     
}

LinkedList::Node::Node(ElementType newItem){
     
     data = newItem;
     
}
