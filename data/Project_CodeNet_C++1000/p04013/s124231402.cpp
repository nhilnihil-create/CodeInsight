#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
  int n,a; cin >> n >> a;
  vector<int> x(n);
  for(int i=0; i<n; i++) cin >> x[i];
  ll dp[60][60][2510];
  for(int i=0; i<60; i++){
    for(int j=0; j<60; j++){
      for(int k=0; k<2510; k++){
        dp[i][j][k]=0;
      }
    }
  }
  for(int i=0; i<=n; i++) dp[i][0][0]=1;
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      for(int k=0; k<=n*50; k++){
        if(k<x[i]) dp[i+1][j+1][k]+=dp[i][j+1][k];
        else dp[i+1][j+1][k]+=dp[i][j][k-x[i]]+dp[i][j+1][k];
      }
    }
  }
  ll res=0;
  for(int i=1; i<=n; i++){
    for(int j=0; j<=n*50; j++){
      if(j%i==0&&j/i==a) res+=dp[n][i][j];
    }
  }
  //cout << dp[n][1][8] << endl;
  cout << res << endl;
}