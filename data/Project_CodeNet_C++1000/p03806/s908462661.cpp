#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,A,B;
  cin >> n >> A >> B;
  const int nmax=40,amax=10,INF=1e9;
  int dp[nmax+1][nmax*amax+1][nmax*amax+1];
  for(int i=0;i<n+1;i++){
    for(int j=0;j<nmax*amax+1;j++){
      for(int k=0;k<nmax*amax+1;k++){
        dp[i][j][k]=INF;
      }
    }
  }
  vector<int> a(n),b(n),c(n);
  for(int i=0;i<n;i++){
    cin >> a[i] >> b[i] >> c[i];
  }
  dp[0][0][0]=0;
  for(int i=0;i<n;i++){
    for(int j=0;j<nmax*amax+1;j++){
      for(int k=0;k<nmax*amax+1;k++){
        if(dp[i][j][k]==INF){
          continue;
        }
        dp[i+1][j][k]=min(dp[i+1][j][k],dp[i][j][k]);
        dp[i+1][j+a[i]][k+b[i]]=min(dp[i+1][j+a[i]][k+b[i]],dp[i][j][k]+c[i]);
      }
    }
  }
  int ans=INF;
  for(int i=1;i<nmax*amax+1;i++){
    for(int j=1;j<nmax*amax+1;j++){
      if(i*B==j*A){
        ans=min(ans,dp[n][i][j]);
      }
    }
  }
  if(ans==INF){
    cout << -1 << endl;
  }
  else{
    cout << ans << endl;
  }
}