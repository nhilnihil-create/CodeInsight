#include "bits/stdc++.h"
using namespace std;

typedef long long ll;

const ll MAX = 510000;
const ll MOD = (ll)1e9 + 7;

ll fac[MAX], finv[MAX], inv[MAX]; // a!(fac[a]), (a!)^{-1}(finv[a]), a^{-1}(inv[a])

								  // テーブルを作る前処理
void comb_init() {
	fac[0] = fac[1] = 1;
	finv[0] = finv[1] = 1;
	inv[1] = 1;
	for (ll i = 2; i<MAX; i++) {
		fac[i] = fac[i - 1] * i % MOD;
		inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
		finv[i] = finv[i - 1] * inv[i] % MOD;
	}
}

ll mod_comb(ll n, ll k) {
	if (n < k) return 0;
	if (n < 0 || k < 0) return 0;
	return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

int main() {
	// 前処理
	comb_init();

	ll H, W, A, B;
	cin >> H >> W >> A >> B;

	ll sum=0;
	for (ll i = B; i < W; i++) {
		ll st, tg;
		//cout << i+H-A-1 <<"C"<< i <<" "<< A+W-2-i <<"C"<< W-1-i << endl;
		st = mod_comb(i+H-A-1, i);
		tg = mod_comb(A+W-2-i, W-1-i);
		sum += st*tg%MOD;
	}

	cout << sum%MOD << endl;
}
