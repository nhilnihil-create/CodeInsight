#include<bits/stdc++.h>
using namespace std;

const int N = 2020, M = N * N;
const int MOD = 1e9 + 7;
int f[N][N], fra[M], inv[M];

int qpow(int a, int b) {
	int res = 1;
	for (; b; b >>= 1, a = 1ll * a * a % MOD)
		if (b & 1) res = 1ll * res * a % MOD;
	return res;
}
 
void init(int n) {
	fra[0] = 1;
	for (int i = 1; i <= n; i++) fra[i] = 1ll * fra[i - 1] * i % MOD;
	inv[n] = qpow(fra[n], MOD - 2);
	for (int i = n - 1; i >= 0; i--) inv[i] = 1ll * inv[i + 1] * (i + 1) % MOD;
}

int C(int n, int m) {
	if (m > n) return 0;
	return 1ll * fra[n] * inv[n - m] % MOD * inv[m] % MOD;
}

int main() {
	init(2000 * 2000);
	int n, k;
	scanf("%d%d", &n, &k);
	if (k == 1) {
		printf("1\n");
		return 0;
	}
	for (int i = 0; i <= n; i++) f[i][0] = 1;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= i; j++)
			f[i][j] = (f[i - 1][j] + (long long)f[i][j - 1] * C(n * k - i - 1- (k - 1) * (j - 1), k - 2) % MOD) % MOD;
//	for (int i = 1; i <= n; i++)
//		for (int j = 0; j <= i; j++)
//			printf("%d%c", f[i][j], " \n"[j == i]);
	int ans = 1ll * f[n][n] * fra[n] % MOD;
	printf("%d\n", ans);
	return 0;
}