// -------------------------------------------------------
//
// lab1.cpp 
//
// Program to read a 3 X 3 matrix of integers mat and an integer item, and 
// search mat to see if it contains item. 
//
// Add your name here and other info requested by your instructor. 
//
// -------------------------------------------------------

#include <iostream>

const int SIZE = 3; // Set Matrix size 
typedef int Matrix[SIZE][SIZE]; 

bool matrixSearch(Matrix &mat, int n, int item); 

// -------------------------------------------------------
// Search the n X n matrix mat in row-wise order for item.
//
// Precondition: 
// Matrix mat is an n X n matrix of integers with n > 0. 
// Postcondition: 
// True is returned if item is found in mat, else false. 
// -------------------------------------------------------
int main() 
{
   Matrix mat;

   // Enter the matrix Matrix mat;
   std::cout << "Enter the elements of the " << SIZE << " X " << 
        SIZE << " matrix row-wise:" << std::endl; 

   for (int i = 0; i < SIZE; i++)
      for (int j = 0; j < SIZE; j++) 
         std::cin >> mat[i][j]; 

   // Search mat for various items mt itemToFind; 
   char response;
   int itemToFind;
  
   do {
      std::cout << "Enter integer to search for: ";
      std::cin >> itemToFind; 
      if (matrixSearch(mat, SIZE, itemToFind))
         std::cout << "item found" << std::endl; 
      else
         std::cout << "item not found" << std::endl; 
      std::cout << std::endl << "More items to search for (Y or N)? "; 
      std::cin >> response; 
   } while (response == 'Y' || response == 'y');
}

//-- (-- Incorrect --) Definition of matrixSearch() 
// -------------------------------------------------------
// Search the n X n matrix mat in row-wise order for item 
//
// Precondition: 
// Matrix mat is an n X n matrix of integers with n > 0. 
//
// Postcondition: 
// True is returned if item is found in mat, else false.
//
// NOTE: 
// mat[row] [col] denotes the entry of the matrix in the 
// (horizontal) row numbered row (counting from 0) and the 
// (vertical) column numbered col. 
// --------------------------------------------------------
bool matrixSearch(Matrix & mat, int n, int item) 
{
	bool found = false;
	for (int row = 0; row < n; row++){
		for (int col = 0; col < n; col++) {
			if (mat[row][col] == item) {
				found = true; 
               }
          }
     }
	return found;
}