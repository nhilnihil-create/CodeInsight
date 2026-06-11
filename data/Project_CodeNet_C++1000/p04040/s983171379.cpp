#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mod = 1e9 + 7;
const int N = 200000;

ll fac[N + 10], inv[N + 10];
ll H, W, A, B;

ll PowMod(ll a,ll b) {
	ll res = 1;
	while(b) {
		if(b & 1) res = res * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return res;
}

void pre() {
	fac[0] = inv[0] = 1;
	for(int i = 1;i <= N; ++i) 
		fac[i] = fac[i - 1] * i % mod;
	inv[N] = PowMod(fac[N], mod - 2);
	for(int i = N - 1;i >= 1; --i)
		inv[i] = inv[i + 1] * (i + 1) % mod;
}

ll C(ll n, ll m) {
	if(n == 0 || m == 0) return 1;
	ll res = 1;
	res = res * fac[n] % mod;
	res = res * inv[n - m] % mod;
	res = res * inv[m] % mod;
	return res;
}

int main() {
	cin >> H >> W >> A >> B;
	pre(); // 2 3 1 1
	ll ans = 0; 
	for(int i = 1;i <= H - A; ++i) 
		ans = (ans + (C(i + B - 2, i - 1) * C(H - i + W - B - 1, H - i) % mod))% mod;
	cout << ans << endl;
	return 0;
}