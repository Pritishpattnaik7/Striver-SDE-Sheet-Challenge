#include<bits/stdc++.h>
using namespace std;

bool isValid(vector<vector<char>> &board, int row, int col, char c){
        for (int i=0 ; i<9 ; i++){
            //check for row wise
            if (board[row][i] == c){
                return false;
            }
        
            //check for column wise
            if (board[i][col] == c){
                return false;
            }
        
            //check in the 3x3 grid - Tricky af
            if (board[3 * (row/3) + i/3][3 * (col/3) + i%3] == c){
                return false;
            }
        }
        return true;
    }
    
    bool solve(vector<vector<char>> &board){
        int n = board.size();
        int m = board[0].size();
        
        //search for empty cells to fill
        for (int i=0 ; i<n ; i++){
            for (int j=0 ; j<m ; j++){
                if (board[i][j] == '.'){
                    for (char c='1' ; c<='9' ; c++){
                        if (isValid(board, i, j, c)){
                            board[i][j] = c;
                            
                            //recursive call
                            if (solve(board) == true)
                                return true;
                            
                            else
                                board[i][j] = '.';  //backtrack step
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }

int main(){
}