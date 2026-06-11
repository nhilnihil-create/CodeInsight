#include <bits/stdc++.h>

using namespace std;

long long dp[51][51][2501];

int main() {
  ios::sync_with_stdio(0); 
  cin.tie(0); 

  int n, a;
  cin >> n >> a;

  vector<int> v(n);
  for (int i = 0; i < n; ++i) cin >> v[i];

  dp[0][0][0] = 1;
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j <= i; ++j) {
      for (int k = 0; k <= 2500; ++k) {
        if (k < v[i - 1] || j == 0) {
          dp[i][j][k] = dp[i - 1][j][k];
        } else {
          dp[i][j][k] = dp[i - 1][j][k] + dp[i - 1][j - 1][k - v[i - 1]];
        }
      }
    }
  }

  long long res = 0;
  for (int i = 1; i <= n; ++i) {
    res += dp[n][i][i * a];
  }

  cout << res << "\n";
}
	

