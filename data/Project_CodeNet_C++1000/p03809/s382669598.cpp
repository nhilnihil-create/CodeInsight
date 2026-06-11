#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int n, a[N], root;
vector<int> edge[N];

void dfs(int u, int p) {
	int sum = 0, mx = 0;
	for(int i = 0; i < edge[u].size(); ++i) {
		int v = edge[u][i];
		if(v == p) continue;
		dfs(v, u);
		sum += a[v];
		mx = max(mx, a[v]);
	}
	if(edge[u].size() == 1) return;
	int x = sum - a[u], y = sum - 2 * x;
	if(x < 0 || y < 0) { cout << "NO"; exit(0); }
	if(mx <= sum / 2 && x > sum / 2) { cout << "NO"; exit(0); }
	if(mx > sum / 2 && x > sum - mx) { cout << "NO"; exit(0); } 
	a[u] = y;
}

int main() {
	cin >> n;
	for(int i = 1; i <= n; ++i) cin >> a[i];
	for(int i = 1; i < n; ++i) {
		int u, v;
		cin >> u >> v;
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	for(int i = 1; i <= n; ++i) if(edge[i].size() > 1) root = i;
	if(root) dfs(root, root);
	else if(a[1] != a[2]) { cout << "NO"; exit(0); }
	if(a[root]) { cout << "NO"; exit(0); }
	cout << "YES";
}