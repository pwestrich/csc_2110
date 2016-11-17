/*--- SortLibrary.h ------------------------------------------------
  This is a collection  of various sorting function templates.
 
  Lab #13
                                                          
  Add your name here and other info requested by your instructor.

--------------------------------------------------------------------*/

#include <string>
#include <vector>
#include <iostream>
using namespace std;

template <typename ElementType>
inline void interchange(ElementType & a, ElementType & b)
/*------------------------------------------------------------
   Precondition:  ElementType is a type parameter.
   Postcondition: Values of a and b have been interchanged.
 -------------------------------------------------------------*/
{
   ElementType temp = a;
   a = b;
   b = temp;
}

/*
//-- FIRST VERSION OF BUBBLE SORT -----------------------------
//   Precondition:  ElementType is a type parameter.
//   Postcondition: x has been sorted in ascending order.
//-------------------------------------------------------------
template <class ElementType>
void bubbleSort(vector<ElementType> & x)
{
   int numElements = x.size();
   for (int listEnd = numElements-1; listEnd > 0; listEnd--)
      for (int j = 0; j < listEnd; j++)
         if (x[j] > x[j+1])
            interchange(x[j], x[j+1]);
}*/


///*** SECOND VERSION OF BUBBLE SORT BEGINS HERE

//-- Second (improved) version -- ----------------------------
//   Precondition:  ElementType is a type parameter.
//   Postcondition: x has been sorted so its elements are in 
//       ascending order.
//------------------------------------------------------------
//*
template <class ElementType>
void bubbleSort(vector<ElementType> & x){
     
   int numCompares = x.size() - 1;
   //  The number of pairs to be compared on the current pass 

   while (numCompares != 0){
        
      int last = 0;  
      // The location of the last element involved in an interchange

        for (int i = 0; i < numCompares; i++){
         
             if (x[i] > x[i+1]){
                  
                  interchange(x[i], x[i+1]);
                  last = i+1;
                  
             }
             
         }
        
          numCompares = last;
        
     }
     
}
//*/
//*** SECOND VERSION OF BUBBLE SORT ENDS HERE ***/



//===================(insertion sort)====================

// Write Code here

template <class ElementType>
void insertionSort(vector<ElementType> &v){
     
     unsigned int j = 0;
     ElementType nextElement;
     
     for (unsigned int i = 1; i < v.size(); i++){
          
          nextElement = v[i];
          j = i;
          
          while ((j > 0) && (nextElement < v[j - 1])){
               
               v[j] = v[j-1];
               j--;
               
          }
          
          v[j] = nextElement;
          
     }
     
}

//-- FUNCTIONS USED BY QUICKSORT BEGIN HERE

/*--- split() -------------------------------------------------
   Rearranges x[first], ... , x[last] so that the pivot element
   is properly positioned at position pos.

   Precondition:  ElementType is a type parameter.
   Postcondition: Elements of x have been rearranged so that
       x[first], ..., x[pos-1} are all <= x[pos] and
       x[pos+1], ..., x[last]  are all > x[pos].
 --------------------------------------------------------------*/
template <class ElementType>
void split(vector<ElementType> & x,
           int first, int last, int & pos)
{
   ElementType pivot = x[first]; // pivot element
   int left = first,             // index for left search
       right = last;             // index for right search

   while (left < right)
   {
      // Search from right for element <= pivot
      while (x[right] > pivot)
         right--;
      // Search from left for element > pivot
      while (left < right && x[left] <= pivot)
         left++;
      // Interchange elements if searches haven't met
      if (left < right)
         interchange(x[left], x[right]);
   }
   // End of searches; place pivot in correct position
   pos = right;
   x[first] = x[pos];
   x[pos] = pivot;
}


/*-- quicksort() ---------------------------------------------
   Precondition:  ElementType is a type parameter.
   Postcondition: Elements of x have been rearranged so that
        x[first], ..., x[last] are in ascending order.
 -------------------------------------------------------------*/
template <class ElementType>
void quicksort(vector<ElementType> & x, int first, int last)
{
   int pos;          // final position of pivot
   if (first < last) // list has more than one element
   {
      // Split into two sublists
      split(x, first, last, pos);
      // Sort left sublist
      quicksort(x, first, pos - 1);
      // Sort right sublist
      quicksort(x, pos + 1, last);
   }
   // else list has 0 or 1 element and 
   // requires no sorting
}


/*-- Function template interface to quickSort() --------------
   Precondition:  ElementType is a type parameter.
   Postcondition: x has been sorted so its elements are in 
       ascending order.
 -------------------------------------------------------------*/
template <typename ElementType>
void qSort(vector<ElementType> & x)
{  
   quicksort(x, 0, x.size() - 1);  
}
