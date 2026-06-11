#pragma GCC optimize("O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 2e5 + 5;
const int mod = 1e9 + 7;

ll f[N], fr[N];

ll cnk(int n, int k) {
	return f[n] * fr[k] % mod * fr[n - k] % mod;
}

ll binpow(ll a, int p) {
	ll res = 1;
	while (p) {
		if (p & 1) {
			(res *= a) %= mod;
		}
		p >>= 1;
		(a *= a) %= mod;
	}
	return res;
}

int main() {
	// freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int h, w, a, b;
	cin >> h >> w >> a >> b;
	f[0] = fr[0] = 1;
	for (int i = 1; i < N; i++) {
		f[i] = f[i - 1] * i % mod;
		fr[i] = binpow(f[i], mod - 2);
	}
	ll ans = cnk(h + w - 2, h - 1);
	for (int i = h - a + 1; i <= h; i++) {
		ans -= cnk(i + b - 2, b - 1) * cnk(h - i + 1 + w - b - 2, w - b - 1) % mod;
		ans = (ans + mod) % mod;
	}
	cout << ans << endl;
	return 0;
}
