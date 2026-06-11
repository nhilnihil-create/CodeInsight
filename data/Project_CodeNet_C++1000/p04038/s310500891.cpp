#include<bits/stdc++.h>
#define rep(i,a,b) for (int i=(a); i<=(b); i++)
#define per(i,a,b) for (int i=(a); i>=(b); i--)
using namespace std;

const int maxn = 2005;
const int mod = 1000000007;
int fac[maxn*maxn], rev[maxn*maxn], f[maxn<<1][maxn];
int n, K, ans;

inline int power(int x, int p) {
	int res = 1;
	while (p) {
		if (p & 1) res = 1ll * res * x % mod;
		x = 1ll * x * x % mod; p >>= 1;
	}
	return res;
}

inline int C(int n, int m) {
	return 1ll * fac[n] * rev[m] % mod * rev[n-m] % mod;
}

int main() {
	scanf("%d%d", &n, &K);
	if (K == 1) return puts("1"), 0;
	fac[0] = rev[0] = 1;
	rep (i, 1, maxn*maxn-1) {
		fac[i] = 1ll * fac[i-1] * i % mod;
		rev[i] = power(fac[i], mod - 2);
	}
	f[0][0] = 1;
	rep (i, 1, n*2) rep (j, 0, n)
		if (f[i-1][j]) {
			if (j*2 > i-1) 
				f[i][j] = (f[i][j] + f[i-1][j]) % mod;
			f[i][j+1] = (f[i][j+1] + 1ll * f[i-1][j] * C(K * (i-1-j) + (K-1) * (2*j-i+1) + K-2, K-2)) % mod;
		}
	ans = 1ll * f[n*2][n] * fac[n] % mod;
	printf("%d\n", ans);
	return 0;
}