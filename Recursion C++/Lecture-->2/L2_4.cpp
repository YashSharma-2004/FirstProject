#include<bits/stdc++.h>
using namespace std;

// BackTracking used to print 1 to n


void backPrint(int i, int n){
	if(i < n) return;
	
	backPrint(i - 1, n);
	
	cout << i << endl;
	
}



int main(){
#ifndef	Yash
	
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	
	int n;
	cin >> n;
	
	backPrint(n, 1);
	
	return 0;
}