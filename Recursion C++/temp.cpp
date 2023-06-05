#include<bits/stdc++.h>

using namespace std;

int canPlaceIt(int row, int col, vector<string> &board, int n){

    int dupRow = row;
    int dupCol = col;


    // For checking each row and column
    while(row >= 0 && col >= 0) {
        if(board[row][col] == 'Q'){
            return false;
        }
        row--;
        col--;
    }
    row = dupRow;
    col = dupCol;
    // for checking only column
    while(col >= 0){
        if(board[row][col] == 'Q'){
            return false;
        }
        col--;
    }

    row = dupRow;
    col = dupCol;

    // For checking the lower cross diagonal 
    while(row < n && col >= 0){
        if(board[row][col] == 'Q'){
            return false;
        }
        row++;
        col--;
    }

    return true;

}

void nQueen(int n, int col, vector<vector<string>> &ans, vector<string> &board){

    if(col == n) {
        ans.push_back(board);
        return;
    }

    for(int row = 0; row < n; row++) {
        if(canPlaceIt(row, col, board, n) == 1) {
            board[row][col] = 'Q';
            nQueen(n, col + 1, ans, board);
            board[row][col] = '.';
        }
    }
}



int main(){
#ifndef ONLINE_JUDGE

    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    int n = 4;

    vector<vector<string>> ans;
    vector<string> board;

    string s (n, '.');

    for(int i = 0; i<n; i++){
        board[i] = s;
    }


    nQueen(n, 0, ans, board);
    
    for(int i = 0; i<ans.size(); i++) {
        cout << "Ans --> " << i + 1 << endl;
        for (int j = 0; j < ans[0].size(); j++) {
            cout << ans[i][j];
            cout << endl;
        }
        cout << endl;
    }
    
    return 0;
}