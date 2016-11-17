/*----- lab12.cpp ----------------------------
  Program for testing class BST.
  ------------------------------------------------*/

#include <iostream>
using namespace std;

#include "BST.h"

int main()
{
  // Testing Constructor and empty()
  BST intBST;            // test the class constructor
  cout << "Constructing empty BST\n";
  
  // Testing inorder
  cout << "Inorder Traversal of BST: \n";
  intBST.inorder(cout);

  /**PART1******/
  // Testing insert
  cout << "\nNow insert a bunch of integers into the BST."
          "\nTry items not in the BST and some that are in it:\n";
  int number;

  for (;;)
  {
    cout << "Item to insert (-999 to stop): ";
    cin >> number;
    if (number == -999) break;
    intBST.insert(number);
  }
  
  cout << "Inorder Traversal of BST: \n";
  intBST.inorder(cout);

  cout << endl;
  //********/

  /**PART2******/
// Testing search()
  cout << "\n\nNow testing the search() operation."
          "\nTry both items in the BST and some not in it:\n";
  for (;;)
  {
    cout << "Item to search (-999 to stop): ";
    cin >> number;
    if (number == -999) break;
    cout << (intBST.search(number) ? "Found" : "Not found") << endl;
  }
//******/
}
