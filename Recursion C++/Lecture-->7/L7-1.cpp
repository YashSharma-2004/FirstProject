
// Print all the subsequences that are having sum equals to the target

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

void subSequences2(int ind, vector<int> &ans1, int n, int arr[], int sum, int s){
	if(ind == n){
		if(s == sum){
			printFunc(ans1);
			cout << endl;
		}
		return;
	}
	// Pick Condition
	ans1.push_back(arr[ind]);
	s += arr[ind];
	subSequences2(ind + 1, ans1, n, arr, sum, s); 
	ans1.pop_back();
	s -= arr[ind];
	subSequences2(ind + 1, ans1, n, arr, sum, s); // Not-Pick Condition
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
	
	// cout << "1st Method:==>" << endl;
	// subSequences1(0, ans1, n, arr, sum);	
	
	// cout << "2nd Method:==>" << endl;
	
	subSequences2(0, ans1, n, arr, sum, s);	
	
	return 0;	
}