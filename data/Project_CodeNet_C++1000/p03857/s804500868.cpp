#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int n, K, L;
int par[N];
int a[N];
vector < pair<int,int> > G[N];
int ans[N];

int find(int p) { return p == par[p] ? p : par[p] = find(par[p]); }
void join(int p, int q) { par[find(p)] = find(q); }

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> K >> L;

	for (int i = 1; i <= n; ++i) par[i] = i;
	while(K--) {
		int u, v; cin >> u >> v;
		if (find(u) != find(v)) join(u, v);
	}
	for (int i = 1; i <= n; ++i) a[i] = find(i);

	for (int i = 1; i <= n; ++i) par[i] = i;
	while(L--) {
		int u, v; cin >> u >> v;
		if (find(u) != find(v)) join(u, v);
	}
	for (int i = 1; i <= n; ++i) G[find(i)].push_back(make_pair(a[i], i));

	for (int i = 1; i <= n; ++i) {
		sort(G[i].begin(), G[i].end());
		for (int j = 0; j < G[i].size(); ) {
			int k = j, val = G[i][j].first;
			while(j < G[i].size() && G[i][j].first == val) ++j;
			for (int l = k; l < j; ++l) {
				ans[G[i][l].second] = j - k;
			}
		}
	}

	for (int i = 1; i <= n; ++i) printf("%d ", ans[i]); printf("\n");
}