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
  ll N, A;
  cin >> N >> A;
  vl x(N);
  rep(i, N){
    cin >> x[i];
  }

  vector<vector<vector<ll> > > dp(50, vvl(51, vl(2501, 0)));
  ll sum = 0;
  dp[0][0][0] = 1;
  dp[0][1][x[0]] = 1;
  
  rep(i, N - 1){
    sum += x[i];
    
    rep(j, i + 2){
      rep(k, sum + 1){
		dp[i + 1][j + 1][k + x[i + 1]] += dp[i][j][k];
		dp[i + 1][j][k] += dp[i][j][k];
      }
    }
  }

  ll ans = 0;

  rep2(i, 1, N + 1){
    ans += dp[N-1][i][i * A];
  }

  cout << ans << endl;
  
  return 0;
}