#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
#include<cmath>
#include<cstdio>
#include<tuple>
#include<bitset>

using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
#define ALL(x) x.begin(),x.end()
#define ll long long
typedef pair<int,int> P;
const int inf=1000000007;
const int MOD=1000000007;
int dp[40][500][500];
struct Med{
  int a;
  int b;
  int c;
};
signed main(){
  int n,ma,mb;cin>>n>>ma>>mb;
  vector<Med> med(n);
  rep(i,40){
    rep(j,500){
      rep(k,500){
        dp[i][j][k]=inf;
      }
    }
  }
  dp[0][0][0]=0;
  rep(i,n){
    cin>>med[i].a>>med[i].b>>med[i].c;
  }
  dp[0][med[0].a][med[0].b]=med[0].c;
  rep1(i,n-1){
    rep(j,500){
      rep(k,500){
        if(j-med[i].a<0||k-med[i].b<0){
          dp[i][j][k]=dp[i-1][j][k];
          continue;
        }
        dp[i][j][k]=min(dp[i-1][j][k],dp[i-1][j-med[i].a][k-med[i].b]+med[i].c);
      }
    }
  }
  int res=inf;
  rep1(j,499){
    rep1(k,499){
      if(j*mb==k*ma){
        res=min(res,dp[n-1][j][k]);
      }
    }
  }
  if(res==inf){
    res=-1;
  }
  cout<<res<<"\n";
  return 0;
}
