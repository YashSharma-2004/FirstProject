#include<bits/stdc++.h>
using namespace std;

void solve(int row, int col,  vector<string> &ans,vector<vector<int>> &arr, vector<string> &temp, vector < vector < int >> & map, string s)
{

    if((row == arr.size() - 1) && (col == arr.size() - 1)){
        cout << s << endl;
        // ans.push_back(s);
        return;
    }

    // Down
    if((row + 1 < arr.size()) && (map[row + 1][col] == 0) && (arr[row + 1][col] == 1)){
        map[row][col] = 1;
        solve(row + 1, col, ans, arr, temp, map, s+'D');
        map[row][col] = 0;
    }

    // Up
    if((row - 1 >= 0) && (map[row - 1][col] == 0) && (arr[row - 1][col] == 1)){
        map[row][col] = 1;
        solve(row - 1, col, ans, arr, temp, map, s+'U');
        map[row][col] = 0;
    }

    // Right
    if((col + 1 < arr.size()) && (map[row][col + 1] == 0) && (arr[row][col + 1] == 1)){
        map[row][col] = 1;
        solve(row, col + 1, ans, arr, temp, map, s+'R');
        map[row][col] = 0;
    }
    // Left
    if((col - 1 >= 0) && (map[row][col - 1] == 0) && (arr[row][col - 1] == 1)){
        map[row][col] = 1;
        solve(row, col - 1 , ans, arr, temp, map, s+'L');
        map[row][col] = 0;
    }


}


int main(){

    vector < vector < int >> arr = {{1,0,0,0},{1,1,0,1},{1,1,0,0},{0,1,1,1}};
    vector<string> temp;
    vector<string> ans;
    int r = 0, c = 0;
    int n = arr.size();
    vector < vector < int >> m(n, vector<int> (n, 0));
    if(arr[0][0] == 1) solve(r, c, ans, arr, temp, m, "");

    // for (int i = 0; i < arr.size(); i++)
    // {
    //     cout << ans[i] << " ";
    // }
    

    return 0;
}