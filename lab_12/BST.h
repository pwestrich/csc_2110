/* BST.h contains the declaration/definition of class BST.
   Basic operations:
     Constructor: Constructs an empty BST
     empty:       Checks if a BST is empty
     search:      Search a BST for an item
     insert:      Inserts a value into a BST
     inorder:     Inorder traversal of a BST -- output the data values
    Private utility helper operations:
     inorderAux:  Used by inorder
 --------------------------------------------------------------------------*/

#include <iostream>
using namespace std;
#ifndef BINARY_SEARCH_TREE
#define BINARY_SEARCH_TREE

typedef int DataType;
class BST
{
 
private:

	 /***** Node structure *****/
  	class Node 
  	{
   	public:
    		DataType data;
    		Node * left;
    		Node *  right;

    		Node(): left(0), right(0)
    		{}
    		Node(DataType item): data(item), left(0), right(0)
    		{}
  	};

  	typedef Node * NodePointer; 
	
	
public:
  	BST();
  	/*------------------------------------------------------------------------
    	Construct a BST object.

    	Precondition:  None.
    	Postcondition: An empty BST has been constructed.
   	-----------------------------------------------------------------------*/

  	bool empty() const;
  	/*------------------------------------------------------------------------
    	Check if BST is empty.

    	Precondition: None.
    	Postcondition: Returns true if BST is empty and false otherwise.
   	-----------------------------------------------------------------------*/

  	bool search(const DataType & item) const; 
  	/*------------------------------------------------------------------------
    	Search the BST for item.

    	Precondition:  None.
    	Postcondition: Returns true if item found, and false otherwise.
   	-----------------------------------------------------------------------*/

   	void insert(const DataType & item);
  	/*------------------------------------------------------------------------
    	Insert item into BST.

    	Precondition:  None.
    	Postcondition: BST has been modified with item inserted at proper 
        position to maintain BST property. 
  	------------------------------------------------------------------------*/
  	void inorder(ostream & out);
  	/*------------------------------------------------------------------------
    	Inorder traversal of BST.

    	Precondition:  ostream out is open.
    	Postcondition: BST has been inorder traversed and values in nodes 
        have been output to out.
    	Note: inorder uses private auxiliary function inorderAux().
 	------------------------------------------------------------------------*/

	 
private:
 
  	void inorderAux(ostream & out, NodePointer subtreePtr);
  	/*------------------------------------------------------------------------
    	Inorder traversal auxiliary function.

    	Precondition:  ostream out is open; subtreePtr points to a subtree of this BST.
    	Postcondition: Subtree of this BST with subtreePtr as root has been output to out.
 	------------------------------------------------------------------------*/

	/***** Data Members *****/
  	NodePointer myRoot; 

}; // end of class template declaration

//--- Definition of constructor
BST::BST(): myRoot(0)
{}

//--- Definition of empty()
bool BST::empty() const
{ 
	return myRoot == 0; 
}

//--- Definition of insert()
void BST::insert(const DataType & item)
{
	//insert code here
     
     bool found = false;
     NodePointer currentLocation = myRoot;
     NodePointer previousLocation = NULL;
     Node* newItem = new Node(item);
     newItem->left = newItem->right = NULL;
     
     while (!found && currentLocation != NULL){
          
          if (item < currentLocation->data){
               
               previousLocation = currentLocation;
               currentLocation = currentLocation->left;
               
          }
          
          else if (item > currentLocation->data){
               
               previousLocation = currentLocation;
               currentLocation = currentLocation->right;
               
          }
          
          else found = true;
          
     }
     
     if (previousLocation == NULL){
          
          myRoot = newItem;
          
     }
     
     else if (item < previousLocation->data){
          
          previousLocation->left = newItem;
          
     }
     
     else previousLocation->right = newItem;
     
     
}

//--- Definition of search()
bool BST::search(const DataType & item) const
{
	//insert code here
     
     NodePointer currentLocation = myRoot;
     NodePointer previousLocation = NULL;
     bool found = false;
     
     while (!found && currentLocation != NULL){
          
          if (item < currentLocation->data){
               
               previousLocation = currentLocation;
               currentLocation = currentLocation->left;
               
          }
          
          else if (item > currentLocation->data){
               
               previousLocation = currentLocation;
               currentLocation = currentLocation->right;
               
          }
          
          else found = true;
          
     }
     
     return found;
     
}


//--- Definition of inorder()
void BST::inorder(ostream & out)
{ 
   inorderAux(out, myRoot); 
}


//--- Definition of inorderAux()
void BST::inorderAux(ostream & out,  NodePointer subtreeRoot)
{
   if (subtreeRoot != 0)
   {
      inorderAux(out, subtreeRoot->left);    // L operation
      out << subtreeRoot->data << "  ";      // V operation
      inorderAux(out, subtreeRoot->right);   // R operation
   }
}

#endif 

