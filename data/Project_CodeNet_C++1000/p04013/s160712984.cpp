#include <bits/stdc++.h>
using namespace std;
using ll = long long; 

ll ans=0,dp[51][51][2501];

int main() {
  int N,A; cin >> N >> A;
  int x[N], total =0; 
  for (int i =1; i<N+1; i++) {
    cin >> x[i]; total += x[i];
  }
 
  for (int i =0; i<=N; i++) {
    for (int j =0; j<=N; j++) {
      for (int k =0; k<=total; k++) {
        if (i == 0 && j == 0 && k == 0) dp[i][j][k] = 1;
        else if (i >= 1 && k < x[i]) dp[i][j][k] = dp[i-1][j][k];
        else if (i >= 1 && j >= 1 && k >= x[i]) dp[i][j][k] = dp[i-1][j][k] + dp[i-1][j-1][k - x[i]];
        else dp[i][j][k] = 0;
      }       
    }
  } 
  
  for (int i =1; i<N+1; i++) ans += dp[N][i][i * A];
  cout << ans << endl; 
}