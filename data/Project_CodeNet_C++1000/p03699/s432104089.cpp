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
	int s[105];
	int sum = 0;
	rep(i, 0, n){
		cin >> s[i];
		sum += s[i];
	}
	sort(s, s+n);
	if(sum%10!=0){
		cout << sum << endl;
		return 0;
	}
	rep(i, 0, n){
		if(s[i]%10!=0){
			cout << sum-s[i] << endl;
			return 0;
		}
	}
	cout << 0 << endl;
	return 0;
}