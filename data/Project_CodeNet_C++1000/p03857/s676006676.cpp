#include<bits/stdc++.h>
using namespace std;

const int N = 2 * 1000 * 100 + 10;
int n, K, L, col[2][N], cnt[2], ans[N];
vector<int> adj[2][N];
bool vis[2][N];
map<pair<int, int>, int> res;
	

void dfs(int root, bool tp) {
	if (tp) {
		res[make_pair(cnt[tp], col[0][root])]++;
		res[make_pair(col[0][root], cnt[tp])]++;
	}
	vis[tp][root] = true;
	col[tp][root] = cnt[tp];
	for (auto u: adj[tp][root])
		if (!vis[tp][u])
			dfs(u, tp);
}

int main() { 
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n >> K >> L;
	for (int i = 1, v, u; i <= K; i++) {
		cin >> v >> u;
		adj[0][v].push_back(u);
		adj[0][u].push_back(v);
	}
	for (int i = 1, v, u; i <= L; i++) {
		cin >> v >> u;
		adj[1][v].push_back(u);
		adj[1][u].push_back(v);
	}
	for (int i = 1; i <= n; i++)
		ans[i] = 1;
	for (int i = 1; i <= n; i++)
		if (!vis[0][i]) {
			cnt[0]++; 
			dfs(i, 0);
		}
	cnt[1] = cnt[0];
	for (int i = 1; i <= n; i++)
		if (!vis[1][i]) {
			cnt[1]++;
			dfs(i, 1);
		}
	for (int i = 1; i <= n; i++)
		cout << res[make_pair(col[0][i], col[1][i])] << ' ';
	cout << endl;
	return 0;
}
