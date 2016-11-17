//
//  player.cpp
//  
//
//  Created by Philip Westrich on 2/8/13.
//
//

#include "player.h"

Player::Player(string newName, int newNumber){ //Default constructor
     
     name = newName;
     number = newNumber;
     
}

int Player::getIndex(){
     //Pre: Object exists
     //Post: Player number is returned
     
     return number;
}

string Player::getName(){
     //Pre: Object exists
     //Post: Player name has been returned
     
     return name;
}

void Player::nextMove(TicTacToe& Game){
     //Pre: Object exists, TicTacToe object also exists
     //Post: The move requested from the user has been made.
     
     int row = -1,  //Variables for input. Set to -1, because it's invalid.
         col = -1;
     
     while (((row <= 0) || (row > 3)) && ((col <= 0) || (col > 3))){ //Only allow for valid input selections
          
          do { //This loop will make sure an integer was entered.
               
               if (!cin){
                    
                    cin.clear();
                    cin.ignore(1000, '\n');
                    
               }
               
               cout << name << ", please make your move: ";
               
               cin >> row;
               cin >> col;
               cin.ignore(1000, '\n');
               
          } while (!cin);
          
          if (((row <= 0) || (row > 3)) && ((col <= 0) || (col > 3))){
               
               cout << "Sorry, that is not a valid choice. Please try again." << endl;
               
               row = col = -1;
               
          }
          
          else if (Game.getValue(row, col) != '0'){ //Check if the value is taken
               
               cout << "Sorry, that spot is taken. Please try again." << endl;
               
               row = col = -1;
               
          }
          
     }
     
     Game.setValue((row - 1), (col - 1), number); //If the move is valid, make it.
     
}
