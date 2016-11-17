/*
 
 main.h
 by Philip Westrich
 for Assignment #3
 CSC 2110-002
 Wednesday, April 3, 2013
 
 Description:
     This file contains all #include's and #define's for
     the main to function properly
 
*/

#ifndef MAIN_H
#define MAIN_H

#ifndef IOSTREAM
#define IOSTREAM
//The standard iostream and iomanip
#include <iostream>
#include <iomanip>
#endif

#ifndef STDLIB
#define STDLIB
//#include cstdlib for good measure
#include <cstdlib>
#endif

//Constants for input validation
#define MAXSERVERS 10         //Max number of servers
#define MAXLENGTH 36000       //Max simulation length
#define MAXTRANSACTION 600    //Max transaction time
#define MINTRANSACTION 2      //Min transaction time
#define MAXARRIVAL 100        //Max arrival time

//Header files for the following classes
#include "Q.h"
#include "job.h"
#include "Server.h"

#endif
