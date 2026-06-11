#include <cstdio>
#include <algorithm>
#include <vector>

typedef long long LL;
const int MN = 100005;

int N, A[MN], deg[MN];
std::vector<int> G[MN];

LL DFS(int u, int p) {
	int cnt = 0;
	LL sum = 0, mxv = 0;
	for (int v : G[u]) if (v != p) {
		LL x = DFS(v, u);
		if (x == -1) return -1;
		++cnt, sum += x, mxv = std::max(mxv, x);
	}
	if (!cnt) return A[u];
	if (A[u] > sum || A[u] < mxv || 2 * A[u] < sum) return -1;
	return 2 * A[u] - sum;
}

int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; ++i) scanf("%d", &A[i]);
	for (int i = 1, x, y; i < N; ++i) {
		scanf("%d%d", &x, &y);
		G[x].push_back(y);
		G[y].push_back(x);
		++deg[x], ++deg[y];
	}
	if (N == 2) return printf(A[1] == A[2] ? "YES" : "NO"), 0;
	int s = 0;
	for (int i = 1; i <= N; ++i) if (deg[i] > 1) s = i;
	puts(DFS(s, 0) == 0 ? "YES" : "NO");
	return 0;
}