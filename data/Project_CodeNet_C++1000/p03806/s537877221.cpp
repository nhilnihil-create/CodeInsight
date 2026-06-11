#include<bits/stdc++.h>
#define rep(i, n) for (int i=0; i<(n); i++)
#define ll long long
using namespace std;

const int inf=10101010;
const int N_MAX=41;
const int AB_MAX=11;
int dp[N_MAX][N_MAX*AB_MAX][N_MAX*AB_MAX];

int main() {
  int n,ma,mb; cin>>n>>ma>>mb;
  vector<int> a(n),b(n),c(n);
  rep(i, n) cin>>a[i]>>b[i]>>c[i];
  rep(i, n+1) {
    rep(j, n*AB_MAX+1) {
      rep(k, n*AB_MAX+1) {
        dp[i][j][k]=inf;
      }
    }
  }
  dp[0][0][0]=0;
  rep(i, n) {
    rep(j, n*AB_MAX) {
      rep(k, n*AB_MAX) {
        if (dp[i][j][k]==inf) continue;
        dp[i+1][j][k]=min(dp[i+1][j][k], dp[i][j][k]);
        dp[i+1][j+a[i]][k+b[i]]=min(dp[i+1][j+a[i]][k+b[i]],dp[i][j][k]+c[i]);
      }
    }
  }
  int res=inf;
  for (int i=1; i<n*AB_MAX+1; i++) {
    for (int j=1; j<n*AB_MAX+1; j++) {
      if (i*mb==j*ma) res=min(res, dp[n][i][j]);
    }
  }
  if (res!=inf) cout<<res<<endl;
  else cout<<-1<<endl;
}