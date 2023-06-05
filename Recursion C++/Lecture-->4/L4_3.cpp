
#include<bits/stdc++.h>
using namespace std;


// Basically, it is like a palindrome question to check that whether a string remains same or not when we reverse it

int checkReverseString(string &s, int i, int n){
	
	if(i >= n / 2) return 1;
	
	if(s[i] != s[n - i - 1]) return 0; // That means it's not a palindrome bcz it will check the first and last then first+1 and last - 1 and so on
	
	return checkReverseString(s, i + 1, n);
	
	
}

int main(){

#ifndef ONLINE_JUDGE
	
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	
	
#endif
	string s1 = "madam";
	string s = "madan";
	
	int n = 5;
	
	cout << checkReverseString(s1, 0, n);
	cout << endl; 
	cout << checkReverseString(s, 0, n);
	
	
	
	return 0;	
}