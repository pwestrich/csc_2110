/*
 HeapSortMax.cpp
 by Philip Westrich
 for Assignment #5
 CSC 2110-002
 Friday, May 3, 2013
 
 Description:
     This program will take an integer argument. It will then create
     an array of random numbers between 1 and 100, inclusive. Next, 
     it will convert that array into a maximum heap, then print it 
     in ascending order.
*/

#include <iostream> //for cout, cerr, endl
#include <iomanip>  //for setw()
#include <cstdlib>  //for atoi(), srand(), rand()
#include <ctime>    //for time

using namespace std;

int comparisonCount = 0;

//Function prototypes
void heapSort(int array[], const int &size);
void printHeap(int array[], const int &size);
void reheapDown(int array[], const int &root, const int &bottom);
void reheapUp(int array[], const int &root, const int &bottom);
void Swap(int &left, int &right);

int main(int argc, const char* argv[]){

     if (argc < 2){ //Check for number of arguments
          
          cerr << "Error: Too few arguments." << endl;
          cerr << "Enter one integer argument above 0." << endl;
          cerr << "Exiting..." << endl;
          exit(EXIT_FAILURE);
          
     }
     
     //Convert string argument into an integer
     int size = atoi(argv[1]);
     
     if (size < 1){ //If negative, exit
          
          cerr << "Sorry, the argument must be greater than 1." << endl;
          cerr << "Also, be sure to enter an integer." << endl;
          cerr << "Exiting..." << endl;
          exit(EXIT_FAILURE);
          
     }
     
     //Seed the random number generator with the current time
     //time(NULL) returns a long int, must static_cast or the compiler might complain
     srand(static_cast<int>(time(NULL)));
     
     //Declare array of input size
     int array[size];
     
     //Initialize the array with random numbers
     cout << "Generating random numbers..." << endl;
     for (int i = 0; i < size; i++){
          
          array[i] = ((rand() % 100000000) + 1);
          
     }
     
     cout << "Unsorted array:" << endl;
     cout << "----------------" << endl;
     for (int i = 0; i < size; i++){
          
          cout << "Element #" << (i + 1) << ": " << array[i] << endl;
          
     }
     
     cout << "----------------" << endl;

     //Make the array into a maximum heap
     heapSort(array, size);
     
     //Print the heap
     cout << "Printing heap..." << endl;
     cout << "----------------" << endl;
     printHeap(array, size);
     cout << "----------------" << endl;
     cout << endl;
   
   cout << "Comparison count: " << comparisonCount << endl;
     cout << "Exiting..." << endl;
     
     return 0;
     
}

void heapSort(int array[], const int &size){
     
     //Make the array into a heap
     for (int i = ((size / 2) - 1); i >= 0; i--){
          
          reheapDown(array, i, size - 1);
          
     }
     
     //Sort the heap in ascending order
     for (int i = size - 1; i >= 1; i--){
          
          Swap(array[0], array[i]);
          reheapDown(array, 0, i - 1);
          
     }
     
}

void printHeap(int array[], const int &size){
     
     //Print each element
     for (int i = 0; i < size; i++){
          
          cout << "Element #"
               << setw(8) << (i + 1) << ": " << array[i] << endl;
          
     }
     
}

void reheapDown(int array[], const int &root, const int &bottom){
     
     int maxChild = -1;
     int leftChild = (root * 2) + 1;
     int rightChild = (root * 2) + 2;
     
     if (leftChild <= bottom){
        
        comparisonCount++;
          
          if (leftChild == bottom){
             
             comparisonCount++;
             
               maxChild = leftChild;
               
          }
          
          else {
               
               if (array[leftChild] <= array[rightChild]){
                  
                  comparisonCount++;
                    
                    maxChild = rightChild;
                    
               }
               
               else {
                    
                    maxChild = leftChild;
                    
               }
               
          }
          
          if ( array[root] < array[maxChild]){
             
             comparisonCount++;
               
               Swap(array[root], array[maxChild]);
               reheapDown(array, maxChild, bottom);
               
          }
          
     }
     
}

void reheapUp(int array[], const int &root, const int &bottom){
     
     int parent = -1;
     
     if (bottom > root){
        
        comparisonCount++;
          
          parent = (bottom - 1) / 2;
          
          if (array[parent] < array[bottom]){
             
             comparisonCount++;
               
               Swap(array[parent], array[bottom]);
               reheapUp(array, root, parent);
               
          }
          
     }
     
}

void Swap(int &left, int &right){
     
     //Simple function to swap two elements
     int temp = left;
     left = right;
     right = temp;
     
}
