#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  int n, ma, mb;
  cin >> n >> ma >> mb;
  
  int dp[n + 1][401][401];
  for(int i = 0; i < n + 1; i++){
    for(int j = 0; j < 401; j++){
      for(int k = 0; k < 401; k++){
        dp[i][j][k] = 1e9;
        if(j == 0 && k == 0) dp[i][j][k] = 0;
      }
    }
  }
  
  int a, b, c;
  for(int i = 0; i < n; i++){
    cin >> a >> b >> c;
    for(int j = 0; j < 401; j++){
      for(int k = 0; k < 401; k++){
        if(dp[i][j][k] != 1e9){
          dp[i + 1][j + a][k + b] = min(dp[i + 1][j + a][k + b], dp[i][j][k] + c);
          dp[i + 1][j][k] = min(dp[i + 1][j][k], dp[i][j][k]);
        }
      }
    }
  }
  
  int ans = 1e9;
  for(int i = 1; i < (int) 401 / max(ma, mb); i++){
    ans = min(ans, dp[n][ma * i][mb * i]);
  }
  
  if(ans == 1e9) cout << -1 << '\n';
  else cout << ans << '\n';
}