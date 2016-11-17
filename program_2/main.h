/*
 main.h
 by Philip Westrich
 for CSC 2110-002, Program #2
 Friday, March 8, 2013
 
 Description:
     This is the header file for the program's main driver.
     Included here are any definitions needed for it.
 
 */

#ifndef MAIN_H
#define MAIN_H

#include <iostream>
#include <string>
#include <fstream>

#include "Node.h" 
#include "LinkedList.h"
     
int readFile(LinkedList<Node>& list);

#endif 
