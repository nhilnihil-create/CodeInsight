#include <bits/stdc++.h>

using namespace std;

const int N = 2000 + 7;
int n, k, mindel[N][N], dep[N][N];
vector<int> g[N];
bool vis[N];

void dfs(int a) {
  mindel[a][0] = 1;
  vector<int> kids;
  vis[a] = 1;
  for (auto &b : g[a]) {
    if (vis[b] == 0) {
      dfs(b);
      mindel[a][0] += mindel[b][0];
      kids.push_back(b);
    }
  }
  if (kids.empty()) {
    for (int i = 1; i <= k; i++) {
      mindel[a][i] = 0;
    }
    return;
  }
  for (int len = 1; len <= k; len++) {
    int other = k - len;
    other = min(other, len - 1);
    int sum = 0, mx = (int) 1e9;
    for (auto &b : kids) {
      sum += mindel[b][other];
      mx = min(mx, mindel[b][len - 1] - mindel[b][other]);
    }
    mindel[a][len] = min(mindel[a][len - 1], sum + mx);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> n >> k;
  k++;
  for (int i = 1; i < n; i++) {
    int x, y;
    cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  dfs(1);
  int ans = (int) 1e9;
  for (int i = 1; i <= n; i++) {
    ans = min(ans, mindel[i][k] + n - mindel[i][0]);
  }
  cout << ans << "\n";
}
