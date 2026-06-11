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
  ll N, Ma, Mb;
  cin >> N >> Ma >> Mb;

  vector<vvl> dp(N + 1, vvl(401, vl(401, 10000)));
  dp[0][0][0] = 0;

  ll a, b, c;
  rep(i, N){
    cin >> a >> b >> c;

    rep(ca, 400 - a){
      rep(cb, 400 - b){
		dp[i + 1][ca][cb] = min(dp[i + 1][ca][cb], dp[i][ca][cb]);
		dp[i + 1][ca + a][cb + b] = min(dp[i + 1][ca + a][cb + b], dp[i][ca][cb] + c);
      }
    }
  }
  
  ll ans = 10000;

  rep(ca, 401){
    rep(cb, 401){
      if((ca*Mb == cb*Ma) && (ca > 0)){
	ans = min(ans, dp[N][ca][cb]);
      }
    }
  }

  if(ans == 10000) cout << -1 << endl;
  else cout << ans << endl;
  
  return 0;
}