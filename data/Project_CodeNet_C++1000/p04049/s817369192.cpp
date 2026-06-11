#include <cstdio>
#include <vector>

const int MN = 2005;

int N, K, eu[MN], ev[MN];
std::vector<int> G[MN];

int dep[MN];
void DFS(int u, int p) {
	for (int v : G[u]) if (v != p) dep[v] = dep[u] + 1, DFS(v, u);
}

int main() {
	scanf("%d%d", &N, &K);
	for (int i = 1; i < N; ++i) {
		scanf("%d%d", &eu[i], &ev[i]);
		G[eu[i]].push_back(ev[i]);
		G[ev[i]].push_back(eu[i]);
	}
	int Ans = N;
	if (K & 1) {
		for (int i = 1; i < N; ++i) {
			int u = eu[i], v = ev[i];
			dep[u] = dep[v] = 0;
			DFS(u, v), DFS(v, u);
			int cnt = 0;
			for (int j = 1; j <= N; ++j) if (dep[j] > K / 2) ++cnt;
			Ans = Ans > cnt ? cnt : Ans;
		}
	} else {
		for (int i = 1; i <= N; ++i) {
			dep[i] = 0, DFS(i, 0);
			int cnt = 0;
			for (int j = 1; j <= N; ++j) if (dep[j] > K / 2) ++cnt;
			Ans = Ans > cnt ? cnt : Ans;
		}
	}
	printf("%d\n", Ans);
	return 0;
}