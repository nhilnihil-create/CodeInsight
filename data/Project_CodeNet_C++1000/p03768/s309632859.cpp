#include <bits/stdc++.h>

inline int read() {
	int ret, cc;
	while (!isdigit(cc = getchar()));
	ret = cc - 48;
	while ( isdigit(cc = getchar()))
		ret = cc - 48 + ret * 10;
	return ret;
}

const int MAXN = 100010;

std::vector<int> G[MAXN];

int dp[MAXN][20];
int A[MAXN];
int B[MAXN];
int C[MAXN];
int n, m, q;

void Dfs(int u, int d, int t) {
	if (d < 0) return;
	if (dp[u][d] >= t) return;
	dp[u][d] = t;
	for (auto v : G[u]) Dfs(v, d - 1, t);
}

int main() {
	n = read(), m = read();
	for (int i = 1, x, y; i <= m; ++i) {
		x = read(), y = read();
		G[x].push_back(y), G[y].push_back(x);
	}
	q = read();
	for (int i = 1; i <= q; ++i) 
		A[i] = read(), B[i] = read(), C[i] = read();
	for (int i = q; i >= 1; --i) Dfs(A[i], B[i], i);
	for (int i = 1; i <= n; ++i) {
		int x = 0;
		for (int j = 0; j <= 10; ++j) 
			x = std::max(x, dp[i][j]);
		printf("%d\n", C[x]);
	}
}
