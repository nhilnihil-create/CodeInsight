#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100010;
const int MAXD = 11;
const int MAXQ = 100010;
int N, M, Q;
vector<int> adj[MAXN];
bool vis[MAXN][MAXD];
int V[MAXQ], D[MAXQ], C[MAXQ];

int ans[MAXN];

void dfs(int cur, int prv, int d, int c) {
	if (vis[cur][d]) return;
	vis[cur][d] = true;
	if (ans[cur] == 0) {
		ans[cur] = c;
	}
	if (d == 0) return;
	for (int nxt : adj[cur]) {
		if (nxt == prv) continue;
		dfs(nxt, cur, d-1, c);
	}
}

int main() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < M; i++) {
		int a, b; scanf("%d %d", &a, &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	scanf("%d", &Q);
	for (int i = 0; i < Q; i++) {
		scanf("%d %d %d", &V[i], &D[i], &C[i]);
	}
	for (int i = Q-1; i >= 0; i--) {
		dfs(V[i], 0, D[i], C[i]);
	}

	for (int i = 1; i <= N; i++) {
		printf("%d\n", ans[i]);
	}

	return 0;
}
