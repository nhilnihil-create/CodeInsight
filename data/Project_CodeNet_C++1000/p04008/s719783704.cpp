#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
const int MAXN = 100010;
using namespace std;

int N, K, Ans = 0;
bool vis[MAXN];
int fa[MAXN], dep[MAXN], seq[MAXN];
vector<int> G[MAXN];

void dfs(int u) {
	int i, v;
	for(i = 0; i < G[u].size(); i++) {
		v = G[u][i];
		dep[v] = dep[u] + 1, dfs(v);
	}
}
void dfsvis(int u) {
	int i, v;
	vis[u] = 1;
	for(i = 0; i < G[u].size(); i++) if(!vis[v = G[u][i]])
		dfsvis(v);
}

inline bool cmpdep(int x, int y) { return dep[x] > dep[y]; }
int main() {
	int u, i;
	scanf("%d%d", &N, &K);
	for(i = 1; i <= N; i++) scanf("%d", &fa[i]);
	for(i = 2; i <= N; i++) G[fa[i]].push_back(i);
	if(fa[1] != 1) Ans++;

	dfs(1);

	for(i = 1; i <= N; i++) seq[i] = i;
	sort(seq + 1, seq + N + 1, cmpdep);
	for(i = 1; i <= N; i++) if((u = seq[i]), (!vis[u] && dep[u] > K)) {
		for(int k = 1; k <= K - 1; k++) u = fa[u];
		dfsvis(u);

		Ans++;
	}
	printf("%d", Ans);
	return 0;
}
