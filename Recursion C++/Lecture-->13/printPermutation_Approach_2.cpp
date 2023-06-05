#include<bits/stdc++.h>

using namespace std;

void printPermutation(int ind, vector<int> & nums, vector<vector<int>> &ans){

    if(ind == nums.size()){
        ans.push_back(nums);
        return;
    }

    for(int i = ind; i < nums.size(); i++){
        swap(nums[i], nums[ind]);
        printPermutation(ind + 1, nums, ans);
        swap(nums[i], nums[ind]);
    }

   
}


int main(){
#ifndef ONLINE_JUDGE

    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    
    vector<int> nums{1,2,3};
    vector<vector<int>> ans;
    printPermutation(0, nums, ans);
    for(int i =0; i<ans.size(); i++){
        for(int j = 0; j<ans[i].size(); j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}