/*
 
 node.h
 by Philip Westrich
 for Assignment #4
 "Zipcode Database"
 CSC 2110-002
 Wednesday, April 17, 2013
 
 Description:
 This is the class definition for the nodes of the binary tree.
 Also contains the overload for operator<< for printing.
 
 */

#ifndef NODE_H
#define NODE_H

#ifndef STRING
#define STRING
#include <string>
#endif

using namespace std;

struct NodeInfo{
     
     string Key;
     string City;
     string State;
     
};

class Node{
     
public:
     
     Node();
     Node(string newKey, string newCity, string newState);
     
     NodeInfo data;
     
     Node* left;
     Node* right;
     
};

Node::Node(){
     
     data.Key = data.City = data.State = '\0';
     left = right = NULL;
     
}

Node::Node(string newKey, string newCity, string newState){
     
     data.Key = newKey;
     data.City = newCity;
     data.State = newState;
     
     left = right = NULL;
     
}

ostream& operator<< (ostream& out, Node item){
     
     out  << setw(8)     << item.data.Key
          << setw(24)    << item.data.City
          << setw(8)     << item.data.State
          << endl;
     
     return out;
     
}

#endif
