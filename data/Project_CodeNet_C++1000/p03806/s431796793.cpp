#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<math.h>
#include<complex>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<set>
#include<bitset>
#include<functional>
#include<assert.h>
#include<numeric>
using namespace std;
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
#define pint pair<int,int>
#define pll pair<ll,ll>
using ll = long long;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;

ll dp[50][500][500]; // dp[i][j][k] i個までで状態[j][k]を作るのに必要な最小費用

int main(){
  int n,ma,mb;
  cin >> n >> ma >> mb;
  int a[n+1]={},b[n+1]={},c[n+1]={};
  rep(i,n)cin >> a[i+1] >> b[i+1] >> c[i+1];
  for(int i=0;i<50;i++){
    for(int j=0;j<500;j++)for(int k=0;k<500;k++)dp[i][j][k]=longinf;
  }
  dp[0][0][0]=0;
  for(int i=1;i<=n;i++){
    for(int j=0;j<=400;j++){
      for(int k=0;k<=400;k++){
        dp[i][j][k]=min(dp[i][j][k],dp[i-1][j][k]);
        if(j>=a[i] && k>=b[i])dp[i][j][k]=min(dp[i][j][k],dp[i-1][j-a[i]][k-b[i]]+c[i]);
      }
    }
  }
  ll ans=longinf;
  for(int i=ma;i<500;i++){
    for(int j=mb;j<500;j++){
      if(i%ma==0 && j%mb==0 && i/ma==j/mb){
        ans=min(ans,dp[n][i][j]);
      }
    }
  }
  if(ans>=longinf)ans=-1;
  cout << ans << endl;
return 0;}