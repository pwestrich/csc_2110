
#include <iostream>

bool isPrime(int n, int d);

using namespace std;

int main(){
          
     cout << "Testing numbers 1 - 200 for primes..." << endl;
     cout << "Numbers found: " << endl;
     
     for (int n = 1; n <= 200; n++){
                    
          if (isPrime(n, (n - 1))){
               
               cout << n << endl;
               
          }
          
     }
     
     cout << "Done!" << endl;
     
     return 0;
     
}

bool isPrime(int n, int d){
     
     if (n == 1){
          
          return false;
          
     }
     
     else if (d == 1){
          
          return true;
          
     }
     
     else if ((n % d) == 0){
          
          return false;
          
     }
     
     else {
          
          return isPrime(n, (n - 1));
          
     }
     
}
