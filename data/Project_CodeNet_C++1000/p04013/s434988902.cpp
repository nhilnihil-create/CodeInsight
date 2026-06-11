#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
typedef long long ll;
typedef pair <int,int> P;

ll dp[55][2505][55];

int main(){
  int n,a;
  cin>>n>>a;
  dp[0][0][0]=1;
  rep(i,n){
    int x;
    cin>>x;
    rep(j,2501){
      rep(k,i+1){
	dp[i+1][j+x][k+1]+=dp[i][j][k];
	dp[i+1][j][k]+=dp[i][j][k];
      }
    }
  }
  ll ans=0;
  rep(j,2501){
    rep(k,n+1){
      if(k==0) continue;
      if(j%k) continue;
      if(j/k==a) ans+=dp[n][j][k];
    }
  }
  cout<<ans<<endl;
  return 0;
}