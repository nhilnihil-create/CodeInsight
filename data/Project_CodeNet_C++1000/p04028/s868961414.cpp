#include <bits/stdc++.h>
const int INF=1e9,MOD=1e9+7;
const long long LINF=1e18;
using namespace std;
#define int long long
//template
int dp[5005][5005];
int pw(int n,int k){
  int res=1;
  while(k){
    if(k&1)res*=n;res%=MOD;
    n*=n;n%=MOD;
    k>>=1;
  }
  return res;
}
//main
signed main(){
  int N;string s;
  cin>>N>>s;
  memset(dp,0,sizeof(dp));
  dp[0][0]=1;
  for(int i=0;i<N;i++){
    for(int j=1;j<=N;j++){
      dp[i+1][j]=(dp[i][j+1]+dp[i][j-1]*2)%MOD;
    }
    dp[i+1][0]=dp[i][0]+(dp[i][1])%MOD;
  }
  cout<<(dp[N][s.size()]*pw(pw(2,s.size()),MOD-2))%MOD<<endl;
}
