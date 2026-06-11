#include<bits/stdc++.h>
#define rep(i, x) for(ll i = 0; i < x; i++)
#define rep2(i, x) for(ll i = 1; i <= x; i++)
#define all(a) (a).begin(),(a).end()
using ll = long long;
using ld = long double;
using namespace std;
const ll INF = 1000000000000000000;
const ll mod = 1000000007;
const ld pi = 3.141592653589793238;

ll modpow(ll x, ll y) {
	ll res = 1;
	while (y) {
		if (y % 2) { res *= x; res %= mod; }
		x = x * x % mod; y /= 2;
	}
	return res;
}

ll inx[123456], iny[123456];
signed main() {
	ll n, m; cin >> n >> m;
	vector<ll> x, y;
	rep(i, n) {
		cin >> inx[i];
		if (i != 0) {
			x.push_back(inx[i] - inx[i - 1]);
		}
	}
	rep(i, m) {
		cin >> iny[i];
		if (i != 0) {
			y.push_back(iny[i] - iny[i - 1]);
		}
	}
	ll ans1 = 0, ans2 = 0;
	ll cnt = 1; reverse(all(x));
	rep(i, n - 1) {
		x[i] = (x[i] * cnt) % mod; cnt++;
	}
	cnt = 1; reverse(all(x));
	rep(i, n - 1) {
		ans1 += (x[i] * cnt) % mod; cnt++; ans1 %= mod;
	}

	cnt = 1; reverse(all(y));
	rep(i, m - 1) {
		y[i] = (y[i] * cnt) % mod; cnt++;
	}
	cnt = 1; reverse(all(y));
	rep(i, m - 1) {
		ans2 += (y[i] * cnt) % mod; cnt++; ans2 %= mod;
	}

	cout << (ans1 * ans2) % mod << endl;
	return 0;
}