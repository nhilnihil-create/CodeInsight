#include <bits/stdc++.h>
#define mset(a, b) memset(a, b, sizeof(a))
using namespace std;
typedef long long LL;
const int MAXN = 200005;
const LL MOD = 1e9 + 7;

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

int n, m, a, b;
LL fac[MAXN], inv[MAXN], finv[MAXN];

inline LL C(int x, int y) {
	return fac[x] * finv[y] % MOD * finv[x-y] % MOD;
}

inline LL Calc(int x, int y) {
	return C(x+y-2, x-1);
}

void init() {
	read(n); read(m); read(a); read(b);
	fac[0] = fac[1] = inv[0] = inv[1] = finv[0] = finv[1] = 1;
	for (int i=2;i<=n+m;++i) {
		fac[i] = fac[i-1] * i % MOD;
		inv[i] = (MOD-MOD/i) * inv[MOD%i] % MOD;
		finv[i] = finv[i-1] * inv[i] % MOD;
	}
}

void solve() {
	LL ans = Calc(n, m);
	for (int i=1;i<=b;++i) {
		ans = (ans - Calc(n-a, i) * Calc(a, m-i+1) % MOD + MOD) % MOD;
	}
	printf("%lld\n", ans);
}

int main() {
	init();
	solve();
	return 0;
}
