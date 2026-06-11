#include <iostream>
using namespace std;

int main() {
  int n, ma, mb;
  cin >> n >> ma >> mb;
  int a[n], b[n], c[n];
  int suma = 0, sumb = 0, sumc = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i] >> c[i];
    suma += a[i];
    sumb += b[i];
    sumc += c[i];
  }
  int inf = sumc + 1;

  int dp[n+1][suma+1][sumb+1];
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= suma; j++) {
      for (int k = 0; k <= sumb; k++) {
        dp[i][j][k] = inf;
      }
    }
  }

  dp[0][0][0] = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= suma; j++) {
      for (int k = 0; k <= sumb; k++) {
        if (dp[i][j][k] == inf) continue;
        dp[i+1][j][k] = min(dp[i+1][j][k], dp[i][j][k]);
        dp[i+1][j+a[i]][k+b[i]] = min(dp[i+1][j+a[i]][k+b[i]], dp[i][j][k]+c[i]);
      }
    }
  }

  int ans = inf;
  for (int j = 1; j <= suma; j++) {
    for (int k = 1; k <= sumb; k++) {
      if (j*mb == k*ma) ans = min(ans, dp[n][j][k]);
    }
  }
  cout << (ans != inf ? ans : -1) << endl;
}