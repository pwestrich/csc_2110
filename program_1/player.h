//  player.h
//  
// by Philip Westrich
//
//This file shall contain the definition for the Player class, as well as any
//other things it needs to operate.

#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>
#include "tictactoe.h"

using namespace std;

class Player{
     
public:
     
     Player(string newName, int newNumber);   //Constructor
     int getIndex();                          //Gets the player number
     string getName();                        //Gets the player name
     void nextMove(TicTacToe& Game);          //Makes the move.
     
private:
     
     string name;   //The player's name
     int number;    //The player's number
     
};




#endif 
