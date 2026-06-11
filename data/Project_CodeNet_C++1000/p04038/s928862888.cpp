#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> P;
template<typename T> inline void chkmin(T &a, const T &b) { a = a < b ? a : b; }
template<typename T> inline void chkmax(T &a, const T &b) { a = a > b ? a : b; }

const int MAXN = 2005, MAXM = 4000005, MOD = 1e9 + 7;
int f[MAXN][MAXN], g[MAXM], inv[MAXM], n, K;

int main() {
	scanf("%d%d", &n, &K);
	if (K == 1) return puts("1") * 0;
	inv[1] = 1;
	for (int i = 2; i <= n * K; i++)
		inv[i] = MOD - (LL)MOD / i * inv[MOD % i] % MOD;
	g[K - 2] = 1;
	for (int i = K - 1; i <= n * K; i++)
		g[i] = (LL)g[i - 1] * i % MOD * inv[i - K + 2] % MOD;
	f[n][n] = 1;
	for (int i = n - 1; i >= 0; i--)
	for (int j = n; j >= i; j--)
		f[i][j] = (f[i + 1][j] + (LL)f[i][j + 1] * g[i + (K - 1) * (j + 1) - 1] % MOD * (j + 1)) % MOD;
	printf("%d\n", f[0][0]);
	return 0;
}