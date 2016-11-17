//  main.cpp 
//
//  Created by Philip Westrich on 2/8/13.
//
// This is the main driver for Assignment #1, the Tic Tac Toe game.

#include "main.h"

using namespace std;

int main(){
     
     //Variables for input.
     string nameBuffer;
     char answer = 'X'; 
     TicTacToe Game;
     
     cout << "Welcome to Tic Tac Toe!" << endl;
     cout << "-----------------------" << endl;
     cout << "by Philip Westrich" << endl;
     
     do {
          
          answer = 'X'; //Reset the input variable for playing again.
     
          cout << "Please enter the name for Player 1: ";
          cin >> nameBuffer;
     
          Player playerOne(nameBuffer, 1);
     
          cout << "Please enter the name for Player 2: ";
          cin >> nameBuffer;
     
          Player playerTwo(nameBuffer, 2);
     
          cout << playerOne.getName() << ", you will be X, and "
               << playerTwo.getName() << " will be O."
               << endl;
     
          cout << "Please enter your moves by putting the row number, "
               << "followed by the column number."
               << endl;
          
          cout << "Example: Enter '2 2' for the middle square."
               << endl;
          
          if (choosePlayer() == 1){ //If Player 1 wins the toss, he goes first.
               
               cout << playerOne.getName() << " will go first." << endl;
     
               do { //Repeat until the game is won.
          
                    playerOne.nextMove(Game);
               
                    cout << Game;
                    
                    if (Game.getStatus() != 3){ //If Player 1 won, break from the loop.
                         
                         break;
                         
                    }
               
                    playerTwo.nextMove(Game);
               
                    cout << Game;
          
               } while (Game.getStatus() == 3);
               
          }
          
          else { //Otherwise, Player 2 goes first
               
               cout << playerTwo.getName() << " will go first." << endl;
               
               do { //Repeat until the game is won.
                    
                    playerTwo.nextMove(Game);
                    
                    cout << Game;
                    
                    if (Game.getStatus() != 3){ //If Player 2 won, break from the loop.
                         
                         break;
                         
                    }
                    
                    playerOne.nextMove(Game);
                    
                    cout << Game;
                    
               } while (Game.getStatus() == 3);
               
               
          }
     
          if (Game.getStatus() == 1){
          
               cout << "Congratulations " << playerOne.getName() << ", you've won the game!" << endl;
          
          }
     
          else if (Game.getStatus() == 2){
          
               cout << "Congratulations " << playerTwo.getName() << ", you've won the game!" << endl;
          
          }
     
          else if (Game.getStatus() == 0){
          
               cout << "No winners this time, it's a tie!" << endl;
               
          }
          
          cout << "Would you like to play again?" << endl;
          
          while (answer == 'X'){
               
               do { //This loop will make sure valid input is given from the user.
                    
                    if (!cin){
                         
                         cin.clear();
                         cin.ignore(1000, '\n');
                         
                    }
                    
                    cout << "Enter 'Y' for yes, or 'N' for no: ";
                    cin >> answer;
                    cin.ignore(1000, '\n');
                    
               } while (!cin);
               
          }
          
          if ((answer == 'Y') || (answer == 'y')){ //If we are to play again, re-initialize the board.
               
               Game.initialize();
               
          }
          
     } while ((answer == 'Y') || (answer == 'y')); //We'll repeat the game until the user(s) decide to qiut.
          
     return 0;
     
}
