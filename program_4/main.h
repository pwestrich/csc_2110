/*
 
 main.h
 by Philip Westrich
 for Assignment #4
 "Zipcode Database"
 CSC 2110-002
 Wednesday, April 17, 2013
 
 Description:
 This is the mheader file for the main driver. It contains all things
 that need to be included for the program to work.
 
 */

#ifndef MAIN_H
#define MAIN_H

#ifndef IOSTREAM
#define IOSTREAM
#include <iostream>      //For console in/out
#include <iomanip>
#endif

#ifndef STRING
#define STRING
#include <string>        //For C-strings
#endif

#ifndef FSTREAM
#define FSTREAM
#include <fstream>       //For file I/O
#endif

#ifndef STDLIB
#define STDLIB
#include <cstdlib>       //For good measure
#endif

#include "Node.h"
#include "BinaryTree.h"  //BinaryTree class

#endif
