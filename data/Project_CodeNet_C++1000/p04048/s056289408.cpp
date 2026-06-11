#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
#ifndef LOCAL
#define endl '\n'
#endif

const int mod = 1e9 + 7;

int pwr(int a,int b) {
	int ans = 1;
	while(b) {
		if(b & 1) ans = (ans * 1LL * a) % mod;
		a = (a * 1LL * a) % mod;
		b >>= 1;
	}
	return ans;
}

int n, m;
const int N = 1e5 + 5;
int cnt[N];

ll f(ll x, ll n) {
	if(x == 0)
		return 0;
	if(n % x == 0) {
		return (2 * (n / x) - 2) * x;
	}
	ll val = ((2 * (n / x) - 1) * x + (n % x) + f(n % x, x));
	return val;
}

void solve() {
	ll n, x;
	cin >> n >> x;
	cout << x + f(n - x, n);
}

signed main() {
	ios :: sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	// cin >> t;
	t = 1;
	for(int tt = 1; tt <= t; tt++) {
		// cout << "Case #" << tt << ": ";
		solve();
	}
	return 0;
}