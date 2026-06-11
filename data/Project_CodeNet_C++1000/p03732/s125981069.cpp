#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define rep2(i, m, n) for(int i = (int)(m); i < (int)(n); i++)
#define rep_inv(i, n, m) for(int i = (int)(n); i > (int)(m); i--)
using namespace std;
using ll = long long;
using vl = vector<ll>;
using vc = vector<char>;
using vvl = vector<vl>;
using vvc = vector<vc>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;

int main(){
  ll N, W;
  cin >> N >> W;
  vpll wv(N);
  rep(i, N) cin >> wv[i].first >> wv[i].second;

  ll w1 = wv[0].first;
  vector<vvl> dp(N + 1, vvl(N + 1, vl(400, -1)));
  rep(i, N + 1) dp[i][0][0] = 0;

  rep(i, N){
    ll wrem = wv[i].first - w1;
    ll v = wv[i].second;

    rep(j, i + 2){
      rep(k, 3 * (i + 1) + 1){
	if(dp[i][j][k] == -1) continue;
	
	dp[i + 1][j][k] = max(dp[i + 1][j][k], dp[i][j][k]);
	dp[i + 1][j + 1][k + wrem] = max(dp[i + 1][j + 1][k + wrem], dp[i][j][k] + v);
      }      
    }
  }

  ll ans = 0;

  rep(j, N + 1){
    rep(k, 400){
      if(dp[N][j][k] == -1) continue;
      if((j * w1 + k <= W)){
	ans = max(ans, dp[N][j][k]);
      }
    }
  }

  cout << ans << endl;
  
  return 0;
}
