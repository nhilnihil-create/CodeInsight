#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>

using namespace std;

int main(){
  int n,m,l,a[45],b[45],c[45],dp[45][410][410],ans =100000009;
  cin >> n >> m >> l;
  
  for(int i=0;i<n;i++){
    cin >> a[i] >> b[i] >> c[i];
  }
  
  for(int i = 0; i <= n; ++i){ 
    for(int j = 0; j <= 400; ++j){ 
      for(int k = 0; k <= 400; ++k){  
        dp[i][j][k]=100000009; 
      }  
    }  
  }
  
  
  dp[0][0][0] =0;
  
  
  for(int i=0;i<n;i++){
    for(int j=0;j<=400;j++){
      for(int k=0;k<=400;k++){
        if(dp[i][j][k] == 100000009){
          continue;
        }
        dp[i+1][j][k] = min(dp[i][j][k],dp[i+1][j][k]);
        dp[i+1][j+a[i]][k+b[i]] = min(dp[i+1][j+a[i]][k+b[i]],dp[i][j][k]+c[i]);
      }
    }
  }
  
  for(int j=1;j<=400;j++){
    for(int k=1;k<=400;k++){
      
      if(k*m ==j*l){
        ans = min(dp[n][j][k],ans);
      }
    }
  }
  
  if(ans == 100000009){
    ans = -1;
  }
  
  cout << ans << endl;
}
  
