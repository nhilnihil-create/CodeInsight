#include <bits/stdc++.h> 

using namespace std;
using ll=long long;
using ull=unsigned long long;
using pii=pair<int,int>;

#define INF LONG_MAX
#define MOD 1000000007
#define rng(a) a.begin(),a.end()
#define rrng(a) a.end(),a.begin()
#define int ll

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int N,A;
  cin>>N>>A;
  vector<int>x(N);
  for(int i=0;i<N;i++)cin>>x[i];

  vector<vector<vector<int>>>dp(N+1,vector<vector<int>>(N*A+1,vector<int>(N+1,0)));
  dp[0][0][0]=1;
  for(int i=0;i<N;i++){
    for(int j=0;j<=A*N;j++){
      for(int k=0;k<N;k++){
        if(j+x[i]<=N*A)dp[i+1][j+x[i]][k+1]+=dp[i][j][k];
        dp[i+1][j][k]+=dp[i][j][k];
      }
    }
  }

  int ans=0;
  for(int i=1;i<=N;i++)ans+=dp[N][A*i][i];
  cout<<ans<<endl;
  return 0;
}

