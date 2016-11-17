/*--- sortdriver2.cpp ------------------------------------------------
  Program for timing various sorting algorithms.
 
  Lab #13
                                                          
  Add your name here and other info requested by your instructor.

 ---------------------------------------------------------------------*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#include "SortLibrary.h"
#include "Timer.h"

int main()
{
   const char SORTMENU[] =
     "0  TO STOP\n"
     "1  Bubble sort\n"
     "2  Insertion sort\n"
     "3  Quicksort\n"
     "4  STL's sort\n";

   const string SORTNAME[] = {"Bubble", "Insertion ", "Quick", "STL's "};

   string fileName;
   cout << "Enter name of file to sort: ";
   cin >> fileName;
  
   ifstream inFile;
   inFile.open(fileName.data());
   if (!inFile.is_open())
   {
      cerr << "\nError: Unable to open the file " << fileName << endl;
      exit(1);
   }

   // Read vector orig with values from inFile
   vector<string> orig;
   string str;
   for (;;)
   {
      inFile >> str;
      if (inFile.eof()) break;
      orig.push_back(str);
   }

   cout << "We will be sorting a list of " << orig.size() << " strings\n\n"
           "Here are the sorting methods available:\n" << SORTMENU << endl;

   int method;
   for (;;)
   {
      cout << "\nEnter number of sorting scheme to use: ";
      cin >> method;
      if (method == 0) break;

      // Reset vector x back to original
      vector<string> x = orig;

      // Perform the sort and time it
      Timer t;
      switch (method)
      {
         case 1: t.start(); bubbleSort(x); t.stop();
                 break;
         case 2: t.start(); insertionSort(x); t.stop();
                 break;
         case 3: t.start(); qSort(x); t.stop();
                 break;
         case 4: t.start(); sort(x.begin(), x.end()); t.stop();
                 break;
         default:
                 cerr << "*** Bad sorting method " << method << endl;
      }

      // Display the time.
      cout << "*** " << SORTNAME[method-1] << "sort took: "
           << t.seconds() << " seconds." << endl;
   }
}
