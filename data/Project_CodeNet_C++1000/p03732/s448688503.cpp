#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)n; i++)
typedef long long ll;

int main(){
  ll n, W;
  cin >> n >> W;
  ll w[n], v[n], w1;
  rep(i,n) {
    cin >> w[i] >> v[i];
    if(i == 0) w1 = w[i];
    w[i] -= w1;
  }
  vector<vector<vector<ll>>> dp(n+1, vector<vector<ll>>(n+1, vector<ll>(2*n+1,0)));
  rep(i, n){
   rep(j, n){
     rep(k, 2*n+1){
      if(k-w[i] >= 0) dp[i+1][j+1][k] = max(dp[i+1][j+1][k], dp[i][j][k-w[i]]+v[i]);
      dp[i+1][j][k] = max(dp[i+1][j][k], dp[i][j][k]);
     }
    }
  }
  ll ans = 0;
  rep(i, n+1) {
    ll a = W - i*w1;
    if(a > 2*n) ans = max(ans, dp[n][i][2*n]);
    else if(a >= 0) ans = max(ans, dp[n][i][a]);
  }
  cout << ans << endl;
  return 0;
}
