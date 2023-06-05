#include<bits/stdc++.h>
using namespace std;

int cnt = 0;

int L2(int num){
	if(num >= 5){
		return 0;
	}
	cout << "Hel" << endl;
	L2(num+1);
	return 0;
}

int main(){
#ifndef	Yash
	
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	
	int num = 0;
	L2(num);
	
	
	return 0;
}