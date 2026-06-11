#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)n; i++)
using ll = long long;

int main(){
  ll n, l;
  cin >> n >> l;
  ll w[n], v[n];
  rep(i,n) cin >> w[i] >> v[i];
  ll a = w[0];
  rep(i,n) w[i] -= a;
  ll ans = 0;
  vector<vector<vector<ll>>> dp(n+1,vector<vector<ll>>(n+1,vector<ll>(3*n+1)));
  rep(i,n) {
    rep(j,n) {
      rep(k,3*n+1) {
        dp[i+1][j][k] = max(dp[i+1][j][k],dp[i][j][k]);
        if(k+w[i] <= 3*n) dp[i+1][j+1][k+w[i]] = max(dp[i+1][j+1][k+w[i]],dp[i][j][k]+v[i]);
      }
    }
  }
  rep(i,n+1) {
    rep(j,3*n+1) {
      if(a*i+j <= l) ans= max(ans,dp[n][i][j]);
    }
  }
  cout << ans << endl;
  return 0;
}
