#include<bits/stdc++.h>
using namespace std;

int cnt = 0;

int L2(int start, int num){
	if(start > num){
		return 0;
	}
	cout << start << endl;
	start++;
	L2(start, num);
	return 0;
}

int main(){
#ifndef	Yash
	
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	
	int num;
	cin >> num;
	L2(1, num);
	
	
	return 0;
}