#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(string &s, int i, int j){
     while (i <= j) {
      if (s[i++] != s[j--])
        return false;
    }
    return true;
}
void func(int index, string s, vector < string > & path, vector < vector < string > > & res) {
    if (index == s.size()) {
      res.push_back(path);
      return;
    }
    for (int i = index; i < s.size(); ++i) {
      if (isPalindrome(s, index, i)) {
        path.push_back(s.substr(index, i - index + 1));
        func(i + 1, s, path, res);
        path.pop_back();
      }
    }
  }

int main(){

#ifndef ONLINE_JUDGE
	
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	
	
#endif

    string s = "aab";

    int n = 4;
    vector<vector<string>> ans;
	vector<string> temp;
	func(0, s, temp, ans);
	
    

    for (int i = 0; i < int(ans.size()); i++) {
        // cout << "[ ";
        for (int j = 0; j < int(ans[i].size()); j++){
            cout << ans[i][j] << " ";
            // cout << "]";
        }
        cout << endl;
    }
    // cout << " ]";

	return 0;	
}