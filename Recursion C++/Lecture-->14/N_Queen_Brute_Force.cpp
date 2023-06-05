#include<bits/stdc++.h>

using namespace std;

int canPlaceIt(int row, int col, vector<string> board, int n){

    int dupRow = row;
    int dupCol = col;

    while (row >= 0 && col >= 0){
        if(board[row][col] == 'Q') {
            return false;
        }
        row--;
        col--;
    }
    col = dupCol;
    row = dupRow;

    while (col >= 0){
        if(board[row][col] == 'Q') return false;
        col--;
    }
    
    col = dupCol;
    row = dupRow;
    
    while (row < n && col >= 0)
    {
        if(board[row][col] == 'Q') return false;
        row++;
        col--;
    }
    
    return true;

}


void nQueen(int n, int col, vector<string> &board, vector<vector<string>> &ans){
    if(col == n){
        ans.push_back(board);
        return;
    }
    for (int row = 0; row < n; row++) {
        if(canPlaceIt(row, col, board, n) == 1) {
            board[row][col] = 'Q';
            nQueen(n, col + 1, board, ans);
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
    vector<string> board(n);
    string s(n, '.');
    vector<vector<string>> ans;
    for (int i = 0; i < n; i++) {
        board[i] = s;
    }
     nQueen(n, 0, board, ans);
    for (int i = 0; i < ans.size(); i++) {
        cout << "Arrangement " << i + 1 << "\n";
        for (int j = 0; j < ans[0].size(); j++) {
            cout << ans[i][j];
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}