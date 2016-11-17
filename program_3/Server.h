/*
 
 Server.h
 by Philip Westrich
 for Assignment #3
 "Line Simulator"
 CSC 2110-002
 Wednesday, April 3, 2013
 
 Description:
 This is the definition for the Server class. I decided to include both
 implementation and definition in one file, because it's short and simple.
 */

#ifndef SERVER_H
#define SERVER_H

class Server{
     
public:
     
     Server();                          //Default constructor
     Server(int newTime);               //Optional constructor
     void initialize(int newTime);      //Re-initialize the object
     
     bool isAvalible();                 //Returns if server is avalible
     bool addJob();                     //Adds a job to the list
     bool incrementTimer();             //Increments internal timer
     
private:
     
     bool removeJob();                  //Removes job
     bool avalible;                     //Avalabillity status
     
     int serveTime;                     //Serve time
     int timer;                         //Timer for resetting avalibillity status
          
};

Server::Server(){   //Default constructor
     /*
      Pre:     None.
      Post:    Object is initialized to the empty state
     */
     
     avalible = true;
     serveTime = timer = 0;
     
}

Server::Server(int newTime){  //Optional constructor
     /*
      Pre:     None.
      Post:    Object is initialized with given parameters at declaration
      */
     
     avalible = true;
     serveTime = newTime;
     timer = 0;
     
}

void Server::initialize(int newTime){
     /*
      Pre:     None.
      Post:    Object is initialized with given parameters
      */
     
     avalible = true;
     serveTime = newTime;
     timer = 0;
     
}

bool Server::isAvalible(){
     /*
      Pre:     None.
      Post:    Returns avalibillity status of the server
      */
     
     return avalible;
     
}

bool Server::addJob(){
     /*
      Pre:     None.
      Post:    Adds a job to the server and sets the timer to 0
      */
     
     if (!avalible){
          
          cerr << "Error! Server is full!" << endl;
          
          return false;
          
     }
     
     else {
          
          avalible = false;
          timer = 0;
          return true;
          
     }
     
}

bool Server::removeJob(){
     /*
      Pre:     None.
      Post:    Sets avalibillity to true
      */
     
     avalible = true;
     return true;
     
}

bool Server::incrementTimer(){
     /*
      Pre:     None.
      Post:    Increments the server's internal timer by 1
               Returns true if a job was removed
               Returns false otherwise
      */
     
     timer++;
     
     if (timer == (serveTime + 1)){
          
          removeJob();
          return true;
     }
     
     else return false;
     
}

#endif
