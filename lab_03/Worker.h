//Worker.h
//by Philip Westrich and
//CSC 2111-002
//Lab #3

#ifndef _Worker_h
#define _Worker_h

#include <iostream>
#include <string>

using namespace std;

class Worker {
     
public:
     void displayWorker();
     void setValue(string name, double wage, double hours);
     double getPay();
     
private:
     string workerName;
     double workerRate;
     double workerHours;
     
};

#endif
