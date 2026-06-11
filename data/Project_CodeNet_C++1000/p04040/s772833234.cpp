#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

const int OO = 1e9;
const int MOD = 1e9 + 7;

const int MAXN = 2 * 123456;

int f[MAXN];

int power(int a, int b) {
	if (b == 0) return 1;
	int ans = power(a, b / 2);
	return (LL) ans * ans % MOD * (b % 2 == 1 ? a : 1) % MOD;
}

int C(int n, int r) {
	return (LL) f[n] * power(f[r], MOD - 2) % MOD * power(f[n - r], MOD - 2) % MOD;
}

void solve() {
	f[0] = 1;
	for (int i = 1; i < MAXN; ++i)
		f[i] = (LL) f[i - 1] * i % MOD;

	int h, w, a, b;
	scanf("%d%d%d%d", &h, &w, &a, &b);
	int ans = C(h + w - 2, w - 1);
	for (int i = 1; i <= b; ++i) {
		ans = (ans - (LL) C(h - a - 1 + i - 1, i - 1) * C(a - 1 + w - i, a - 1) % MOD + MOD) % MOD;
	}
	printf("%d\n", ans);
}

int32_t main() {
// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);

// 	clock_t begin = clock();
// #endif

	solve();

// #ifndef ONLINE_JUDGE
// 	clock_t end = clock();
// 	printf("ELAPSED TIME: %f\n", (double) (end - begin) / CLOCKS_PER_SEC);
// #endif

	return 0;
}
