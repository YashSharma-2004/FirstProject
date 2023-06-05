#include<bits/stdc++.h>

using namespace std;

void printPermutation(vector<int> &temp, vector<int> & nums, vector<vector<int>> &ans, int freq[]){

    if(temp.size() == nums.size()){
        ans.push_back(temp);
        return;
    }

    for(int i = 0; i<nums.size(); i++){
        if(freq[i] != 1){
            temp.push_back(nums[i]);
            freq[i] = 1;
            printPermutation(temp, nums, ans, freq);
            freq[i] = 0;
            temp.pop_back();
        }
    }
}


int main(){
#ifndef ONLINE_JUDGE

    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    vector<int> temp;
    vector<int> nums;
    vector<vector<int>> ans;
    int freq[nums.size()];
    for (int i = 0; i < nums.size(); i++) freq[i] = 0;
    printPermutation(temp, nums, ans, freq);
    for(int i =0; i<ans.size(); i++){
        for(int j = 0; j<ans[i].size(); j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}