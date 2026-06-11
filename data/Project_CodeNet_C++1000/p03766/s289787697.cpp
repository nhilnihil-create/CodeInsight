# include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn(1e6 + 5);
const int mod(1e9 + 7);

inline void Inc(int &x, const int y) {
    x = x + y >= mod ? x + y - mod : x + y;
}

inline void Dec(int &x, const int y) {
    x = x - y < 0 ? x - y + mod : x - y;
}

inline int Add(const int x, const int y) {
    return x + y >= mod ? x + y - mod : x + y;
}

inline int Sub(const int x, const int y) {
    return x - y < 0 ? x - y + mod : x - y;
}

inline int Pow(ll x, int y) {
    int ret = 1;
    for (; y; y >>= 1, x = x * x % mod)
        if (y & 1) ret = ret * x % mod;
    return ret;
}

int n, f[maxn], ans;

inline void Solve() {
	int i, sum = 0;
	ans = 0, memset(f, 0, sizeof(f));
	for (i = 1; i <= n; ++i) {
		if (i < 3) f[i] = 1;
		else f[i] = Add(Sub(f[i - 1], f[i - 2]), f[i - 3]);
		if (i <= n - 1) Inc(ans, (ll)f[i] * Add((ll)(n - 1) * (n - 1) % mod, min(n - 1, i + 1)) % mod);
		else Inc(ans, (ll)f[i] * n % mod);
		Inc(f[i], f[i - 1]);
	}
	printf("%d\n", ans);
}

int main() {
	while (scanf("%d", &n) != EOF) Solve();
	return 0;
}