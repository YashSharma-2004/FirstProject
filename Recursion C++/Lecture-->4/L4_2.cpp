
#include<bits/stdc++.h>
using namespace std;


int reverseArray(int a[], int i, int n, int j){
	
	if(i >= j) return 0; // n / 2 bcz we will swap untill the middle element
	
	reverseArray(a, i+1, n, j-1); 
	
	swap(a[i], a[j]); // n - i - 1 will point will act like we do with i and j like swap(a[i], a[j]) and then i++ and j--;
	
	return 0;
	
}

int main(){

#ifndef ONLINE_JUDGE
	
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	
	
#endif
	
	int n; cin >> n;
	
	int a[n];
	
	for(int i = 0; i<n; i++){
		cin >> a[i];
	}
	
	int j = n - 1;
	reverseArray(a, 0, n, j);
	
	for(int i = 0; i<n; i++) cout << a[i] << endl;
	
	return 0;	
}