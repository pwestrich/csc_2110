/*
 
 job.h
 by Philip Westrich
 for Assignment #3
 "Line Simulator"
 CSC 2110-002
 Wednesday, April 3, 2013
 
 Description:
 This is the definition for the Job class. Because it's so short, I decided to 
 put it all in one file. 
 It contains a default constructor, one optional constructor, and two data members
 
 */

#ifndef JOB_H
#define JOB_H

class Job {
     
public:
     
     Job();                                       //Default constructor
     Job(const int &newWaitTime, Job* newNext);   //Another constrictor
     
     //No real need for these to be private.
     int wait;
     Job* next;
     
};

Job::Job(){
     
     wait = 0;
     next = NULL;
     
}

Job::Job(const int &newWaitTime, Job* newNext){
     
     wait = newWaitTime;
     next = newNext;
     
}

#endif 
