#include<bits/stdc++.h>
using namespace std;

// mutliple recursion calls 

// Fibonacci number

// Time complexity ==> 

int f(int n){
	if(n <= 1) return n;
	
	int l = f(n - 1);
	int sl = f(n - 2);
	
	return l + sl;
}


int main(){

#ifndef ONLINE_JUDGE
	
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	
	
#endif
	
	
	
	cout << f(4);
	
	
	return 0;	
}