#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
	string s;
	cin >> s;
	vector<char> ans;
	rep(i,s.size()){
		if(s[i] == '1' || s[i] == '0') ans.push_back(s[i]);
		if(s[i] == 'B' && ans.size()) ans.pop_back();
	}
	for(auto x : ans){
			cout << x;
	}
	cout << endl;
}