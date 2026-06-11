#include <bits/stdc++.h>

using namespace std;

const int N = 100100;

vector <int> adj[N];
int v[N], d[N], c[N];

int col[N];
int pass[N];
int dist[N];
int func[N][13];

void dfs(int v, int d, int c) {
	if(d == -1) return;
	if(func[v][d] == 0) {
		func[v][d] = 1;
		if(col[v] == 0) {
			col[v] = c;
		}
		dfs(v, d-1, c);
		for (int x: adj[v]) {
			dfs(x, d-1, c);
		}
	}
}

int main() {
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	int q;
	cin >> q;

	for (int i = 0; i < q; ++i) {
		cin >> v[i] >> d[i] >> c[i];
		v[i]--;
	}

	for (int i = q-1; i >= 0; --i) {
		dfs(v[i], d[i], c[i]);
	}
	for (int i = 0; i < n; ++i) {
		printf("%d\n", col[i]);
	}

}