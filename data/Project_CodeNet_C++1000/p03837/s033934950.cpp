#include <bits/stdc++.h>
using namespace std;

#define int long long

#define ii pair<int,int>
#define fi first
#define sc second

#define all(x) (x).begin(),(x).end()

struct edge {
  int u, v, w;
  edge() {}
  edge(int u, int v, int w):
    u(u), v(v), w(w) {}
};

void chmin(int &a, int b) {
  if (a > b) a = b;
}

void solve() {
  int n, m;
  cin >> n >> m;
  vector<edge> edges;
  vector<vector<int>> dist(n + 1, vector<int>(n + 1, 2e9));
  for (int i = 1; i <= m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    dist[u][v] = dist[v][u] = w;
    edges.push_back(edge(u, v, w));
  }
  for (int k = 1; k <= n; k++)
  for (int i = 1; i <= n; i++)
  for (int j = 1; j <= n; j++) {
    chmin(dist[i][j], dist[i][k] + dist[k][j]);
  }
  int ans = 0;
  for (auto &i : edges) {
    if (dist[i.u][i.v] < i.w) ans++;
  }
  cout << ans << '\n';
}

signed main() {
#ifdef _DEBUG
  // freopen("in" , "r", stdin );
  // freopen("out", "w", stdout);
#endif
  ios::sync_with_stdio(0); cin.tie(0);
  int T = 1;
  // cin >> T;
  while (T--) solve();
}
