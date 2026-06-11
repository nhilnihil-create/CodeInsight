#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define DUMP(x)  cout << #x << " = " << (x) << endl;
#define FOR(i, m, n) for(ll i = m; i < n; i++)
#define IFOR(i, m, n) for(ll i = n - 1; i >= m; i-- )
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
#define FOREACH(x,a) for(auto& (x) : (a) )
#define ALL(v) (v).begin(), (v).end()
#define SZ(x) ll(x.size())

int main(){
  ll N,W; cin >> N >> W;
  vector<ll> w(N), v(N);
  REP(i,N){
    cin >> w[i] >> v[i];
  }
  //重みを補正する, 0<=wi<=3
  ll d = w[0];
  REP(i,N) w[i] -= d;
  //dp[i][j][k]:i番目まで見て，j個使用，補正後の重みの和がkのとき価値の最大値
  vector<vector<vector<ll>>> dp(N+1, vector<vector<ll>>(N+1,vector<ll>(3*N+1,-1)));
  dp[0][0][0] = 0;

  REP(i,N) REP(j,N+1) REP(k,3*N+1) if(dp[i][j][k] != -1){
    dp[i+1][j][k] = max(dp[i+1][j][k], dp[i][j][k]);
    dp[i+1][j+1][k+w[i]] = max(dp[i+1][j+1][k+w[i]], dp[i][j][k]+v[i]);
  }

  ll ans = 0;
  REP(j,N+1){
    REP(k,min(W-j*d,3*N)+1){
      ans = max(ans,dp[N][j][k]);
    }
  }
  cout << ans << endl; 
}