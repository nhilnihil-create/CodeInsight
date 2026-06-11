#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const int INF=1001001001;
int dp[50][600][600];

int main(){
  int n,ma,mb;
  cin>>n>>ma>>mb;
  vector<int>a(n),b(n),c(n);
  rep(i,n)cin>>a[i]>>b[i]>>c[i];

  rep(i,50)rep(j,600)rep(k,600)dp[i][j][k]=INF;
  dp[0][0][0]=0;

  for(int i=0; i<n; ++i){
    for(int j=0; j<500; ++j){
      for(int k=0; k<500; ++k){
        chmin(dp[i+1][j+a[i]][k+b[i]],dp[i][j][k]+c[i]);
        chmin(dp[i+1][j][k],dp[i][j][k]);
      }
    }
  }
  int ans=INF,i=ma,j=mb;
  while(1){
    if(i>=500||j>=500)break;
    ans=min(ans,dp[n][i][j]);
    i+=ma,j+=mb;
  }
  if(ans!=INF)cout<<ans<<endl;
  else cout<<-1<<endl;
}