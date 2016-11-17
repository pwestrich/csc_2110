/*
 
 Node.h
 by Philip Westrich
 for CSC 2110-002, Assignment #2
 Friday, March 9, 2013
 
 Description:
     This is the definition for the nodes we'll be using in the list, as well
     as operator overloading stuff.
 
 */

#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <string>

using namespace std;

struct Node{
     
     string Key;
     string Author;
     string Title;
     
     Node* next;
     
};

ostream& operator<< (ostream& out, const Node& item){
     
     out << "--------------------------------------------------------------------------------" << endl;
     out << "Key: "           << item.Key                                                      << endl;
     out << "Author: "        << item.Author                                                   << endl;
     out << "Title: "         << item.Title                                                    << endl;
     out << "--------------------------------------------------------------------------------" << endl;
     
     return out;
     
}

#endif 
