#include <bits/stdc++.h>
using namespace std;

// ----------- define --------------
#define int long long
#define vi vector<int>
#define vc vector<char>
#define ii pair<int,int>
#define fi first
#define sc second
#define stoi stoll
#define all(x) (x).begin(),(x).end()
#define get_bit(x, k) ((x >> k) & 1)
// ---------------------------------

const int N = 100005;

vector<ii> adj[N];

int dis[N];

void dfs(int i, int p, int c) {
  dis[i] = c;
  for (auto &j : adj[i]) {
    if (j.fi == p) continue;
    dfs(j.fi, i, c + j.sc);
  }
}

void MAIN() {
  int n; cin >> n;
  for (int i = 1; i < n; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    adj[u].push_back(ii(v, w));
    adj[v].push_back(ii(u, w));
  }
  int q, k;
  cin >> q >> k;
  dfs(k, k, 0);
  for (int i = 0; i < q; i++) {
    int u, v;
    cin >> u >> v;
    cout << dis[u] + dis[v] << '\n';
  }
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int T = 1;
  // cin >> T;
  while (T--) MAIN();
}
