#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 9, P = 1e9 + 7;

int f[N], n, g[N], ans;

void up (int &x, int y) { x += y; if (x >= P) x -= P; }

int main () {
	scanf("%d", &n);
	int S = 1ll * (n - 1) * (n - 1) % P;
	g[0] = f[0] = 1;
	for (int i = 1, j; i < n; ++i) {
		f[i] = (g[i - 1] - (i > 1 ? f[i - 2] : 0) + P) % P;
		j = (min(i + 1, n - 1) + S) % P;
		ans = (1ll * f[i - 1] * j + ans) % P;
		g[i] = (g[i - 1] + f[i]) % P;
	}
	ans = (1ll * f[n - 1] * n + ans) % P;
	printf("%d\n", ans);
	return 0;
}