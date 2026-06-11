#include <cstdio>
#include <vector>

const int MN = 100005;

int N;
std::vector<int> G[MN];

int DFS(int u, int p) {
	int ret = 0;
	for (int v : G[u]) if (v != p) ret ^= DFS(v, u) + 1;
	return ret;
}

int main() {
	scanf("%d", &N);
	for (int i = 1, x, y; i < N; ++i)
		scanf("%d%d", &x, &y),
		G[x].push_back(y),
		G[y].push_back(x);
	puts(DFS(1, 0) ? "Alice" : "Bob");
	return 0;
}