#include <iostream>
#include <sstream>

using namespace std;

#include "Stack.h"

int main() 
{
   string line;
   getline(cin, line);
     
     int num1 = 0, num2 = 0;
     Stack stack(10);

   // Create a string stream that will read from "line"
   stringstream ss(line,stringstream::in);
  
   // While there are more tokens...
   while (!ss.eof()) 
   {
      string token;
      ss >> token;
          
      //display token for testing
        
        cout << token << endl;

      // Put your code for evaluating the expression here!
        
        if ((token == "+") || (token == "-") || (token == "/") || (token == "*")){
             
             num1 = stack.top();
             stack.pop();
             num2 = stack.top();
             stack.pop();
             
             if (token == "+"){
                  
                  num1 += num2;
                  
                  stack.push(num1);

                  
             }
             
             else if (token == "-"){
                  
                  num2 -= num1;
                  
                  stack.push(num2);
                  
             }
             
             else if (token == "/"){
                  
                  num1 = (num2 / num1);
                  
                  stack.push(num1);
                  
             }
             
             else if (token == "*"){
                  
                  num1 = num1 * num2;
                  
                  stack.push(num1);

                  
             }
             
             stack.push(num1);
             
        }
        
        else if ((token != "+") && (token != "-") && (token != "/") && (token != "*")){
             
             stack.push(atoi(token.c_str()));
             
        }
        
        
 
   }; //end while

   // The should be one and only one item left on the stack
   // print the item at the top of the stack
     
     cout << "Your answer: " << stack.top() << endl;
   
   return 0;
}
