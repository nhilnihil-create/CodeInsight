#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
typedef long double ld;
const int inf=1e9+7;
const ll longinf=1LL<<60;
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
#define F first
#define S second
 
const int mx=200010;
const ll mod=1e9+7;

int main(){
  int n,ma,mb;
  cin >> n >> ma >> mb;
  vector<int> a(n),b(n),c(n);
  rep(i,n){ cin >> a[i] >> b[i] >> c[i]; }
  vector<vector<vector<int>>> dp(45,vector<vector<int>>(520, vector<int>(520,inf)));
  dp[0][0][0]=0;
  rep(i,n){
    rep(j,410)rep(k,410){
      dp[i+1][j][k]=min(dp[i+1][j][k],dp[i][j][k]);
      dp[i+1][j+a[i]][k+b[i]]=min(dp[i+1][j+a[i]][k+b[i]],dp[i][j][k]+c[i]);
    }    
  }
  int ans=inf;
  for(int i=1; i<=40; i++){
    ans = min(ans,dp[n][ma*i][mb*i]);
  }
  if(ans==inf){ans=-1;}
  cout << ans << endl;
  return 0;
}