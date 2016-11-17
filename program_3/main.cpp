/*
 
 main.cpp
 by Philip Westrich
 for Assignment #3
 "Line Simulator"
 CSC 2110-002
 Wednesday, April 3, 2013
 
 Description:
     This is the main driver for the program. It will prompt the user for input,
     put it to work, and print the results.
 
*/

#include "main.h"

using namespace std;

int main(){
     
     int length = 0;               //Length of simulation
     int transactionTime = 0;      //Length of transaction time
     int numServers = 0;           //Number of servers
     int avgArrival = 0;           //Average time between jobs
          
     Q<Job> line;                  //The queue
     
     cout << "Welcome to the Line Simulator!"                                        << endl;
     cout << "This program will simulate how long it will take to serve a number "
          << "of customers using a single-queue, multi-server system."               << endl;
     cout << "Please enter the folowing values for the simulation:"                  << endl;
     
     do {
          
          cout << "Simulation length (between 0 and " << MAXLENGTH << "): ";
          cin >> length;
          
     } while ((length < 1) || (length > MAXLENGTH));

     do {
          
          cout << "Average transaction time (between " << MINTRANSACTION << " and " << MAXTRANSACTION << "): ";
          cin >> transactionTime;
          
     } while ((transactionTime < MINTRANSACTION) || (transactionTime > MAXTRANSACTION));
     
     do {
          
          cout << "Number of servers (between 0 and " << MAXSERVERS << "): ";
          cin >> numServers;
          
     } while ((numServers < 1) || (numServers > MAXSERVERS));
     
     do {
          
          cout << "Average time between arrivals (between 1 and " << MAXARRIVAL << "): ";
          cin >> avgArrival;
          
     } while ((avgArrival < 1 ) || (avgArrival > MAXARRIVAL));
     
     cin.ignore(1000, '\n');
     cout << endl;
     cout << "Running simulation... please wait..." << endl;
     cout << endl;
     
     Server servers[numServers]; //Create array of servers
     
     for (int i = 0; i < numServers; i++){ //Initialize the servers
          
          servers[i].initialize(transactionTime);
          
     }
     
     for (int time = 1; time <= length; time++){ //Loop through every minute
               
          if (time % avgArrival == 0){ //If it's an arrival time, add to line
                              
               line.NQ(new Job);
               
          }
          
          for (int i = 0; i < numServers; i++){   //Loop through each server
               
               if (servers[i].isAvalible() && !line.isEmpty()){
                    /*
                     If server is avalible, and there is someone in line, remove him from
                     the line and add the job to the servers
                     */
          
                    if (servers[i].addJob()) line.DQ();
                    
               }
               
          }
          
          //Increment server wait times as well as the line's
          for (int i = 0; i < numServers; i++) {
               
               if (!servers[i].isAvalible()) servers[i].incrementTimer();
               
          }
                         
          line.incrementWait();

     }
     
     //Now print results
     
     cout << "Done!"                                                            << endl;
     cout << "--------------------------------------------------------------"   << endl;
     cout << "Here are the parameters entered:"                                 << endl;
     cout << "Total length of simulation: "       << length                     << endl;
     cout << "Average transaction time: "         << transactionTime            << endl;
     cout << "Number of servers: "                << numServers                 << endl;
     cout << "Average time between arrivals: "    << avgArrival                 << endl;
     cout << "--------------------------------------------------------------"   << endl;
     cout << "Here are the results:"                                            << endl;
     cout << "Number of people served: "          << line.getTotalServed()      << endl;
     cout << "Average wait time: "                << showpoint
          << fixed << setprecision(2)             << line.getAverageWait()      << endl;
     cout << "Number still waiting in line: "     << line.getLength()           << endl;
     cout << "--------------------------------------------------------------"   << endl;

     return 0;

}
