#include<bits/stdc++.h>
using namespace std;

int cnt = 0;

int L2(int start, int end){
	if(start < end){
		return 0;
	}
	cout << start << endl;
	start--;
	L2(start, end);
	return 0;
}

int main(){
#ifndef	Yash
	
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	
	int num;
	cin >> num;
	L2(num, 1);
	
	
	return 0;
}