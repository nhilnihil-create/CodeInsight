#include<bits/stdc++.h>
using namespace std;
#ifdef LOCAL_DEBUG
  #include "LOCAL_DEBUG.hpp"
#endif
#define int long long

signed main(){

  int n, m1, m2; cin >> n >> m1 >> m2;
  vector<int> a(n), b(n), c(n);
  for(int i = 0; i < n; i++){
    cin >> a[i] >> b[i] >> c[i];
  }

  static int dp[51][501][501];
  fill(dp[0][0], dp[50][500] + 500, 1LL << 60);
  dp[0][0][0] = 0;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < 500; j++){
      for(int k = 0; k < 500; k++){
        dp[i+1][j][k] = min(dp[i+1][j][k], dp[i][j][k]);
        dp[i+1][j + a[i]][k + b[i]] = min(dp[i+1][j + a[i]][k + b[i]], dp[i][j][k] + c[i]);
      }
    }
  }

  int ans = 1LL << 60;
  for(int i = 1; i < 500; i++){
    for(int j = 1; j < 500; j++){
      if(i * m2 == j * m1) ans = min(ans, dp[n][i][j]);
    }
  }
  if(ans >= 1LL << 60) ans = -1;
  cout << ans << endl;

  return 0;
}
