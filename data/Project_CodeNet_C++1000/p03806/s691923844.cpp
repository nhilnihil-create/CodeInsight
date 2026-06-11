#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

int dp[405][405][45];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);cout.tie(0);

  int n, ma, mb;
  cin >> n >> ma >> mb;
  vector < int > a(n + 1), b(n + 1), c(n + 1);
  for (int i = 1; i <= n; i++) cin >> a[i] >> b[i] >> c[i];

  for (int i = 0; i < 405; i++) {
    for (int j = 0; j < 405; j++) {
      for (int k = 0; k < 45; k++) dp[i][j][k] = 1e9 + 5;
    }
  }

  for (int k = 0; k < 45; k++) dp[0][0][k] = 0;

  for (int i = 0; i < 405; i++) {
    for (int j = 0; j < 405; j++) {
      for (int k = 1; k <= n; k++) {
        if (i - a[k] >= 0 && j - b[k] >= 0) dp[i][j][k] = min(dp[i - a[k]][j - b[k]][k - 1] + c[k], dp[i][j][k - 1]);
        else dp[i][j][k] = dp[i][j][k - 1];
      }
    }
  }

  int min_cst = INT_MAX;
  for(int i = ma; i < 405; i += ma) {
    int j = (i * mb) / ma;
    if (j >= 405) continue;
    min_cst = min (min_cst, dp[i][j][n]);
  }

  if(min_cst == 1e9 + 5) cout << -1 << '\n';
  else cout << min_cst << '\n';
}
