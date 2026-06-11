#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

const int MAX_N = 1e5 + 5;

vector<int> adj [MAX_N];
int vis [MAX_N];

void dfs (int u, int col, int &bip) {
  vis[u] = col;
  for (int nxt : adj[u]) {
    if (vis[nxt] == 0) {
      dfs(nxt, -col, bip);
    } else if (vis[nxt] == col) {
      bip = 0;
    }
  }
}

int main () {
  ios::sync_with_stdio(false);

  int n, m;
  cin >> n >> m;

  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;

    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  ll singl = 0, ev = 0, od = 0;
  for (int i = 1; i <= n; i++) {
    if (adj[i].empty()) {
      singl++;
    } else {
      if (vis[i] == 0) {
        int bip = 1;
        dfs(i, 1, bip);
        if (bip) ev++;
        else od++;
      }
    }
  }

  ll ans = 2 * (ll) n * singl - singl * singl;
  ans += 2 * ev * ev;
  ans += ev * od;
  ans += od * ev;
  ans += od * od;

  cout << ans << endl;
}
