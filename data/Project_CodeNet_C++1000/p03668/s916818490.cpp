#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
int n, nim[N];
vector<int> g[N];

void dfs(int u, int f) {
	for(int v : g[u]) if(v != f)
		dfs(v,u);
	for(int v : g[u]) if(v != f) {
		nim[u] ^= (nim[v] + 1);
	}
}

int main() {
	scanf("%d", &n);
	for(int i = 1; i < n; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1,-1);
	if(nim[1] == 0) puts("Bob");
	else puts("Alice");
	return 0;
}