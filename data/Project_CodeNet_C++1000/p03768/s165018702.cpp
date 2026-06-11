#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
vector<int> g[100000];
int dp[100000][15] = {};
signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int n, m, q;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    a--; b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  cin >> q;
  vector<int> c(q + 1);
  for (int i = 1; i <= q; i++) {
    int v, d;
    cin >> v >> d >> c[i];
    v--;
    dp[v][d] = max(dp[v][d], i);
  }
  for (int i = 10; i >= 1; i--) {
    for (int j = 0; j < n; j++) {
      for (int nbr : g[j]) {
        dp[nbr][i - 1] = max(dp[nbr][i - 1], dp[j][i]);
      }
    }
  }
  for (int i = 0; i < n; i++) {
    int t = 0;
    for (int j = 0; j <= 10; j++) {
      t = max(t, dp[i][j]);
    }
    cout << c[t] << endl;
  }
  return 0;	
}