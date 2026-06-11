#include <bits/stdc++.h>
//#include <atcoder/all>
#define ll long long int
#define MOD 1000000007
#define P pair<ll,ll>
#define INF 1000000000000000000

//using namespace atcoder;
using namespace std;

int main(void){
  ll n, a;
  cin >> n >> a;
  
  vector<ll> x(n);
  for (int i = 0; i < n; i++){
    cin >> x[i];
  }
  vector<vector<vector<ll>>> dp(n + 1, vector<vector<ll>>(n + 1, vector<ll>(2501, 0)));
  for (ll i = 0; i < n + 1; i++){
    dp[i][0][0] = 1;
  }

  for (ll i = 1; i < n + 1; i++){
    for (ll j = 1; j < n + 1; j++){
      for (ll k = 0; k < 2501; k++){
        if (k - x[i-1] >= 0)
          dp[i][j][k] = dp[i-1][j][k] + dp[i-1][j-1][k-x[i-1]];
        else
          dp[i][j][k] = dp[i-1][j][k];
      }
    }
  }
  ll ans = 0;
  for (ll i = 1; i < n + 1; i++){
    ans += dp[n][i][a*i];
  }
  cout << ans << endl;

  return 0;
}
