#include <cstdio>
#include <vector>

typedef long long LL;
const int MN = 100005;

int N, M;
std::vector<int> G[MN];

int w, o[2], vis[MN], col[MN];
void DFS(int u, int c) {
	vis[u] = 1, ++o[col[u] = c];
	for (int v : G[u])
		if (!vis[v]) DFS(v, c ^ 1);
		else if (col[u] == col[v]) w = 1;
}

int main() {
	scanf("%d%d", &N, &M);
	for (int i = 1, x, y; i <= M; ++i) {
		scanf("%d%d", &x, &y);
		G[x].push_back(y);
		G[y].push_back(x);
	}
	int a = 0, b = 0, c = 0;
	for (int i = 1; i <= N; ++i) if (!vis[i]) {
		w = o[0] = o[1] = 0, DFS(i, 0);
		++(w ? c : o[1] ? b : a);
	}
	printf("%lld\n", 2ll * a * N - (LL)a * a + 2ll * b * b + 2ll * b * c + (LL)c * c);
	return 0;
}