#include <bits/stdc++.h>
using namespace std;

const int
	MAX = 5e5 + 5,
	MOD = 1e9 + 7;
int n, m, a, b, inv[MAX], f[MAX];

int exp(int a, int b) {
	if(b == 0)
		return 1;

	if(b & 1)
		return 1LL * a * exp(a, b - 1) % MOD;

	int sq = exp(a, b / 2);
	return 1LL * sq * sq % MOD;
}

int comb(int n, int k) {
	if(n < k)
		return 0;

	int ans = 1LL * f[n] * inv[k] % MOD;
	ans = 1LL * ans * inv[n - k] % MOD;

	return ans;
}

int ways(int f0, int c0, int f, int c) {
	return comb(f - f0 + c - c0, f - f0);
}

int main() {
	inv[0] = f[0] = 1;

	for(int i = 1; i < MAX; i++) {
		f[i] = 1LL * i * f[i - 1] % MOD;
		inv[i] = exp(f[i], MOD - 2);
	}

	scanf("%d%d%d%d", &n, &m, &a, &b);

	int ans = 0;
	for(int i = 1; i <= n - a; i++) {
		int w1 = ways(1, 1, i, b);
		int w2 = ways(i, b + 1, n, m);

		int v = 1LL * w1 * w2 % MOD;
		ans = (ans + v) % MOD;
	}

	printf("%d\n", ans);
	return 0;
}