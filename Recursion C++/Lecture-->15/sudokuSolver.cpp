#include<bits/stdc++.h>

using namespace std;


bool canPlaceIt(vector<vector<char>> & board, int row, int col, char c){

    for (int i = 0; i < 9; i++)
    {
        if(board[row][i] == c) return false;
        if(board[i][col] == c) return false;
    }

    int dupRow = row - row % 3;    
    int dupCol = col - col % 3;    


    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if(board[i + dupRow][j + dupCol] == c) return false;
        }
        
    }
    
    return true;

}


bool solve(vector<vector<char>> & board){
 for(int i = 0; i < board.size(); i++){
        for(int j = 0; j < board[i].size(); j++){
            
            if(board[i][j] == '.'){

                for(char c = '1'; c <= '9'; c++){

                    if(canPlaceIt(board, i, j, c)){ // If can place the number then placec it and make a recursion call if that gives true after some point of time then return true else do the backtracking step
                        board[i][j] = c;

                        if(solve(board)){
                            return true;
                        }
                        else{
                            board[i][j] = '.'; // Backtracking step
                            
                        }
                    }

                }
                return false;
            }
        }
    }
    return true;


}

int main(){
#ifndef ONLINE_JUDGE

    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

#endif


    vector<vector<char>>board{
        {'9', '5', '7', '.', '1', '3', '.', '8', '4'},
        {'4', '8', '3', '.', '5', '7', '1', '.', '6'},
        {'.', '1', '2', '.', '4', '9', '5', '3', '7'},
        {'1', '7', '.', '3', '.', '4', '9', '.', '2'},
        {'5', '.', '4', '9', '7', '.', '3', '6', '.'},
        {'3', '.', '9', '5', '.', '8', '7', '.', '1'},
        {'8', '4', '5', '7', '9', '.', '6', '1', '3'},
        {'.', '9', '1', '.', '3', '6', '.', '7', '5'},
        {'7', '.', '6', '1', '8', '5', '4', '.', '9'}
    };
   
    solve(board);

    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++)
            cout << board[i][j] << " ";
            cout << endl;
    }

    return 0;
}