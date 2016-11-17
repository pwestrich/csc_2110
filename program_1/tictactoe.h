//
//  tictactoe.h
//  
//
//  Created by Philip Westrich on 2/8/13.
//
//

#ifndef TICTACTOE_H
#define TICTACTOE_H

#include <iostream>

using namespace std;

class TicTacToe{
  
public:
     
     friend ostream& operator<<(ostream &out, const TicTacToe& Game);
     
     TicTacToe();                                 //Default constructor
     void initialize();                           //Initializes the board with '/0'
     void setValue(int row, int col, int player); //Makes the player's move
     int getStatus();                             //Returns the current game state
     char getValue(int row, int col);              //Gets the value in the game board
     
     
private:
     
     char gameBoard[3][3];
     int moveCount;
     
};

#endif
