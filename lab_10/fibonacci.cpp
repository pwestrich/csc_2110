/*--- fibonacci.cpp --------------------------------------------------------
   Program to compute the Fibonacci function both
   iteratively and recursively.

   Input:  a positive integer x
   Output: the x-th Fibonacci number

  Written by:   Larry R. Nyhoff
                 
  Add your name here and other info requested by your instructor.

  -------------------------------------------------------------------------*/
#include <cstdlib>
#include <iostream>
#include "Timer.h"

using namespace std;


unsigned iterFibonacci(unsigned n);
/*---------------------------------------------------------
   An iterative (nonrecursive) Fibonacci number calculator
  
   Precondition:  n >= 1.
   Postcondition: n-th Fibonacci number is returned.
 ------------------------------------------------------------*/

unsigned recFibonacci(unsigned n);
/*---------------------------------------------------------
   A recursive) Fibonacci number calculator
  
   Precondition:  n >= 1.
   Postcondition: n-th Fibonacci number is returned.
 ------------------------------------------------------------*/

int main()
{
   unsigned x;

   cout << "Please enter a positive integer: ";
   cin >> x;
     
     Timer recTimer, iterativeTimer;
  
   // Now print the result of the iterative version of the function
     iterativeTimer.start();
     cout << "Iterative fib(" << x << ") = " << iterFibonacci(x) << endl;
     iterativeTimer.stop();
     cout << "Time taken: ";
     iterativeTimer.print(cout);
     cout << endl;

   // Now print the result of the recursive version of the function
     recTimer.start();
     cout << "Recursive fib(" << x << ") = " << recFibonacci(x) << endl;
     recTimer.stop();
     cout << "Time taken: ";
     recTimer.print(cout);
     cout << endl;
}


//--- Definition of iterFibonacci()
unsigned iterFibonacci(unsigned n)
{
   int
      nextFib = 1,        // the next Fibonacci number to be calculated
      previousFib = 1,    // the Fibonacci number before it
      beforePreviousFib;  // the Fibonacci number before that one

   for (int i = 3; i <= n; i++)
   {
      // First, update the previous and before previous values
      beforePreviousFib = previousFib;
      previousFib = nextFib;

      // Then compute the next Fibonacci value
      nextFib = previousFib + beforePreviousFib;
   }

   return nextFib;
}


//--- Definition of recFibonacci()
unsigned recFibonacci(unsigned n) {
  // Add statements for RecFibonacci() here
     
     if ((n == 1) || (n == 2)){
          
          return 1;
          
     }
     
     else if (n > 2){
          
          return ( recFibonacci(n-2) + recFibonacci(n - 1));
          
     }
     
     else {
          
          cout << "Bad number!" << endl;
          cout << "Exiting..." << endl;
          exit (1);
          
     }
     
}
