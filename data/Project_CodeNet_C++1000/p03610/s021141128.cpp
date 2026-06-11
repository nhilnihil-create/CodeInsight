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
		if(i%2 == 0){
			ans.push_back(s[i]);
		}
	}
	rep(i,ans.size()){
		cout << ans[i];
	}
	cout << endl;
}