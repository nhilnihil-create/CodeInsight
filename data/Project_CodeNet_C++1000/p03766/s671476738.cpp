#include <bits/stdc++.h>

const int mod = 1000000007;
typedef long long LL;
void reduce(int & x) { x += x >> 31 & mod; }
int mul(int a, int b) { return (LL) a * b % mod; }
int pow(int a, int b, int res = 1) {
	for (; b; b >>= 1, a = mul(a, a)) if (b & 1) res = mul(res, a);
	return res;
}
int remod(LL x) { x %= mod; return x + (x >> 63 & mod); }

const int MAXN = 1000010;
int f[MAXN], g[MAXN];

int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	int ans = 0, n; std::cin >> n;
	f[0] = g[0] = 1;
	for (int i = 1; i <= n; ++i) {
		reduce(f[i] += f[i - 1] - mod);
		if (i - 3 >= 0) reduce(f[i] += g[i - 3] - mod);
		reduce(g[i] = f[i] + g[i - 1] - mod);
		reduce(ans += mul(f[i - 1], std::min(i, n - 1)) - mod);
		if (i + 1 <= n)
		reduce(ans += mul(f[i - 1], mul(n - 1, n - 1)) - mod);
	}
	reduce(ans += f[n] - mod);
	std::cout << ans << std::endl;
	return 0;
}
