#include <bits/stdc++.h>
#define mset(a, b) memset(a, b, sizeof(a))
#define mcpy(a, b) memcpy(a, b, sizeof(a))
#define rg register
using namespace std;
typedef long long LL;
const int MAXN = 1000005;
const int MOD = 1e9 + 7;

template <typename T> inline void read(T &AKNOI) {
	T x = 0, flag = 1;
	char ch = getchar();
	while (!isdigit(ch)) {
		if (ch == '-') flag = -1;
		ch = getchar();
	}
	while (isdigit(ch)) {
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	AKNOI = flag * x;
}

int n;
LL dp[MAXN], sum[MAXN];

inline void Inc(LL &x, LL y) {
	x += y; if (x >= MOD) x -= MOD;
}

void init() {
	read(n);
	dp[1] = 1;
	for (int i=1;i<=n;++i) {
		Inc(dp[i], dp[i-1]);
		if (i >= 3) Inc(dp[i], sum[i-3]);
		Inc(sum[i], sum[i-1]);
		Inc(sum[i], dp[i]);
	}
}

void solve() {
	LL ans = 0;
	for (int i=1;i<=n-1;++i) {
		ans = (ans + dp[i] * (n-1) % MOD * (n-1)) % MOD;
	}
	for (int i=1;i<=n-1;++i) {
		ans = (ans + dp[i] * min(i+1, n-1)) % MOD;
	}
	ans = (ans + dp[n] * n) % MOD;
	printf("%lld\n", ans);
}

int main() {
	init();
	solve();
	return 0;
}
