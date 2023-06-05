#include<bits/stdc++.h>
using namespace std;

int kthPermutationSequence(int n, string ans, int k){
    vector<int> nums;
    int fact = 1;
    // For generating the n number and to get the factorial that how many sequence in total can be there for nums.size() - 1 
    for (int i = 1; i < n; i++)
    {
        nums.push_back(i);
        fact *= i;
    }
    nums.push_back(n);
    // cout << nums.size();
    k = k - 1; // Because of array is of 0th index

    while(1){
        ans += to_string(nums[k / fact]); // For selecting one number in every iteration
        nums.erase(nums.begin() + k / fact); //  For deleting the number which is picked

        // When we picked all the element and got the number then break;
        if(nums.size() == 0)
        {
            break;
        }

        k %= fact; // To check which number to take

        fact = fact / nums.size(); // How many sequence can be formed


    }
    cout << ans << endl;

    return 0;
}


int main(){
#ifndef ONLINE_JUDGE

    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

#endif
    int nums = 4;
    int k = 17;
    string ans = "";

    kthPermutationSequence(nums, ans, k);

    return 0;
}