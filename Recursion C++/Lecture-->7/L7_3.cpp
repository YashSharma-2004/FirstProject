
// count all the subsequences that are having sum equals to the target

#include<bits/stdc++.h>
using namespace std;



int subSequences1(int ind, int n, int arr[], int sum, int s){
	if(ind == n){
		if(s == sum){
			return 1;
		}
		else return 0;
	}
	s += arr[ind];
	int l = subSequences1(ind + 1, n, arr, sum, s); // Pick Condition
	s -= arr[ind];
	int r = subSequences1(ind + 1, n, arr, sum, s); // Not-Pick Condition
	return l + r;
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

	
	
	
	cout << subSequences1(0, n, arr, sum, s);	
	
	return 0;	
}