//Worker.cpp
//Lab #3
//
//Implementation of the Worker class

using namespace std;

#include "Worker.h"

void Worker::setValue(string newName, double newRate, double newHours){
     
     workerName = newName;
     workerRate = newRate;
     workerHours = newHours;
     
}

double Worker::getPay(){
     
     return (workerRate * workerHours);
     
}

void Worker::displayWorker(){
     
     cout << "Name: "                   << workerName  << endl;
     cout << "Rate: "                   << workerRate  << endl;
     cout << "Hours this week: "        << workerHours << endl;
     cout << "Total pay this week: "    << getPay()    << endl;
     
}
