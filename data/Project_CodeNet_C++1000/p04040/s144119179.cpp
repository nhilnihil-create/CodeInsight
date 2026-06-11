#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
const ll INF = 1LL << 60;
const double PI = 3.141592653589793238;
const double EPS = 1e-10;
ll fact[200001];
ll inv_fact[200001];
ll mod_pow(ll a, ll b) {
	if (b == 0) return 1;
	if (b % 2 == 0) {
		ll x = mod_pow(a, b / 2);
		return (x*x) % MOD;
	}
	return (a*mod_pow(a, b - 1)) % MOD;
}
ll comb(ll n, ll k) {
	if (n < k) return 0;
	ll ret = fact[n];
	(ret *= inv_fact[k]) %= MOD;
	(ret *= inv_fact[n - k]) %= MOD;
	return ret;
}
int main() {
	fact[0] = inv_fact[0] = 1;
	for (int i = 1; i <= 200000; i++) {
		fact[i] = (fact[i - 1] * i) % MOD;
		inv_fact[i] = (inv_fact[i - 1] * mod_pow(i, MOD - 2)) % MOD;
	}
	int H, W, A, B;
	cin >> H >> W >> A >> B;
	ll ans = 0;
	for (int i = 0; i < H - A; i++) {
		ll t = comb(i + B - 1, i);
		(t *= comb(H - i - 1 + W - B - 1, H - i - 1)) %= MOD;
		(ans += t) %= MOD;
	}
	cout << ans << endl;
}
