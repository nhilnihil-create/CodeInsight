/*
	简单容斥
*/
#include <iostream>
#include <cstdio>
#define N 200005

using namespace std;

const int mod = 1e9 + 7;

int n, m, A, B;
int fac[N], ifac[N];

inline int perm(int s, int r) { return 1LL * fac[s] * ifac[s - r] % mod; }
inline int comb(int s, int r) {	return 1LL * perm(s, r) * ifac[r] % mod; }
inline int calc(int a, int b, int c, int d) { return comb(c - a + d - b, c - a); }

inline int fpm(int bs, int mi) {
	int res = 1;
	while(mi) {
		if(mi & 1) res = 1LL * res * bs % mod;
		bs = 1LL * bs * bs % mod, mi >>= 1;
	}
	return res;
}

int main() {
	cin >> n >> m >> A >> B;

	fac[0] = 1;
	for(int i = 1; i <= n + m; ++i) fac[i] = 1LL * i * fac[i - 1] % mod;
	ifac[n + m] = fpm(fac[n + m], mod - 2);
	for(int i = n + m; i; --i) ifac[i - 1] = 1LL * i * ifac[i] % mod;
	
	int ans = calc(1, 1, n, m);
	for(int i = 1; i <= B; ++i) {
		ans = (ans - 1LL * calc(1, 1, n - A, i) * calc(n - A + 1, i, n, m)) % mod;
		if(ans < 0) ans += mod;
	}
	cout << ans << endl;
	return 0;
}