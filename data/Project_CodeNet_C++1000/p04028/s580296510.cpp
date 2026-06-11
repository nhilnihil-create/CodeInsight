#include <bits/stdc++.h>

const int MAXN = 5010;
const int mod = 1000000007;
typedef long long LL;
void reduce(int & x) { x += x >> 31 & mod; }
int mul(int a, int b) { return (LL) a * b % mod; }
int pow(int a, int b, int res = 1) {
	for (; b; b >>= 1, a = mul(a, a)) if (b & 1) res = mul(res, a);
	return res;
}
int f[MAXN][MAXN], n;
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	f[0][0] = 1; std::cin >> n;
	for (int i = 1; i <= n; ++i)
		for (int j = 0; j <= i; ++j) {
			reduce(f[i][j + 1] += mul(f[i - 1][j], 2) - mod);
			reduce(f[i][std::max(j - 1, 0)] += f[i - 1][j] - mod);
		}
	static char buf[MAXN]; std::cin >> buf; int len = strlen(buf);
	std::cout << pow(mod + 1 >> 1, len, f[n][len]) << std::endl;
	return 0;
}
