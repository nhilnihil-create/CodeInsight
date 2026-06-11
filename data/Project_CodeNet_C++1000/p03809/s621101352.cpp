#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 9;
int n, A[N], root;
vector<int>V[N];
using ll = long long;

void Dfs (int u, int fa) {
	if (V[u].size() == 1) return ;
	ll S = -A[u], D = 0;
	for (auto v : V[u]) if (v != fa) {
		Dfs(v, u);
		S += A[v];
		if (A[v] > D) D = A[v];
	}
	if (S < 0) puts("NO"), exit(0);
	if (A[u] < D) puts("NO"), exit(0);
	A[u] -= S;
	if (A[u] < 0) puts("NO"), exit(0);
}

int main () {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) scanf("%d", &A[i]);
	if (n == 2) return puts(A[1] == 1 && A[2] == 1 ? "YES" : "NO"), 0;
	for (int i = 1, u, v; i < n; ++i) scanf("%d%d", &u, &v), V[u].emplace_back(v), V[v].emplace_back(u);
	for (int i = 1; i <= n; ++i) if (V[i].size() > 1) { root = i; break; }
	Dfs(root, 0);
	puts(A[root] ? "NO" : "YES");
	return 0;
}