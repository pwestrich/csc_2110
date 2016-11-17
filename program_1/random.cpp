//
//  random.cpp
//  
//
//  Created by Philip Westrich on 2/13/13.
//
//Purpose:
//This file will contain the code needed to randomly select a player.
//It will return either 1 or 2 for the player to go first, respectivley

#include "random.h"

int choosePlayer(){
     
     srand(time(NULL)); //Seed the random number generator with the current time.
     
     return ((rand() % 2) + 1);
     
}
