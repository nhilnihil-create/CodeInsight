#include <cstdio>
#include <vector>

const int MAXN = 1e5 + 100;

int n, m, Q;
int x[MAXN], d[MAXN], c[MAXN];

std::vector<int> edge[MAXN << 1];

int col[MAXN][20];

void Dfs(int x, int d, int c) {
	if (d == -1 || col[x][d])
		return;
	col[x][d] = c;
	for (int i = 0; i < edge[x].size(); ++i) {
		int y = edge[x][i];
		Dfs(y, d - 1, c);
	}
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		edge[u].push_back(v), edge[v].push_back(u);
	}
	for (int i = 1; i <= n; ++i)
		edge[i].push_back(i);

	scanf("%d", &Q);
	for (int i = 1; i <= Q; ++i)
		scanf("%d%d%d", &x[i], &d[i], &c[i]);

	for (int i = Q; i; --i)
		Dfs(x[i], d[i], c[i]);
	
	for (int i = 1; i <= n; ++i)
		printf("%d\n", col[i][0]);
	return 0;
}