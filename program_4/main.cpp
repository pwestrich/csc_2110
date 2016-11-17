/*
 
 main.cpp
 by Philip Westrich
 for Assignment #4
 "Zipcode Database"
 CSC 2110-002
 Wednesday, April 17, 2013
 
 Description:
 This is the main driver for the program. It will read the database
 from the given input file, put it into the binary tree
 */

#include "main.h"

using namespace std;

void readFile(ifstream& infile, BinaryTree<Node> &tree);

int main(int argc, char* argv[]){
     
     if (argc < 2){ //Check if arguments were given
          
          cout << "No input file specified. Pleast try again." << endl;
          exit(EXIT_FAILURE);
          
     }
     
     ifstream infile(argv[1]);
     
     if (!infile){  //Check if file was opened successfully
          
          cout << "File " << argv[1] << " not found." << endl;
          exit (EXIT_FAILURE);
          
     }
     
     cout << endl;
     cout << "Welcome to the Zipcode Library!" << endl;
     cout << "This is a database of zip codes and their city." << endl;
     cout << endl;
     cout << "Loading library... Please wait..." << endl;
     
     BinaryTree<Node> tree;   //The tree
     
     readFile(infile, tree);  //Read data from file
     
     cout << "Done! " << tree.getLength() << " items read successfully!" << endl;
     cout << endl;
     
     //Variables for input
     char input = '\0';
     string search = "\0";
     Node* inputNode = NULL;
     
     while (true){
          
          cout << "Menu"                     << endl;
          cout << "--------------------"     << endl;
          cout << "(F)ind a zip code"        << endl;
          cout << "(L)ist all zip codes"     << endl;
          cout << "(A)dd a new zip code"     << endl;
          cout << "(R)emove a zip code"      << endl;
          cout << "(E)xit"                   << endl;
          cout << endl;
          cout << "Your choice (F, L, A, R, or E): ";
          cin >> input;
          cin.ignore(1000, '\n');
          cout << endl;
          
          if (input == 'F'){ //Find a zip code
               
               cout << "Please enter a 5-digit zip code to search by: ";
               getline(cin, search, '\n');
               
               if (search.size() != 5){ //If not 5 digits, display error message
                    
                    cout << "Sorry, that zip code is invalid." << endl;
                    cout << endl;
                    
               }
               
               else { //Otherwise, start searching
               
                    inputNode = tree.getItem(search);
               
                    if (inputNode == NULL){ //If not found, display error message
     
                         cout << "Sorry, the zip code " << search << " was not found." << endl;
                         cout << endl;
     
                    }
                    
                    else { //Otherwise, display the found item
                         
                         cout << "The following item was found in the database:" << endl;
                         cout << setw(8)     << "Zip Code"
                              << setw(24)    << "City/Region"
                              << setw(8)     << "State"
                              << endl;
                         cout << "----------------------------------------" << endl;
                         cout << (*inputNode);
                         cout << "----------------------------------------" << endl;
                         cout << endl;
                         
                    }
                    
               }
                    
          }

          else if (input == 'L'){ //Print the entire tree
               
               tree.printTree();
               cout << endl;
                              
          }
          
          else if (input == 'A'){ //Add an item
               
               cout << "Please enter the data to be added:" << endl;
               cout << "Zip code (5 digits): ";
               getline(cin, search, '\n');   //Prompt for zipcode
               
               if (search.size() != 5){ //If wrong size, display error message
                    
                    cout << "Sorry, that zip code is invalid." << endl;
                    cout << endl;
                    
               }
               
               else { //Otherwise, search for it.
               
                    inputNode = tree.getItem(search);
               
                    if (inputNode != NULL){ //If already exists, display error message
                    
                         cout << "Sorry, the zip code " << search << " already exists." << endl;
                         cout << endl;
                    
                    }
               
                    else { //Otherwise, promt for other two pices of data
                         
                         inputNode = new Node;
                         inputNode->data.Key = search;
                    
                         cout << "City/Region: ";
                         getline(cin, inputNode->data.City, '\n');
                    
                         cout << "State: ";
                         getline(cin, inputNode->data.State, '\n');
                         cout << endl;
                    
                         if (tree.insertItem(inputNode)){ //and insert it
                         
                              cout << "The following item was added to the database:" << endl;
                              cout << setw(8)     << "Zip Code"
                                   << setw(24)    << "City/Region"
                                   << setw(8)     << "State"
                                   << endl;
                              cout << "----------------------------------------" << endl;
                              cout << (*inputNode);
                              cout << "----------------------------------------" << endl;
                              cout << endl;
                         
                         }
                    
                         else { //If failure, display error message
                         
                              cerr << "Error adding item to database!" << endl;
                              cerr << endl;
                         
                         }
                         
                    }
                    
               }
               
          }
          
          else if (input == 'R'){ //Remove item
               
               cout << "Enter a zip code to search for: ";
               getline(cin, search, '\n'); //Prompt for zip code
               
               if (search.size() != 5){ //If wrong size, display error message
                    
                    cout << "Sorry, that zip code is invalid." << endl;
                    cout << endl;
                    
               }
               
               else { //Otherwise, search for it
               
                    inputNode = tree.getItem(search);
               
                    if (inputNode == NULL){ //If not found, display error message
                    
                         cout << "Sorry, the zip code " << search << " was not found." << endl;
                         cout << endl;
                    
                    }
               
                    else { //Otherwise, display item found, and ask for conformation
                    
                         cout << "The following entry was found:" << endl;
                         cout << (*inputNode);
                         cout << "Do you wish to delete the above item? " << endl;
                         cout << "(Y/N): ";
                         cin >> input;
                         cin.ignore(1000, '\n');
                    
                         if ((input == 'Y') || (input == 'y')){
                         
                              if (tree.removeItem(search)){ //If yes, remove item
                              
                                   cout << "Item deleted successfully!" << endl;
                                   cout << endl;
                              
                              }
                         
                              else { //Display error message if failure
                              
                                   cerr << "Error deleting item!" << endl;
                                   cerr << endl;
                              
                              }
                         
                         }
                    
                         else { //Otherwise, say item wasn't deleted
                         
                              cout << "Item not removed." << endl;
                              cout << endl;
                         
                         }
                         
                    }
                    
               }
               
          }
          
          else if (input == 'E'){ //Exit
               
               break;
               
          }
          
          else { //Wrong choice error message
               
               cout << "Sorry, that is not a valid choice." << endl;
               cout << endl;
               
          }
          
     }
     
     cout << "Exiting..." << endl;
     cout << endl;
     
     return 0;
     
}

void readFile(ifstream& infile, BinaryTree<Node> &tree){
     
     string keyBuffer, stateBuffer, cityBuffer;
     
     getline(infile, keyBuffer, '\n'); //Prime eof()
     
     while (!infile.eof()){ //While not at end of file, keep reading
          
          getline(infile, cityBuffer, '\n');
          getline(infile, stateBuffer, '\n');
          
          tree.insertItem(new Node(keyBuffer, cityBuffer, stateBuffer)); //Insert item into tree
          
          getline(infile, keyBuffer, '\n'); //Prime eof flag again
          
     }
     
}
