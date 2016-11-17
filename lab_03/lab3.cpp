#include <iostream>
#include <fstream>
using namespace std;
#include "Worker.h"

int main(){
     
     ifstream infile;
     int records;

     // declare required variables here.
     string nameBuffer;
     double wageBuffer = 0,
            hoursBuffer = 0;
     Worker workers[8];
     
     
     // Open data file
     infile.open("employee.txt");
     
     if (infile.fail()){
          
          cout<<"The file failed to open.\n\n";
          exit(1);
          
     }
   
     // Using a loop, create a worker object, read data from the file,
     // initialize object with the data, and store the object in the
     // array.
     
     for (int i = 0; i < 8; i++){
          
          infile >> nameBuffer;
          infile >> wageBuffer;
          infile >> hoursBuffer;
          
          workers[i].setValue(nameBuffer, wageBuffer, hoursBuffer);
          
     }
     

     // Using another loop, traverse through the array objects created
     // and display each object.
     
     for (int i = 0; i < 8; i++){
          
          workers[i].displayWorker();
          cout << endl;
          
     }
     
     return 0;
     
}
