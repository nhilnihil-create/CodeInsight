#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_N = 1e5 + 5;

vector<int> adj [MAX_N];
int dp [MAX_N];

void dfs (int u) {
  vector<int> dps;
  for (int nxt : adj[u]) {
    dfs(nxt);
    dps.push_back(dp[nxt]);
  }

  sort(dps.begin(), dps.end(), greater<int>());
  for (int i = 0; i < (int) dps.size(); i++) {
    dp[u] = max(dp[u], dps[i] + i);
  }
  dp[u]++;
}

int main () {
  ios::sync_with_stdio(false);

  int n;
  cin >> n;
  for (int i = 2; i <= n; i++) {
    int p;
    cin >> p;

    adj[p].push_back(i);
  }

  dfs(1);

  cout << dp[1] - 1 << endl;
}
