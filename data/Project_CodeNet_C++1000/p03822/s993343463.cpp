#include <cstdio>
#include <algorithm>
#include <vector>

const int MN = 100005;

int N;
std::vector<int> G[MN];

int dp[MN];
void DFS(int u) {
	for (int v : G[u]) DFS(v);
	static int seq[MN];
	int t = 0;
	for (int v : G[u]) seq[++t] = dp[v];
	std::sort(seq + 1, seq + t + 1);
	for (int i = 1; i <= t; ++i) dp[u] = std::max(dp[u], seq[i] + t - i + 1);
}

int main() {
	scanf("%d", &N);
	for (int i = 2, x; i <= N; ++i) scanf("%d", &x), G[x].push_back(i);
	DFS(1);
	printf("%d\n", dp[1]);
	return 0;
}