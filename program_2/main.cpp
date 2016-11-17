/*
 main.cpp
 by Philip Westrich
 for CSC 2110-002, Program #2
 
 Description:
     This is the main driver for the program.
 
 */

#include "main.h"

using namespace std;

int main(){
     
     LinkedList<Node>list;         //The list.
     char choice = '\0';           //Variable for user input
     
     cout << "Welcome to the Communications of the ACM Library!" << endl;
     
     if ( -1 == readFile(list)){ //If the file cannot be read, display error message and quit.
          
          cout << "I'm sorry, that file is invalid." << endl;
          cout << "Please check both the filename and its contents, and try again." << endl;
          
          return 0;
          
     }
     
     
     while (choice != '5'){
          
          //Print menu, promt for input
          
          cout << "What would you like to do?"    << endl;
          cout                                    << endl;
          cout << "1) Find an article"            << endl;
          cout << "2) List every article"         << endl;
          cout << "3) Add a new article"          << endl;
          cout << "4) Remove an existing article" << endl;
          cout << "5) Exit"                       << endl;
          cout                                    << endl;
          cout << "Your choice: ";
          cin.get(choice);
          cin.ignore(1000, '\n');
          
          if (choice == '1'){
               
               Node newNode;  //Node for searching purposes
               bool found;    //bool for searching purposes
               
               cout << "Please enter the key to search for: ";
               getline(cin, newNode.Key);
               
               list.getItem(newNode, found); //Try to find the item
               
               if (found){    //If found, print it.
                    
                    cout << "Article matching your search:" << endl;
                    cout << newNode;
                    
               }
               
               else {    //Otherwise, error message
                    
                    cout << "Sorry, no articles were found matching your query." << endl;
                    
               }
               
          }
          
          else if (choice == '2'){ //Display the list
               
               list.displayList();
               
          }
          
          else if (choice == '3'){ //Get a new item
               
               list.getNewItem();
                              
          }
          
          else if (choice == '4'){ //Delete item
               
               Node itemToDelete;  //Variable for finding the node to delete
               
               cout << "Please enter the key for the item you wish to delete: ";
               getline(cin, itemToDelete.Key);
                              
               if (list.deleteItem(itemToDelete)){     //Try to delete the item
                    
                    cout << "Item deleted successfully!" << endl;
                    
               }
               
               else {
                    
                    cout << "Sorry, the item was not found." << endl;
                    
               }
               
          }
                    
     }
     
     cout << "Exiting..." << endl;
     
     return 0;
     
}

int readFile(LinkedList<Node>& list){
     /*
      Pre:     A LinkedList object has been created and initilized
               A valid filename was given
      
      Post:    If a valid filename was not given, the function will return -1.
      
               If a valid filename was given, the function will read all data
               from the list, place it into the object given, and return the
               total number of succesful items read.
      */
     
     
     
     int length = 0;               //Length counter
     Node newNode;                 //New node to be inserted
     newNode.next = NULL;
     
     ifstream inFile("cacmpubs.txt"); //Open the file
     
     if (!inFile){ //If it fails, return -1 to signal such.
          
          return -1;
          
     }
     
     else {
          
          cout << "Loading library, please wait..." << endl;
          
     }
     
     getline(inFile, newNode.Key); //Try to get first line, so the eof flag checking works
     
     while (!inFile.eof()){ //While we aren't at the end of the file, let's read more and add to the list.
          
          //Get next two lines
          getline(inFile, newNode.Author);
          getline(inFile, newNode.Title);
          
          list.putItem(newNode);   //Put the new item into the list
          length++;                //Increment length.
                    
          getline(inFile, newNode.Key); //Try to read the next key. If it fails, the eof flag will be set.
          
     }
     
     inFile.close(); //Close the file.
     
     cout << length << " items were read successfully!" << endl; //Print number of items read
     
     return length;
     
}
