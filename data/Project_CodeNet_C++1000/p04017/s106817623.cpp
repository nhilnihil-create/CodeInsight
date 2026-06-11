#include <cstdio>
#include <algorithm> 

const int MAXN = 1e5 + 1;

int n, l, q, x[MAXN];

int f[MAXN][31];
void prework() {
	for (int i = 1; i <= n; ++i) {
		int pos = std :: upper_bound(x + 1, x + n + 1, x[i] + l) - x - 1;
		f[i][0] = x[i] + l >= x[n] ? n : pos;
	}
	for (int j = 1; j <= 30; ++j) for (int i = 1; i <= n; ++i) f[i][j] = f[f[i][j - 1]][j - 1];
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) scanf("%d", &x[i]);
	scanf("%d%d", &l, &q);
	prework();
	while (q--) {
		int a, b; scanf("%d%d", &a, &b);
		if (a > b) std :: swap(a, b);
		int p = a, ans = 0;
		for (int j = 30; ~j; --j) if (f[p][j] < b) ans += (1 << j), p = f[p][j];
		printf("%d\n", ans + 1);
	}
	return 0;
}