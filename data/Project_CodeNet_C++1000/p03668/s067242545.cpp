#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 1e5 + 5;

vector<int> adj [MAX_N];
int dp [MAX_N];

void dfs (int u, int p) {
  for (int nxt : adj[u]) {
    if (nxt != p) {
      dfs(nxt, u);

      dp[u] ^= dp[nxt] + 1;
    }
  }
}

int main () {
  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;

    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  dfs(1, 0);

  if (dp[1] == 0) {
    cout << "Bob" << endl;
  } else {
    cout << "Alice" << endl;
  }
}
