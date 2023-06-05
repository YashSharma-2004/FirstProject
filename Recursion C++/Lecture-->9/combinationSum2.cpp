#include<bits/stdc++.h>
using namespace std;


void solve(int index, int t, vector<vector<int>> &ans, vector<int> &temp, vector<int> &v){
	
	if(t == 0){
		ans.push_back(temp);
		return;
	}
	
	for(int i = index; i < int(v.size()); i++){
		if(i > index && v[i] == v[i - 1]) continue; // To avoid the duplicated
		if(v[i] > t) break; // if array value is greater than the target 
		temp.push_back(v[i]);
		solve(index + 1,t - v[i], ans, temp, v);
		temp.pop_back();
	}	
}


int main(){
#ifndef ONLINE_JUDGE
	
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	
#endif
	
	
	vector<int> v{2,5,2,1,2};
	vector<int> temp;
	int target = 5;
	vector<vector<int>> ans;
	sort(v.begin(), v.end());
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