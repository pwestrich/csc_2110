/*
 
 BinaryTree.h
 by Philip Westrich
 for Assignment #4
 "Zipcode Database"
 CSC 2110-002
 Wednesday, April 17, 2013
 
 Description:
 This is the definition and implementation for the templated BinaryTree class.
 
 */

#ifndef BINARYTREE
#define BINARYTREE

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

template <class T>
class BinaryTree{
     
public:
     
     BinaryTree();                           //Default constructor
     ~BinaryTree();                          //Default deconstructor
     
     bool isEmpty();                         //Returns if the tree is empty or not
     bool isFull();                          //Returns if the tree is full or not
     bool insertItem(T* newItem);            //Insert new item
     bool removeItem(string keyToSearch);    //Deletes item with matching key
     
     int getLength();                        //Returns total number of items in tree
     
     T* getItem(string keyToSearch);
     
     void deleteTree();                      //Makes the tree empty
     void printTree();                       //Prints the tree
     
     
private:
          
     bool recursivePutItem(T* &tree, T* newItem);           //Recursive insert function
     bool recursiveDelete(T* &tree, string keyToSearch);    //Functions for deleting items
     bool deleteNode(T* &tree);                             //Deletes a node once found
     
     void print(T* tree);                                   //Recursive print function
     void destroy(T* tree);                                 //Recursive function to destroy tree
     
     T* findItem(T* tree, string keyToSearch);              //Recursive search function
     NodeInfo getReplacement(T* tree);                      //Finds logical replacement for a deleted node
     
     T* root;       //Pointer to root of tree
     int length;    //length counter
     
};

//Public member functions:

template <class T>
BinaryTree<T>::BinaryTree(){
     /*
      Pre:     Object is declared
      Post:    Object is initialized to the empty state
      */
     
     root = NULL;
     length = 0;
     
}

template <class T>
BinaryTree<T>::~BinaryTree(){
     /*
      Pre:     Object leaves scope
      Post:    Calls recursive function destroy
               All memory is deallocated
      */
     
     destroy(root);
     
}

template <class T>
bool BinaryTree<T>::isEmpty(){
     /*
      Pre:     Object exists
      Post:    Returns if tree is empty or not
      */
     return (root == NULL);
     
}

template <class T>
bool BinaryTree<T>::isFull(){
     /*
      Pre:     Object exists
      Post:    Tests for enough memory to make a new T
               Returns true for yes, false for no
      */
     
     try { //Try to create a new item
          
          T* test = new T;
          delete test;
          
          return false;       //Return false if no exception is thrown
          
     }
     
     catch (bad_alloc& ba){ //Catch the bad_alloc and print, if thrown
          
          cerr << "Warning! Bad allocation exception caught: " << ba.what() << endl;
          cerr << "Tree is full!" << endl;
          return true;   //Return true for full list
          
     }
     
}

template <class T>
bool BinaryTree<T>::insertItem(T* newItem){
     /*
      Pre:     None
      Post:    Checks for room to insert a new item
               Calls function recursivePutItem() if yes
               Returns false if no.
               putItem() will return success status of operation
      */
     
     if (isFull()){
          
          return false;
          
     }
     
     else return recursivePutItem(root, newItem);
     
}

template <class T>
bool BinaryTree<T>::removeItem(string keyToSearch){
     /*
      Pre:     Tree has at least one item
      Post:    Returns false if no items to remove
               Otherwise, callse recursive function Delete()
               Delete() will return success status of operation
      */
     
     if (isEmpty()){
          
          return false;
          
     }
     
     else return recursiveDelete(root, keyToSearch);
          
}

template <class T>
int BinaryTree<T>::getLength(){
     /*
      Pre:     None
      Post:    Returns integer length
      */
     
     return length;
     
}

template <class T>
T* BinaryTree<T>::getItem(string keyToSearch){
     /*
      Pre:     None
      Post:    Calls recursive function findItem()
               findItem() will return NULL if item with matching key is not found
               Otherwise returns address of found item
      */
     
     return findItem(root, keyToSearch);
     
}

template <class T>
void BinaryTree<T>::deleteTree(){
     /*
      Pre:     None
      Post:    Calls recursive function destroy()
               Deallocates all memory
               Initalizes tree to the empty state
      */
     
     destroy(root);
     root = NULL;
     length = 0;
     
}

template <class T>
void BinaryTree<T>::printTree(){
     /*
      Pre:     None
      Post:    Prints the tree
               If no items are in the tree, displays such
               Otherwise, calls recursive function print()
      */
     
     if (isEmpty()){
          
          cout << "Database is empty." << endl;
          cout << "Zero items were printed." << endl;
          
     }
     
     else {
     
          cout << setw(8)     << "Zip Code"
               << setw(24)    << "City/Region"
               << setw(8)     << "State"                              << endl;
          cout << "----------------------------------------"          << endl;
     
          print(root);
     
          cout << "----------------------------------------"          << endl;
          cout << "A total of " << length << " items were printed."   << endl;
          
     }
     
}

//Private member functions:

template <class T>
void BinaryTree<T>::destroy(T* tree){
     /*
      Pre:     None
      Post:    Destroys the tree, deallocates all memory
      */
     
     if (tree != NULL){ 
          
          destroy(tree->left);     //Destroy left subtree
          destroy(tree->right);    //Destroy right subtree
          delete tree;             //Destroy tree
          length--;                //Decrement length
          
     }
     
}

template <class T>
bool BinaryTree<T>::recursiveDelete(T* &tree, string keyToSearch){
     /*
      Pre:     None
      Post:    Finds node with matching key
               Calls function deleteNode() on that node
      */
     
     if (tree == NULL){ //If tree is NULL, return false for failure
          
          return false;
          
     }
     
     else if (keyToSearch == tree->data.Key){ //If match is found, send tree to deleteNode()
          
          deleteNode(tree);
          return true;
          
     }
     
     else if (keyToSearch < tree->data.Key){ //if key is less, call on left subtree
          
          return recursiveDelete(tree->left, keyToSearch);
          
     }
     
     //Else look in the right subtree
     else return recursiveDelete(tree->right, keyToSearch);
     
}

template <class T>
bool BinaryTree<T>::deleteNode(T* &tree){
     /*
      Pre:     None
      Post:    Deletes the node tree
               Calls function getReplacement() to find the logical
                replacement if needed
      */
     
     T* itemToDelete = tree;
     
     if (tree->left == NULL){
          
          tree = tree->right;
          delete itemToDelete;
          length--;
          return true;
          
     }
     
     else if (tree->right == NULL){
          
          tree = tree->left;
          delete itemToDelete;
          length--;
          return true;
          
     }
     
     else {
          
          //Get data to replace the data to be deleted, and replace it
          tree->data = getReplacement(tree->right);
                              
          //Delete the duplicate data in the right subtree
          return recursiveDelete(itemToDelete->right, itemToDelete->data.Key);
                    
     }
     
}

template <class T>
NodeInfo BinaryTree<T>::getReplacement(T* tree){
     /*
      Pre:     None
      Post:    Finds logical replacement for a node when 
                deleted from the middle of the tree.
               Will find leftmost node in the given tree and return its data.
      */
               
     while (tree->left != NULL){ //Advance until to as far right as possible
          
          tree = tree->left;
          
     }
          
     return tree->data;         //return refernce to replacement
     
}

template <class T>
void BinaryTree<T>::print(T* tree){
     /*
      Pre:     None
      Post:    Prints the entire tree
      */
     
     if (tree != NULL){
          
          print(tree->left);       //Print left subtree
          
          cout << (*tree);         //Print root
          
          print(tree->right);      //Print right subtree
          
     }
     
}

template <class T>
bool BinaryTree<T>::recursivePutItem(T* &tree, T* newItem){
     /*
      Pre:     None
      Post:    Inserts newItem into tree
      */
     
     if (tree == NULL){ //If current tree is NULL, insertion point found
                    
          tree = newItem;
          length++;
          return true;
          
     }
     
     else if (tree->data.Key > newItem->data.Key){
                    
          return recursivePutItem(tree->left, newItem);
          
     }
     
     else return recursivePutItem(tree->right, newItem);
     
}

template <class T>
T* BinaryTree<T>::findItem(T* tree, string keyToSearch){ 
     /*
      Pre:     None
      Post:    Finds the item with matching key
               Returns NULL if tree is empty
               Returns a reference to that item if found
               Otherwise returns NULL
      */
     
     if (isEmpty()){ //Return NULL for empty tree
          
          return NULL;
          
     }
     
     else if (tree == NULL){ //Return NULL for not found
          
          return NULL;
          
     }
     
     else if (tree->data.Key > keyToSearch){ //If key is less, search in left subtree
          
          return (findItem(tree->left, keyToSearch));
          
     }
     
     else if (tree->data.Key < keyToSearch){ //If key is greater, look in right subtree
          
          return (findItem(tree->right, keyToSearch));
          
     }
     
     else if (tree->data.Key == keyToSearch){ //If key is equal, return reference to tree
          
          return tree;
          
     }
     
     else return NULL; //else return NULL for not found
     
}

#endif
