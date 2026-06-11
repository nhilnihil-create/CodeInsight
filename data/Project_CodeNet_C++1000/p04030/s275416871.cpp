#include <bits/stdc++.h>
using namespace std;

#define rep(i,l,r) for(int i=(l);i<(r);i++)
#define pb push_back
#define fi first
#define se second

using ll = long long;
using G = vector<vector<int>>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const ll MOD = 1000000007;

ll GCD(ll x, ll y){
	return y ? GCD(y, x%y) : x;	
}
ll LCM(ll x, ll y){
	return x/GCD(x, y)*y;
}

int main() {
	string s; cin >> s;
	int l = int (s.size());
	vector<char> ans;
	rep(i, 0, l){
		if(s[i]!='B') ans.pb(s[i]);
		if(s[i]=='B' && ans.size()!=0) ans.pop_back();
	}
	for(auto c: ans) cout << c;
	cout << endl;
	return 0;
}