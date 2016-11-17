//
//tictactoe.cpp  
//
//Created by Philip Westrich on 2/8/13.
//
//

#include "tictactoe.h"

using namespace std;

ostream& operator << (ostream& out, const TicTacToe& Game){
     //Here's our bit for overloading the << operator to display the game board
     
     out << "Here's the current game:" << endl;
     
     for (int i = 0; i < 3; i++){
               
          out << Game.gameBoard[i][0] << " | " << Game.gameBoard[i][1] << " | " << Game.gameBoard[i][2] << endl;
          
          if (i < 2){
               
               out << "----------" << endl;
               
          }
          
     }
     
     return out;
     
}

TicTacToe::TicTacToe(){ //Default constructor
     
     moveCount = 0;
     
     for (int i = 0; i < 3; i++){
          
          for (int j = 0; j < 3; j++){
               
               gameBoard[i][j] = '0';
               
          }
          
     }
     
}

void TicTacToe::initialize(){
     //This function will reset the game to be played again.
     //Pre: Object has been created
     //Post: Object will be reset; the board will be empty, movecount will be 0
     
     moveCount = 0;
     
     for (int i = 0; i < 3; i++){
          
          for (int j = 0; j < 3; j++){
               
               gameBoard[i][j] = '0';
               
          }
          
     }
     
}

void TicTacToe::setValue(int row, int col, int player){
     //Pre: Object exists, 0 <= row & col <= 2 and are integers
     //Post: The requested move has been made to the board, moveCount has been incremented.
     
     if (player == 1){
          
          gameBoard[row][col] = 'X';
          
     }
     
     else {
          
          gameBoard[row][col] = 'O';
          
     }
     
     moveCount++;
     
}

int TicTacToe::getStatus(){
     //Pre: Object exists
     //Post: The game has been checked for winners. 
     
          
     for (int i = 0; i < 3; i++){ //Let's run through the rows.
               
          if ((gameBoard[i][0] == gameBoard[i][1]) && (gameBoard[i][1] == gameBoard[i][2]) && (gameBoard[i][3] != '0')){
               // If the three characters in the board are the same and not '0', we have a winner
                    
               if (gameBoard[i][2] == 'X'){ // Return 1 if the character is X for Player 1
                         
                    return 1;
                         
               }
                    
               else if (gameBoard[2][0] == 'O') { //Otherwise Player 2 has won.
                         
                    return 2;
                         
               }
                    
          }
               
     }
          
     for (int j = 0; j < 3; j++){ //Now for columns.
               
          if ((gameBoard[0][j] == gameBoard[1][j]) && (gameBoard[1][j] == gameBoard[2][j]) && (gameBoard[2][j] != '0')){
               // Same as above, only swapped for columns
                    
               if (gameBoard[2][j] == 'X'){ // Return 1 if the character is X for Player 1
                         
                    return 1;
                         
               }
                    
               else if (gameBoard[2][0] == 'O') { //Otherwise Player 2 has won.
                         
                    return 2;
                         
               }
                    
          }
               
     }
          
     //Now it's time for diagonals.
     if ((gameBoard[0][0] == gameBoard[1][1]) && (gameBoard[1][1] == gameBoard[2][2]) && (gameBoard[2][2] != '0')){
               //Same as above, except for left-to-right diagonal
               
               if (gameBoard[2][2] == 'X'){ // Return 1 if the character is X for Player 1
                    
                    return 1;
                    
               }
               
               else if (gameBoard[2][0] == 'O') { //Otherwise Player 2 has won.
                    
                    return 2;
               }
               
          }
          
     if ((gameBoard[0][2] == gameBoard[1][1]) && (gameBoard[1][1] == gameBoard[2][0]) && (gameBoard[2][0] != '0')){
          //Same as above, except for right-to-left diagonal
               
          if (gameBoard[2][0] == 'X'){ // Return 1 if the character is X for Player 1
                    
               return 1;
                    
          }
               
          else if (gameBoard[2][0] == 'O') { //Otherwise Player 2 has won.
               
               return 2;
          }
               
     }
     
     if (moveCount == 9){ //There can only be a max number of 9 moves. If no one has won at this point, it's a tie.
          
          return 0;
          
     } 
     
      // If there are no winning moves, return 3 to keep the game going.
          
     return 3;
     
}

char TicTacToe::getValue(int row, int col){
     //Pre: Object exists, 0 <= row & col <= 2 and are integers
     //Post: The value for the indicated position will be returned.
     
     return gameBoard[(row - 1)][(col - 1)];
     
}
