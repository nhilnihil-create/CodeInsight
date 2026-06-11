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
	int n; cin >> n;
	ll t[105];
	rep(i, 0, n) cin >> t[i];
	ll ans = t[0];
	rep(i, 1, n){
		ans = LCM(ans, t[i]);

	}
	cout << ans << endl;
	return 0;
}