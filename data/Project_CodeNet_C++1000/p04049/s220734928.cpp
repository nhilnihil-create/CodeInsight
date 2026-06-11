#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 2e3 + 5;

vector<int> adj [MAX_N];

void dfs (int u, int p, int lft, int &cur) {
  if (lft < 0) cur++;
  for (int nxt : adj[u]) {
    if (nxt != p) {
      dfs(nxt, u, lft - 1, cur);
    }
  }
}

int main () {
  int n, K;
  cin >> n >> K;

  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;

    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  int ans = MAX_N;

  // try to root at all vertices
  for (int i = 1; i <= n; i++) {
    int cur = 0;
    dfs(i, 0, K / 2, cur);
    ans = min(ans, cur);
  }

  // try to root at all edges
  for (int u = 1; u <= n; u++) {
    for (int v : adj[u]) {
      int cur = 0;
      dfs(u, v, (K - 1) / 2, cur);
      dfs(v, u, (K - 1) / 2, cur);
      ans = min(ans, cur);
    }
  }

  cout << ans << endl;
}
