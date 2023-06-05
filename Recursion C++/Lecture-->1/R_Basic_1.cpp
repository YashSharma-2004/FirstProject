#include<bits/stdc++.h>
using namespace std;

int cnt = 0;

void print(){
	cout << cnt << endl;
	cnt++;
	if(cnt == 5) return;
	print();
	
}

int main(){
#ifndef	Yash
	
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	
	print();
	
	return 0;
}