#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int n;
int sg[maxn];
vector<int> G[maxn]; 
void dfs(int u, int last) {
	for(int i = 0; i < G[u].size(); ++i) {
		int v = G[u][i];
		if(v == last) {
			continue;
		}
		dfs(v, u);
		sg[u] ^= sg[v] + 1;
	}
}
int main() {
	scanf("%d", &n);
	for(int i = 1; i < n; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs(1, 0);
	puts(sg[1] ? "Alice" : "Bob");
	return 0;
}