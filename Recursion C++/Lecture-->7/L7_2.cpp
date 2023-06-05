
// Print one of the subsequences that are having sum equals to the target

#include<bits/stdc++.h>
using namespace std;

// In these method we had done the same method just like printing the subsequences 
// What we did is  that we check the sum of element of the vector and if it is equal to target
// Then print that  

void printFunc(vector<int> &ans){
	for(auto it : ans){
		cout << it << " ";
	}
	
}

int addFunction(int target, vector<int> &ans){
	int sum = 0;
	for(auto it : ans) sum += it;
	if(sum == target) return 1;
	else return 0;
}

void subSequences1(int ind, vector<int> &ans1, int n, int arr[], int sum){
	if(ind == n){
		if(addFunction(sum, ans1)){
			printFunc(ans1);
			cout << endl;
		}
		return;
	}
	ans1.push_back(arr[ind]);
	subSequences1(ind + 1, ans1, n, arr, sum); // Pick Condition
	ans1.pop_back();
	subSequences1(ind + 1, ans1, n, arr, sum); // Not-Pick Condition
}

// Another method 
// Here we returned true and false bcz we want only one subSequence and if we got that we don't need to go further
bool subSequences2(int ind, vector<int> &ans1, int n, int arr[], int sum, int s){
	if(ind == n){
		// If this condition satisfy then return true
		if(s == sum){
			printFunc(ans1);
			
			cout << endl;
			return true;
		}
		else return false;
	}
	// Pick Condition
	ans1.push_back(arr[ind]);
	s += arr[ind];
	if(subSequences2(ind + 1, ans1, n, arr, sum, s) == 1) return true; 
	ans1.pop_back();
	s -= arr[ind];
	if(subSequences2(ind + 1, ans1, n, arr, sum, s) == 1) return true; // Not-Pick Condition
	return false;
}


int main(){

#ifndef ONLINE_JUDGE
	
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	
	
#endif
	
	
	// int arr[] = {1,2,3,4,5};
	// int n = 5;
	
	int arr[] = {1,2,1};
	int n = 3, sum = 2,s = 0;
	
	vector<int> ans1;
	vector<int> ans2;
	
	
	subSequences2(0, ans1, n, arr, sum, s);	
	
	return 0;	
}