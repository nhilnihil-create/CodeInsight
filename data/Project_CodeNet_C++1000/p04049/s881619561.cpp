#include <bits/stdc++.h>

using namespace std;

#define sz(x) ((int) ((x).size()))
typedef long long ll;
typedef long double ld;

int n, k, s[3000], dp[3000][3000], sum[3000][3000];
vector<int> e[3000];

void dfs(int i = 0, int p = -1) {
  s[i] = 1;
  for (int j : e[i]) {
    if (j == p)
      continue;
    dfs(j, i);
    s[i] += s[j];
    for (int l = 0; l < k; l++)
      sum[i][l + 1] += dp[j][l];
  }
  sum[i][0] = s[i] - 1;
  for (int l = 0; 2 * l <= k; l++)
    dp[i][l] = sum[i][l];
  for (int l = k; 2 * l > k; l--)
    dp[i][l] = (s[i] == 1 ? 0 : n);
  for (int j : e[i]) {
    if (j == p)
      continue;
    for (int l = k; 2 * l > k; l--)
      dp[i][l] = min(dp[i][l], dp[j][l - 1] + sum[i][k - l] - (l == k ? s[j] : dp[j][k - l - 1]));
  }
  for (int l = 1; l <= k; l++)
    dp[i][l] = min(dp[i][l], dp[i][l - 1]);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout << fixed << setprecision(10);
  cin >> n >> k;
  int a, b;
  for (int i = 0; i < n - 1; i++) {
    cin >> a >> b, a--, b--;
    e[a].push_back(b);
    e[b].push_back(a);
  }
  dfs();
  // for (int i = 0; i < n; i++)
  //   for (int j = 0; j <= k; j++)
  //     cout << i << " " << j << ": " << dp[i][j] << "\n";
  int r = n;
  for (int i = 0; i < n; i++)
    r = min(r, dp[i][k] + n - s[i]);
  cout << r << "\n";
}
