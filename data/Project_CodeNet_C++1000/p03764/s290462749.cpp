#include "bits/stdc++.h"
using namespace std;
#define int long long
int mod=1e9+7;

signed main(){
  int n,m;
  cin>>n>>m;
  vector<int> x(n);
  vector<int> y(m);
  for(int i=0;i<n;i++)cin>>x[i];
  for(int i=0;i<m;i++)cin>>y[i];
  int lx=0;
  for(int i=0;i<n;i++){
    lx+=x[i]*i;
    lx%=mod;
    lx-=x[i]*(n-i-1);
    lx%=mod;
  }
  int ly=0;
  for(int i=0;i<m;i++){
    ly+=y[i]*i;
    ly%=mod;
    ly-=y[i]*(m-i-1);
    ly%=mod;
  }
  cout<<(lx*ly)%mod<<endl;
}
