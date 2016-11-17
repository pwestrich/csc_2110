/*
 LinkedList.h
 by Philip Westrich
 for CSC 2110-002. Program #2
 Friday, March 8, 2013
 
 Description:
     This is the header file for the LinkedList class. It will contain the 
     definition for the class, as well as any other files and definitions that
     are needed for its function.

 */

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

template<class T>
class LinkedList{
     
public:
     
     LinkedList();                           //Default constructor
     ~LinkedList();                          //Destructor
     
     void putItem(const T& item);            //Inserts items
     void displayList();                     //Displays the entire list
     void getItem(T& item, bool& found);     //Finds items


     bool deleteItem(const T& item);         //Deletes items
     bool getNewItem();                      //Gets the data for a new item from the user
     bool isFull();                          //Checks if the list is full
     
private:
     
     T* data;                      //Pointer to start of list
     unsigned long int length;    //Length of list. For possible really, really long lists
     
};

template<class T>
LinkedList<T>::LinkedList(){
     /*
      Pre:     An object has been declared
      
      Post:    The object is initialized to length 0 and NULL for data
      
      */
     
     length = 0;
     data = NULL;
     
}

template<class T>
LinkedList<T>::~LinkedList(){
     /*
      Pre:     An object has been declared and left scope
      
      Post:    All data is deallocated
      
      */
     
     
     T* nextItem = data->next;
     
     while ((data != NULL) && (length > 0)){ //While the list still has data, delete it
          
          delete data;
          
          data = nextItem;    //Advance to next item

          if (nextItem!= NULL){
          
               nextItem = nextItem->next;
               
          }
          
     }
     
}

template<class T>
bool LinkedList<T>::isFull(){
     /*
      Pre:     The object exists
      
      Post:    We check for enough memory to declare another node
      */
     
     try {
          
          T* test = new T;         //Try to make a new node
          delete test;             //Otherwise, it isn't; delete test node
          
     }
     catch (bad_alloc& exception) {
          
          return true;            //If it fails, the list is full
     }
     
     return false;
     
}

template<class T>
bool LinkedList<T>::deleteItem(const T& item){
     /*
      Pre:     A valid T was given
      
      Post:    If the item was found by its key, it is deleted.
               The function will return true if an item was deleted, and false if not.
      
      */
     
     
     T* previousItem = NULL;       //Previous item in list
     T* currentItem = data;        //Current item in list, start at beginning
     bool found = false;           //Set found to false
     
     while ((currentItem != NULL) && !found){ //While we haven't found the node's spot
          
          if (currentItem->Key == item.Key){ //Compare the items by key
               
               found = true; //If a match, we;ve found it.
               
          }
          
          else { //Otherwise, advance the pointers, and try again.
               
               previousItem = currentItem;
               currentItem = currentItem->next;
               
          }
          
     }
     
     if (found){ //If the item was found, cut it out of the list, delete it, and decrememnt the length.
          
          if (currentItem == data){ //If the item to delete happens to be the first in the list, here's its special case
               
               data = currentItem->next;
               delete currentItem;
               length--;
               
          }
          
          else { //For all other items in the list, use this one
          
               previousItem->next = currentItem->next;
               delete currentItem;
               length--;
               
          }
          
     }
     
     return found;  //Return success of the operation
     
}

template <class T>
void LinkedList<T>::getItem(T& item, bool& found){
     /*
      Pre:     A valid item was given
      
      Post:    The function will find a match for the object by key, and place it into the given T item
      
      */
     
     
     T* previousItem = NULL;       //Previous item in list
     T* currentItem = data;        //Current item in list, start at beginning
     found = false;                //Set found to false, just to make sure
     
     while ((currentItem != NULL) && !found){ //While we haven't found the node's spot
          
          if (currentItem->Key == item.Key){
               
               found = true;
               
          }
          
          else { //Otherwise, advance the pointers
               
               previousItem = currentItem;
               currentItem = currentItem->next;
               
          }
          
     }
     
     if (currentItem != NULL){
     
          item = (*currentItem);
          
     }
     
     
}

template<class T>
void LinkedList<T>::putItem(const T& item){
     /*
      Pre:     A valid item was given
      
      Post:    The item is placed into its proper sorted spot.
      
      */
     
     
     T* newItem = new T;           //Create new node with the new item
     T* previousItem = NULL;       //Previous item in list
     T* currentItem = data;        //Current item in list, start at beginning
     bool found = false;
     
     (*newItem) = item; //Put the incoming data into the node pointer we're going to insert into the list
     
     while ((currentItem != NULL) && !found){ //While we haven't found the node's spot
          
          if (currentItem->Key > newItem->Key){
               
               found = true;
               
          }
          
          else { //Otherwise, advance the pointers
               
               previousItem = currentItem;
               currentItem = currentItem->next;
               
          }
          
     }
     
     if (previousItem == NULL){ //Special case for inserting a new first item
          
          newItem->next = data;
          data = newItem;
          
     }
     
     else { //All other insertions use this one
          
          newItem->next = previousItem->next;
          previousItem->next = newItem;
          
     }
     
     length++; //Increment the list's size.
     
}

template<class T>
void LinkedList<T>::displayList(){
     /*
      Pre:     None
      
      Post:    All items in the list are printed to the screen
               The total number of items in the list is also printed
               If no items are in the list, nothing happens
      
      */
     
     T* currentItem = data;
     
     while (currentItem != NULL){
          
          cout << (*currentItem);
          
          currentItem = currentItem->next;
          
     }
     
     cout << "A total of " << length << " items were printed." << endl;
     
}
template<class T>
bool LinkedList<T>::getNewItem(){
     /*
      Pre:     None.
      
      Post:    Data for a new item is gathered from the user
               If an item by key already exists, say so and discard the data
               Otherwise, call function putItem
      
      */
     
     
     T newItem; //New item variable
     
     cout << "Please enter the data for the new article." << endl;
     cout << "Key: ";
     getline(cin, newItem.Key);
     cout << "Author: ";
     getline(cin, newItem.Author);
     cout << "Title: ";
     getline(cin, newItem.Title);
     
     bool found = false;
     getItem(newItem, found);
     
     if (found){ //If the item exists already, print error message and exit.
          
          cout << "Sorry, that item's key already exists." << endl;
          
          return false;
          
     }
     
     else { //Otherwise, insert it into the list.
          
          putItem(newItem);
          
          cout << "The following item was added to the list:" << endl;
          cout << newItem << endl;
          
          return true;
          
     }
     
}

#endif 
