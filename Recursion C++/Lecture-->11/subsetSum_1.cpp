#include <bits/stdc++.h>
using namespace std;

// **************************************************************************************


// Brute Force -- In which we are using extra space with a set and one 2d array 
// And also taking more time while converting set to 2d array

void printAns(vector < vector < int >> & ans) {
  cout << "(Brute-Force) The unique subsets are " << endl;
  cout << "[ ";
  for (int i = 0; i < int(ans.size()); i++) {
    cout << "[ ";
    for (int j = 0; j < int(ans[i].size()); j++)
      cout << ans[i][j] << " ";
    cout << "]";
  }
  cout << " ]";
}

void solve(int i, set<vector<int>> &ans, vector<int> & temp, vector<int> &v){
	
	if(i == int(v.size())){
		sort(temp.begin(), temp.end());
		ans.insert(temp);
		return;
	}
	temp.push_back(v[i]);
	solve(i + 1, ans, temp, v); // Pick 
	temp.pop_back();
	solve(i + 1, ans, temp, v); // Not-Pick
}
// **************************************************************************************

// **************************************************************************************

// Optimal Code --> 
	
	
void printAns2(vector < vector < int >> & ans) {
	
  cout << "(Optimal Code) The unique subsets are " << endl;
  cout << "[ ";
  for (int i = 0; i < int(ans.size()); i++) {
    cout << "[ ";
    for (int j = 0; j < int(ans[i].size()); j++)
      cout << ans[i][j] << " ";
    cout << "]";
  }
  cout << " ]";
}


void solve2(int ind, vector<vector<int>> &ans2, vector<int> & temp2, vector<int> &v){
	ans2.push_back(temp2);
	for(int i = ind; i<int(v.size()); i++){
		if (i != ind && v[i] == v[i - 1]) continue;
		temp2.push_back(v[i]);
		solve2(i + 1, ans2, temp2, v); // Pick 
		temp2.pop_back();
	}
	
}

// **************************************************************************************


int main(){
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	
	vector<int> v{1,2,2};
	set<vector<int>> ans;
	vector<int> temp;
	
	vector<int> temp2;
	vector<vector<int>> ans2;
	sort(v.begin(), v.end());
	solve(0, ans, temp, v);
	solve2(0, ans2, temp2, v);
	
	printAns2(ans2);
		cout << endl;
		cout << endl;
	vector<vector<int>> final;
	
	
	for(auto it = ans.begin(); it != ans.end(); it++){
		final.push_back(* it);
	}
	
	printAns(final);
	return 0;
}