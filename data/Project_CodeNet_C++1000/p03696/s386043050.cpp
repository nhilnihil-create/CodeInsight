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

int main() {
	int n; cin >> n;
	string s; cin >> s;
	int right = 0;
	int left = 0;
	rep(i, 0, n){
		if(s[i]=='(') right++;
		else if(s[i]==')') right--;
		left = min(left, right);
	}
	rep(i, 0, abs(left)) cout << '(';
	cout << s;
	rep(i, 0, right-left) cout << ')';
	cout << endl;
	return 0;
}