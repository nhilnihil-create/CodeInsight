#include"bits/stdc++.h"

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define REP(i, n) for (int i = 1; i <= (int)(n); i++)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using namespace std;
using ll = long long;
using pi = pair<int, int>;
const ll INF = 1LL << 60;

ll mod = 1e9 + 7;

ll fact(ll x) {
	ll res = 1;
	rep(i, x)res = res * (ll(i) + 1LL) % mod;
	return res;
}

int main() {
	ll a,b;
	cin >> a >> b;
	if (abs(a - b) > 1) { cout << 0 << endl; return 0; }
	ll ans = fact(a) * fact(b) % mod;
	if (a == b)ans = 2LL * ans % mod;
	cout << ans << endl;
	return 0;
}

