/*--- lab5.cpp --------------------------------------------------
  A program for testing class LinkedList.
 
  Example provided by:   Larry R. Nyhoff
  
  Add your names here.

  ---------------------------------------------------------------------*/

#include <iostream>

using namespace std;

#include "LinkedList.h"

int main()
{
  LinkedList  intList;       // TEST THE CONSTRUCTOR
   cout << "Constructing intList...\n";

/*
// ---- PART 1 ---- TEST SIZE OPERATION
   cout << "Size of intList is " << intList.getSize() << endl;
//---- END PART 1 ----
*/

/*
// ---- PART 2 ---- TEST OUTPUT OF EMPTY LIST 
   cout << "Empty List: \n";
   intList.displayList();
   cout << endl; 
//---- END PART 2 ----
*/

///*
// ---- PART 3 ---- TEST INSERT OPERATION
   for (int i = 0; i < 9; i++)
   {
      intList.insertItem(10 * i);
      cout << "List after insertion: ";
        intList.displayList();
        cout << endl;            // test output
   }


}
