#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int N;
bitset<200002> vis[2];
vi G[2][200002];
map<ii, vi> mp;

struct UFDS {
	int p[200002], rank[200002] = { 0 };
	int find_set(int i) { return (p[i] == i) ? i : (p[i] = find_set(p[i])); }
	bool same_set(int i, int j) { return find_set(i) == find_set(j); }
	void union_set(int i, int j) {
		if (same_set(i, j)) return;
		int x = find_set(i), y = find_set(j);
		rank[x] > rank[y] ? p[y] = x : p[x] = y;
		if (rank[x] == rank[y]) rank[y]++;
 	}
} U[2];

void dfs(int i, int u) {
	vis[i][u] = 1;
	for (auto v : G[i][u]) {
		if (!vis[i][v]) {
			U[i].union_set(u, v);
			dfs(i, v);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int K[2]; cin >> N >> K[0] >> K[1];
	for (int i = 0; i < 2; ++i) {
		while (K[i]--) {
			int u, v; cin >> u >> v;
			G[i][u].push_back(v), G[i][v].push_back(u);
		}
	}
	for (int u = 1; u <= N; u++) U[0].p[u] = U[1].p[u] = u;
	for (int i = 0; i < 2; ++i) {
		for (int u = 1; u <= N; ++u) {
			if (!vis[i][u]) dfs(i, u);
		}
	}
	for (int u = 1; u <= N; ++u)
		mp[ii(U[0].find_set(u), U[1].find_set(u))].push_back(u);
	for (int u = 1; u <= N; ++u)
		cout << mp[ii(U[0].find_set(u), U[1].find_set(u))].size() << ' ';
}