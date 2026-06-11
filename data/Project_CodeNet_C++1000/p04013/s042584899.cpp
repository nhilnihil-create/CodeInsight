#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
const double PI = acos(-1);
const ll MOD = 1000000007;
using Graph = vector<vector<int>>;

int main() {
  int N,A; cin >> N >> A;
  vector<int> x(N);
  rep(i,N) cin >> x[i];

  vector<vector<vector<ll>>> dp(N+1, vector<vector<ll>>(N+1, vector<ll>(2501)));
  dp[0][0][0] = 1;
  rep(i,N) {
    rep(j,N+1) {
      rep(k,2501) {
        if (j == 0) dp[i+1][0][k] = dp[i][0][k];
        else {
          if (k < x[i]) dp[i+1][j][k] = dp[i][j][k];
          else dp[i+1][j][k] = dp[i][j][k] + dp[i][j-1][k-x[i]];
        }
      }
    }
  }
  
  ll ans = 0;
    rep(j,N+1) {
      if (j == 0) continue;
      ans += dp[N][j][A*j];
    }
  cout << ans << endl;
}