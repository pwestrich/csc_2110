#include <iostream> 

using namespace std;

unsigned long long int fact(int n);


int main() {
     
     int n = 0;
     
     cout << "Enter number:";
     cin >> n;
     
     if (n < 0){
          
          cerr << "Error: Positive integers only!" << endl;
          exit(1);
          
     }
     
     else if (n == 0) {
          
          cout << "0! is equal to 1" << endl;
          return 0;
     
     }
     
     else {
               
          cout << n << "! is equal to " << fact(n) << endl;
     }
     
     return 0;
     
}

unsigned long long int fact(int n){
     
     /*if (n == 1){
          
          cout << 1 << " = ";
          return 1;
          
     }
     
     else {*/
          
          cout << n << " * ";
          return (n * fact(n-1));
          
     //} 
     
}
