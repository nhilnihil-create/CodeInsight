#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define MOD (int)1e9+7
#define EPS 1e-8
#define INF 1e9+10
#define INFL 1e18
typedef long long ll;
using namespace std;
ll dp[42][420][420];
int main()
{
  int n,ma,mb;
  cin >> n >> ma >> mb;
  vector<ll>A(n,0),B(n,0),C(n,0);
  rep(i,n)cin >> A[i] >> B[i] >> C[i];
  rep(i,42)rep(j,420)rep(k,420)dp[i][j][k]=INF;
  dp[0][0][0]=0;
  rep(i,n){
      rep(a,405){
          rep(b,405){
              dp[i+1][a][b]=min(dp[i+1][a][b],dp[i][a][b]);
              dp[i+1][a+A[i]][b+B[i]]=min(dp[i+1][a+A[i]][b+B[i]],dp[i][a][b]+C[i]);
          }
      }
  }
  ll ans=INF;
  rep(i,410){
      rep(j,410){
          if(dp[n][i][j]==INF||i*j==0)continue;
          if(i*mb==j*ma){ans=min(ans,dp[n][i][j]);}
      }
  }

  if(ans==INF){cout << -1 << endl;}
  else{cout << ans << endl;}
}
