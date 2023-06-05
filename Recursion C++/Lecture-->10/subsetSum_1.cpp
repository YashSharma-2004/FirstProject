#include <bits/stdc++.h>

using namespace std;


void solve(int i, vector<int> &ans, int sum, vector<int> &v){
	
	if(i == int(v.size())){
		ans.push_back(sum);
		return;
	}
	
	
	solve(i + 1, ans, sum + v[i], v); // Pick because sum + v[i]
	
	
	solve(i + 1, ans, sum, v); // Not-Pick
	
	
}



int main(){
#ifndef ONLINE_JUDGE
	
	freopen("in.txt", "r", stdin);
	
	freopen("out.txt", "w", stdout);
	
#endif
	
	vector<int> v{3,1,2};
	vector<int> ans;
	
	solve(0, ans, 0, v);
	
	sort(ans.begin(), ans.end());
	
	for(auto it: ans)
		cout << it << endl;
	
	return 0;
}