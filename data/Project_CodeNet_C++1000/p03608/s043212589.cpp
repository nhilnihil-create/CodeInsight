#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
#include<cmath>
#include<cstdio>
#include<tuple>
#include<bitset>
#include<map>

using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
#define ALL(x) x.begin(),x.end()
#define ll long long
typedef pair<int,int> P;
const int inf=1000000000000000007;
const int MOD=1000000007;
signed main(){
  int n,m,R;cin>>n>>m>>R;
  vector<int> r(R);
  rep(i,R){
    cin>>r[i];
  }
  vector<vector<int>> dp(n+1,vector<int>(n+1,inf));
  rep(i,m){
    int a,b,c;cin>>a>>b>>c;
    dp[a][b]=c;
    dp[b][a]=c;
  }
  rep1(k,n){
    rep1(i,n){
      rep1(j,n){
        dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
      }
    }
  }
  int res=inf;
  sort(r.begin(),r.end());
  do{
    int buf=0;
    rep1(i,R-1){
      buf+=dp[r[i-1]][r[i]];
    }
    res=min(res,buf);
  }while(next_permutation(ALL(r)));
  cout<<res<<"\n";
  return 0;
}
