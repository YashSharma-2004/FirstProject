#include<bits/stdc++.h>

using namespace std;


void nQueen(int n, int col, vector<string> &board, vector<vector<string>> &ans, vector<int> &lowerDiagonal, vector<int> &upperDiagonal, vector<int> &leftRow) {

    if(col == n){
        ans.push_back(board);
        return;
    }
    for (int row = 0; row < n; row++) {
        if(leftRow[row] == 0 && upperDiagonal[n - 1 + col - row] == 0 && lowerDiagonal[row + col] == 0){
            // Mark the Q
            board[row][col] = 'Q';
            // Mark the 1 where Q is placed in all the diagonal
            leftRow[row] = 1;
            upperDiagonal[n - 1 + col - row] = 1;
            lowerDiagonal[row + col] = 1;
            // Function call
            nQueen(n, col + 1, board, ans, lowerDiagonal, upperDiagonal, leftRow);
            // remove Q which is placed before recursion call
            board[row][col] = '.';
            // Unmark the 1 which is done earlier 
            leftRow[row] = 0;
            upperDiagonal[n - 1 + col - row] = 0;
            lowerDiagonal[row + col] = 0;
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
    vector<int> leftRow(n, 0), lowerDiagonal(2 * n - 1, 0), upperDiagonal(2 * n - 1, 0);
    nQueen(n, 0, board, ans, lowerDiagonal, upperDiagonal, leftRow);
    
    for (int i = 0; i < ans.size(); i++) {
        cout << "Arrangement " << i + 1 << "\n";
        for (int j = 0; j < ans[0].size(); j++) {
            cout << ans[i][j] << " ";
            cout << endl;
        }
        cout << endl;
    }
   
    return 0;
}