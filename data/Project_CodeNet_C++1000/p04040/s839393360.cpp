#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
#define pi pair<ll,ll>
#define pii pair<ll,pi>
#define pb push_back
#define mk make_pair
const ll siz = 1e6 + 7;
const ll mod = 1e9 + 7;
ll fac[siz];
ll inv[siz];
ll binpow(ll a, ll b) {
	ll res = 1;
	while (b > 0) {
		if (b & 1)
			res = (res * a) % mod;
		a = (a * a) % mod;
		b >>= 1;
	}
	return res;
}

ll ncr(ll n, ll r) {
	if (r == 0 || n == r)return 1;
	return (((fac[n] * inv[n - r]) % mod) * inv[r]) % mod;
}

int main() {
// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll h, w, a, b;
	cin >> h >> w >> a >> b;
	fac[0] = 1;
	for (int i = 1; i < siz; i++) {
		fac[i] = (fac[i - 1] * i) % mod;
		inv[i] = binpow(fac[i], mod - 2);
	}
	ll ans = 0;
	for (int i = b; i < w; i++) {
		int y1 = h - a - 1, x1 = i;
		int y2 = a - 1, x2 = w - i - 1;
		ll res = (ncr(x1 + y1, x1)) * (ncr(x2 + y2, x2)) % mod;
		ans = (ans + res) % mod;
	}
	cout << ans << endl;
}
