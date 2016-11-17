/*--------------------------------------------------------------------
  sortdriver1.cpp is a program for testing various sorting algorithms.
 
  Lab #13
                                                          
  Add your name here and other info requested by your instructor.

 ---------------------------------------------------------------------*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#include "SortLibrary.h"


/*-- Output operator ---------------------------------------------
  Display the list stored in positions 1, 2, . . .  of a vector v.
 
  Precondition:  ElementType is a type parameter; ostream out
      is open.
  Postcondition: Elements of vector v have been output to out.
 ----------------------------------------------------------------*/

// Define a function template for operator<<() here

template <class ElementType>
ostream &operator<<(ostream &out, const vector<ElementType> &v){
     
     for (unsigned int i = 0; i < v.size(); i++){
          
          out << v[i] << endl;
          
     }
          
     return out;
     
}

int main()
{
   // Construct a vector of ints
   vector<int> intVecOrig,
               intVec;
   // Value in position [0] will be ignored -- use positions 1, 2, 3, ...

   intVecOrig.push_back(10);  intVecOrig.push_back(7); 
   intVecOrig.push_back(2);   intVecOrig.push_back(5);
   intVecOrig.push_back(11);

   // Construct a vector of strings
   vector<string> strVecOrig,
                 strVec;
   // Value in position [0] will be ignored -- use positions 1, 2, 3, ...

   strVecOrig.push_back("DO");  strVecOrig.push_back("RE"); 
   strVecOrig.push_back("MO");  strVecOrig.push_back("FA");
   strVecOrig.push_back("SO");  strVecOrig.push_back("LA"); 
   strVecOrig.push_back("TI"); 

/*
   // PART 1 -- BUBBLESORT
   cout << "BUBBLESORT:\n===========\n"
           "Unsorted list of integers:\n" << intVecOrig<< endl;
   intVec = intVecOrig;
   bubbleSort(intVec);
   cout << "Sorted list:\n" << intVec << endl;

   cout << "\nUnsorted list of strings:\n" << strVecOrig<< endl;
   strVec = strVecOrig;
   bubbleSort(strVec);
   cout << "Sorted list:\n" << strVec << endl;


   // PART 2 -- INSERTION SORT 
   cout << "\nINSERTION SORT\n==========\n"
           "Unsorted list of integers:\n" << intVecOrig<< endl;
   // Reset intVec to original list and sort it
   intVec = intVecOrig;
   insertionSort(intVec);
   cout << "Sorted list:\n" << intVec << endl;

   cout << "\nUnsorted list of strings:\n" << strVecOrig<< endl;
   // Reset strVec to original list and sort it
   strVec = strVecOrig;
   insertionSort(strVec);
   cout << "Sorted list:\n" << strVec << endl;

   //  END OF PART 2  
   */

   //*
   // PART 3 -- QUICK SORT 
   cout << "\nQUICKSORT\n==========\n"
           "Unsorted list of integers:\n" << intVecOrig<< endl;
   // Reset intVec to original list and sort it
   intVec = intVecOrig;
   qSort(intVec);
   cout << "Sorted list:\n" << intVec << endl;

   cout << "\nUnsorted list of strings:\n" << strVecOrig<< endl;
   // Reset strVec to original list and sort it
   strVec = strVecOrig;
   qSort(strVec);
   cout << "Sorted list:\n" << strVec << endl;

   //  END OF PART 3  
   
}
