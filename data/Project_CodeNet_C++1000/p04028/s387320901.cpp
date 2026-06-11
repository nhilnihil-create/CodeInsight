#include <bits/stdc++.h>
using namespace std;
#define LL long long
const int maxn = 5010;
const int mod = 1e9 + 7;
int n;
char s[maxn];
int f[maxn][maxn];
LL Qpow(LL a, LL b) {
	LL ret = 1;
	for (; b; b >>= 1, a = (a * a) % mod) if(b & 1) ret = (ret * a) % mod;
	return ret;
}
int main() {
	scanf("%d%s", &n, s + 1);
	int len = strlen(s + 1);
	f[0][0] = 1;
	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j <= i; ++j) {
			f[i + 1][j + 1] = (f[i + 1][j + 1] + 2 * f[i][j] % mod) % mod;
			f[i + 1][max(j - 1, 0)] = (f[i + 1][max(j - 1, 0)] + f[i][j]) % mod;
		}
	}
	LL ans = (1ll * Qpow(Qpow(2, len), mod - 2) % mod * f[n][len] % mod) % mod;
	printf("%lld\n", ans);
	return 0;
}