#include <bits/stdc++.h>
using namespace std;
 
#define rep(i, N) for (int i = 0; i < N; i++)
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> i_i;
 
const int MOD = 1e9 + 7;
const int INF = INT_MAX / 2;
 
vector<int> bfs(int N, vector<vector<int> >& G, int s) {
	vector<int> d(N, INF); d[s] = 0;
	queue<int> q; q.push(s);
	while (q.size()) {
		int u = q.front(); q.pop();
		for (int v : G[u])
			if (d[v] > d[u] + 1) {
				d[v] = d[u] + 1;
				q.push(v);
			}
	}
	return d;
}
 
int main() {
	int N; cin >> N;
	vector<vector<int> > G(N);
	rep(i, N - 1) {
		int u, v; scanf("%d%d", &u, &v);
		u--, v--;
		G[u].pb(v), G[v].pb(u);
	}
	vector<int> d1 = bfs(N, G, 0);
	vector<int> d2 = bfs(N, G, N - 1);
	int n1 = 0, n2 = 0;
	rep(u, N) if (d1[u] <= d2[u]) n1++; else n2++;
	cout << (n1 > n2 ? "Fennec" : "Snuke") << endl;
}