#include<iostream>
using namespace std;
typedef long long ll;

ll mod = 1e9 + 7, fac[((int)1e6 + 5)], v[((int)1e6 + 5)];

ll modRec(ll a, ll b) {
	if (b == 0)return 1;
	if (b % 2 == 0)return modRec((a * a) % mod, b / 2);
	return ((a % mod) * modRec((a * a) % mod, b / 2)) % mod;
}

int main() {
	fac[0] = 1, v[0] = 1;
	for (int i = 1; i <= 1e6; i++) {
		fac[i] = (i * fac[i - 1]) % mod;
		v[i] = modRec(fac[i], mod - 2);
	}
	ll h, w, a, b, ans = 0; cin >> h >> w >> a >> b;
	for (ll i = b; i < w; i++) {
		ll p = i, q = h - a - 1, r = w - i - 1, s = a - 1;
		ll x = (((fac[p + q] * v[p]) % mod) * v[q]) % mod;
		x *= (((fac[r + s] * v[r]) % mod) * v[s]) % mod;
		ans = (ans + x) % mod;
	}
	cout << ans << endl;
	return 0;
}