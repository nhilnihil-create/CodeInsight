#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 9;
vector<int>V[N];
int n;

int Dfs (int u, int fa) {
	int sg = 0; for (auto v : V[u]) if (v != fa) sg ^= Dfs(v, u) + 1; return sg;
}

int main () {
	scanf("%d", &n);
	for (int i = 1, u, v; i < n; ++i) {
		scanf("%d%d", &u, &v);
		V[u].emplace_back(v);
		V[v].emplace_back(u);
	}
	puts(Dfs(1, 0) ? "Alice" : "Bob");
	return 0;
}