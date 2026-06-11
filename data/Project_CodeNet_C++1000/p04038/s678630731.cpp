#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD = 1000000007;
const int MAXN = 2010;

ll fac[MAXN*MAXN], ifac[MAXN*MAXN];

inline ll qpow(ll a, ll b) {
	ll res = 1;
	while(b) {
		if(b & 1LL) res = res * a % MOD;
		b >>= 1, a = a * a % MOD;
	}
	return res;
}

int n, k;
ll dp[MAXN][MAXN];

inline ll binom(int x, int y) {
	return fac[x]*ifac[y]%MOD*ifac[x-y]%MOD;
}

inline void update(ll &cur, ll val) {
	cur = cur+val;
	if(cur >= MOD) cur -= MOD;
}

int main() {

	int i, j;
	scanf("%d%d", &n, &k);
	if(k == 1) {
		printf("1\n");
		return 0;
	}
	fac[0] = 1;
	for(i = 1; i <= n*k; i++) fac[i] = fac[i-1]*i%MOD;
	ifac[n*k] = qpow(fac[n*k], MOD-2);
	for(i = n*k; i >= 1; i--) ifac[i-1] = ifac[i]*i%MOD;
	dp[n][n] = 1;
	for(i = n; i >= 0; i--) {
		for(j = n; j >= i; j--) {
			if(i == 0 && j == 0) continue;
			if(i != 0) update(dp[i-1][j], dp[i][j]);
			if(j != i) {
				update(dp[i][j-1], dp[i][j]*binom(j*(k-1)+i-1, k-2)%MOD);
			}
		}
	}
	printf("%lld\n", dp[0][0]*fac[n]%MOD);
	return 0;
}