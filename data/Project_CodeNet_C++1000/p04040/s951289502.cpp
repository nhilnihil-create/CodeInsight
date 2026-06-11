#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
const int MAX = 1234567;

long long fac[MAX], finv[MAX], inv[MAX];

inline void mod_add(long long &x, long long y) {
	x += y;
	if(x >= mod) x -= mod;
}

inline void mod_sub(long long &x, long long y) {
	x -= y;
	if(x < 0) x += mod;
}

inline long long mod_mul(long long x, long long y) {
	return (long long) (x % mod * y % mod);
}

inline long long mod_inv(long long x) {
	x %= mod;
	if(x < 0) x += mod;
	long long y = mod, u = 0, v = 1;
	while(y) {
		long long t = y / x;
		y -= t * x; swap(x, y);
		u -= t * v; swap(u, v);
	}
	if(u < 0) u += mod;
	return u;
}

inline long long mod_pow(long long x, long long y) {
	long long res = 1;
	while(y) {
		if(y & 1) res = mod_mul(res, x);
		x = mod_mul(x, x);
		y >>= 1;
	}
	return res;
}

inline void pre_mod_nCk() {
	fac[0] = fac[1] = 1;
	finv[0] = finv[1] = 1;
	inv[1] = 1;
	for(int i = 2; i < MAX; i++) {
		fac[i] = mod_mul(fac[i - 1], i);
		inv[i] = mod - mod_mul(inv[mod % i], mod / i);
		finv[i] = mod_mul(finv[i - 1], inv[i]);
	}
}

inline long long mod_nCk(int n, int k) {
	if(n < k) return 0;
	if(n < 0 || k < 0) return 0;
	return mod_mul(fac[n], mod_mul(finv[k], finv[n - k]));
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);  
	pre_mod_nCk();
	int h, w, a, b;
	cin >> h >> w >> a >> b;
	long long ans = 0;
	for(int i = 0; i < h - a; i++) {
		mod_add(ans, mod_mul(mod_nCk(b - 1 + i, i), mod_nCk((w - 1 - b) + (h - 1 - i), h - 1 - i)));
	}
	cout << ans << '\n';
	return 0;	
}
