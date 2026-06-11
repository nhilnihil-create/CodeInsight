#include <bits/stdc++.h>
#include <stdlib.h>
#include <fstream>
#include <iostream>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<ll,ll> llP;

ll mod(ll a, ll b){
  ll ret=a%b;
  if(ret<0) ret+=b;
  return ret;
}

ll modpow(ll a,ll b,ll c){
  ll res=1;
  while(b>0){
    if(b&1) res=mod(res*a,c);
    a=mod(a*a,c);
    b>>=1;
  }
  return res;
}

int main() {
  int n,ma,mb;
  cin>>n>>ma>>mb;
  int a[n],b[n],c[n];
  for(int i=0;i<n;i++){
    cin>>a[i]>>b[i]>>c[i];
  }
  int dp[n+1][401][401];
  for(int i=0;i<n+1;i++){
    for(int j=0;j<401;j++){
      for(int k=0;k<401;k++){
        dp[i][j][k]=(int)1e9;
      }
    }
  }
  dp[0][0][0]=0;
  for(int i=0;i<n;i++){
    for(int j=0;j<401;j++){
      for(int k=0;k<401;k++){
        if(dp[i][j][k]==(int)1e9) continue;
        dp[i+1][j][k]=min(dp[i+1][j][k],dp[i][j][k]);
        dp[i+1][j+a[i]][k+b[i]]=min(dp[i+1][j+a[i]][k+b[i]],dp[i][j][k]+c[i]);
      }
    }
  }
  int ans=-1;
  for(int i=1;i<=400;i++){
    for(int j=1;j<=400;j++){
      if(dp[n][i][j]==(int)1e9) continue;
      if(i*mb==j*ma){
        if(ans<0) ans=dp[n][i][j];
        else ans=min(ans,dp[n][i][j]);
      }
    }
  }
  cout<<ans<<endl;
  return 0;
}
