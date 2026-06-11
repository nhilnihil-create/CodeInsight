#include<bits/stdc++.h>
using namespace std;
using lli = long long;
#define rep(i,n) for(int i=0;i<n;i++)

string s;

int main(void){
	cin >> s;
	unordered_map<char, bool> mp;
	rep(i, s.size()){
		mp[s[i]]=true;
	}
	if(mp['N']^mp['S'] != 0) cout << "No" << endl;
	else if(mp['W']^mp['E'] != 0) cout << "No" << endl;
	else cout << "Yes" << endl;
	return 0;
}
