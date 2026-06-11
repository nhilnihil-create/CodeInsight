#include<bits/stdc++.h>
using namespace std;
const int INF = 2e9;
int a[50],b[50],c[50];
int main(){
  int n,A,B;
  cin >> n >> A >> B;
  for(int i=0;i<n;i++) cin >> a[i] >> b[i] >> c[i];
  vector<vector<vector<int>>> dp(n+1,vector<vector<int>> (401,vector<int> (401,INF)));
  for(int i=0;i<n+1;i++) dp[i][0][0]=0;
  for(int i=0;i<n;i++){
    for(int j=0;j<401;j++){
      for(int k=0;k<401;k++){
        if(j>=a[i] && k>=b[i]) {
          dp[i+1][j][k] = min(dp[i][j][k],dp[i][j-a[i]][k-b[i]]+c[i]);
        }
        else dp[i+1][j][k] = dp[i][j][k];
        //if(dp[i+1][j][k]<INF) cout << i << " " << j << " " << k << " " << dp[i+1][j][k] << endl;
      }
    }
  }
  int ans=INF;
  for(int i=1;;i++){
    if(i*A>400 || i*B>400) break;
    else{
      ans = min(ans,dp[n][i*A][i*B]);
    }
  }
  if(ans<INF)cout << ans << endl;
  else cout << -1 << endl;
}