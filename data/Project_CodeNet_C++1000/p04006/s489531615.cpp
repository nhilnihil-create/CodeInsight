#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main(){
  int n;
  cin >> n;
  long long x;
  cin >> x;
  long long k[n];
  rep(i,n)cin >> k[i];
  long long mi[n][n];
  rep(i,n){
    mi[i][0]=k[i];
  }
  rep(i,n-1){
    rep(j,n){
      mi[j][i+1]=min(mi[j][i],k[(j-i-1+n)%n]);
    }
  }
  long long ans=100000000000000;
  rep(i,n){
    long long t=0;
    rep(j,n)t+=mi[j][i];
    ans=min(ans,t+i*x);
  }
  cout << ans << endl;
} 
