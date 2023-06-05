#include<bits/stdc++.h>
using namespace std;


void solve(int i, int t, vector<vector<int>> &ans, vector<int> &temp, vector<int> &v){

	if(i == int(v.size())){
		if(t == 0){
			ans.push_back(temp);
		}
		return;
	}
	
	if(v[i] <= t){
		temp.push_back(v[i]);
		solve(i, t - v[i], ans, temp, v);
		
		temp.pop_back();
		
	}
	
	solve(i + 1, t, ans, temp, v);
}


int main(){
#ifndef ONLINE_JUDGE
	
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	
#endif
	
	
	vector<int> v{2,3,6,7};
	vector<int> temp;
	int target = 7;
	vector<vector<int>> ans;
	solve(0, target, ans, temp, v);
	
	for (int i = 0; i < int(ans.size()); i++)
    {
        for (int j = 0; j < int(ans[i].size()); j++)
        {
            cout << ans[i][j] << " ";
        }    
        cout << endl;
    }

	return 0;
}