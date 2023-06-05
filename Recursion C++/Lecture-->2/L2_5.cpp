#include<bits/stdc++.h>
using namespace std;

// BackTracking used to print n to 1


void backPrint(int i, int n){
	if(i > n) return;
	
	backPrint(i + 1, n);
	
	cout << i << endl;
	
}



int main(){
#ifndef	Yash
	
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	
	int n;
	cin >> n;
	
	backPrint(1, n);
	
	return 0;
}