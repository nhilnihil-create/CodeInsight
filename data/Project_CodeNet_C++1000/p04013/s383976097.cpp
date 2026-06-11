#include<bits/stdc++.h>
using namespace std;
int main(){
  int n, a;
  cin >> n >> a;
  int x[n+1], maxV=0;
  for ( int i = 1; i <= n; i++){
    cin >> x[i];
    maxV = max(maxV, x[i]);
  }

  int xn = 2500; 
  long long dp[n+1][n+1][xn+1];
  for ( int i = 0; i <= n; i++){
    for ( int j = 0; j <= n; j++){
      for ( int k = 0; k <= xn; k++){
        if ( i == 0 && j == 0 && k == 0){
          dp[i][j][k] = 1;
        } else if ( i >= 1 && k < x[i]){
          dp[i][j][k] = dp[i-1][j][k];
        } else if (i >= 1 && j >= 1 && k >= x[i]){
          dp[i][j][k] = dp[i-1][j][k] + dp[i-1][j-1][k-x[i]];
        } else {
          dp[i][j][k] = 0;
        }
      }
    }
  }

  long long ans = 0;
  for ( int i = 1; i <= n; i++){
    ans += dp[n][i][i*a];
  }
  cout << ans << endl;

  return 0;
}