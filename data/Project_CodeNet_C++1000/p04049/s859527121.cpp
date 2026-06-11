#include <bits/stdc++.h>

using namespace std;

const int N = 2000 + 7;
int n, k, mindel[N][N], dep[N][N], under[N], rdp[N];
vector<int> g[N];
bool vis[N];

void dfs(int a) {
  vector<int> kids;
  under[a] = 1;
  vis[a] = 1;
  for (auto &b : g[a]) {
    if (vis[b] == 0) {
      dfs(b);
      rdp[a] = max(rdp[a], rdp[b]);
      under[a] += under[b];
      kids.push_back(b);
    }
  }
  if (kids.empty()) {
    mindel[a][0] = 1;
    for (int i = 1; i <= k; i++) {
      mindel[a][i] = 0;
    }
    return;
  }
  rdp[a]++;
  mindel[a][0] = under[a];
  for (int len = 1; len <= k; len++) {
    mindel[a][len] = (int) 1e9;
    int other = k - len;
    other = min(other, len - 1);
    for (auto &power : kids) {
      int cur = mindel[power][len - 1];
      for (auto &b : kids) {
        if (b != power) {
          cur += mindel[b][other];
        }
      }
      mindel[a][len] = min(mindel[a][len], cur);
    }
  }
  for (int i = 1; i <= k; i++) {
    mindel[a][i] = min(mindel[a][i], mindel[a][i - 1]);
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
    ans = min(ans, mindel[i][k] + n - under[i]);
  }
  cout << ans << "\n";
}
