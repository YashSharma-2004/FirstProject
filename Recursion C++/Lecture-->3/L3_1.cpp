#include<bits/stdc++.h>
using namespace std;


// Sum of n number


int sum(int num){
	if(num == 0) return 0;
	return num + sum(num - 1);
}

int main(){
#ifndef ONLINE_JUDGE
	
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	
	
#endif
	
	int n;
	cin >> n;
	cout << sum(n);
	
	return 0;	
}