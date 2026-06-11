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

signed main(){
  int n,a;cin>>n>>a;
  vector<int> x(n);
  rep(i,n)cin>>x[i];
  int res=0;
  vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(n+1,vector<int>(3000,0)));
  dp[0][0][0]=1;dp[0][1][x[0]]=1;
  rep1(i,n-1){
    dp[i][0][0]=dp[i-1][0][0];
    rep1(j,n){
      rep(k,3000){
        dp[i][j][k]=dp[i-1][j][k];
        if(k-x[i]>=0){
          dp[i][j][k]+=dp[i-1][j-1][k-x[i]];
        }
      }
    }
  }
  rep1(i,n){
    res+=dp[n-1][i][i*a];
    //cout<<dp[n-1][i][i*a]<<endl;
    //cout<<res<<endl;
  }
  cout<<res<<endl;
  return 0;
}
