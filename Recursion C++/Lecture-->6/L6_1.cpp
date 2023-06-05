
// Structure of subsequences 

// f(ind, n){
	// if(ind >= n){
			// print
			// return;
	// } 

	// vec.push_back(arr[i]);
	// f(ind + 1, n); // Condition for take
	// vec.pop_bacK();
	// f(ind + 1, n) // Conditon for not-take
//} 

//main(){
//
//	f(0, n);
//
//}

#include<bits/stdc++.h>
using namespace std;

void printFunc(vector<int> &ans){
	for(auto it : ans){
		cout << it << " ";
	}
	
}


void subSequences1(int ind, vector<int> &ans1, int n, int arr[]){
	if(ind == n){
		printFunc(ans1);
		if(ans1.size() == 0) cout << "{}";
		cout << endl;
		return;
	}
	
	
	
	ans1.push_back(arr[ind]);
	
	subSequences1(ind + 1, ans1, n, arr); // Pick Condition
	
	ans1.pop_back();
	
	
	subSequences1(ind + 1, ans1, n, arr); // Not-Pick Condition
	
}

// To print in reverse order

void subSequences2(int ind, vector<int> &ans2, int n, int arr[]){
	if(ind == n){
		printFunc(ans2);
		if(ans2.size() == 0) cout << "{}";
		cout << endl;
		return;
	}
	
	
	
	subSequences2(ind + 1, ans2, n, arr); // Not-Pick Condition
	
	ans2.push_back(arr[ind]);
	
	subSequences2(ind + 1, ans2, n, arr); // Pick Condition
	
	ans2.pop_back();
	
	
	
	
}



int main(){

#ifndef ONLINE_JUDGE
	
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	
	
#endif
	
	
	int arr[] = {1,2,3};
	int n = 3;
	
	vector<int> ans1;
	vector<int> ans2;
	
	subSequences1(0, ans1, n, arr);	
	cout << endl << "2nd Order" << endl;
	subSequences2(0, ans2, n, arr);	
	
	return 0;	
}