#include <bits/stdc++.h>
using namespace std;

const int maxN = 2001;
const int mod = 1e9 + 7;

long long n, k, dp[maxN][maxN], fac[maxN * maxN], inv_fac[maxN * maxN];

long long pow_mod (long long a, int b) {
	int ans = 1;
	while (b) {
		if (b & 1) { ans = (ans * a) % mod; }
		b >>= 1, a = (a * a) % mod;
	}
	return ans;
}

void init() {
	fac[0] = 1;
	for (register int i = 1; i <= maxN * maxN; i++) {
		fac[i] = (fac[i - 1] * i) % mod;
	}
	inv_fac[maxN * maxN] = pow_mod(fac[maxN * maxN], mod - 2);
	for (register int i = maxN * maxN - 1; i >= 0; i--) {
		inv_fac[i] = (inv_fac[i + 1] * (i + 1)) % mod;
	}
}

inline long long C(int m, int n) {
	return ((fac[n] * inv_fac[m] % mod) * inv_fac[n - m] % mod); 
}

int main() {
	scanf("%lld%lld", &n, &k);
	init();
	if (k == 1) {
		printf("1\n");
		return 0;
	}
	for (register int i = 0; i <= n; i++) {
		dp[i][0] = 1;
	}	
	for (register int i = 1; i <= n; i++) {
			for (register int j = 0; j <= i; j++) {
				if (!j) { continue; }
				dp[i][j] = (dp[i - 1][j] + (dp[i][j - 1] * (n - j + 1)) % mod * C(k - 2, n * k - i - (j - 1) * (k - 1) - 1)) % mod;
			}
	}
	printf("%lld\n", dp[n][n]);
	return 0;
}
