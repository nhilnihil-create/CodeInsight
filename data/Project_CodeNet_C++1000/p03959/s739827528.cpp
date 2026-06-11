#include<bits/stdc++.h>
using namespace std;
#define int long
const int mod = 1e9+7;
signed main(){
  int n;
  cin>>n;
  vector<int> t(n+2),a(n+2);
  for(int i=0;i<n;++i)cin>>t[i+1];
  for(int i=0;i<n;++i)cin>>a[i+1];
  t[0]=t[n+1]=a[0]=a[n+1]=0;
  int r=1,u,l;
  for(int i=1;i<=n;++i){
    u=min(a[i],t[i]),l=1;
    if(t[i-1]!=t[i]){
      if(t[i]>a[i])return cout<<0,0;
      u=l=t[i];
    }
    if(a[i]!=a[i+1]){
      if((l>1&&a[i]!=l)||a[i]>t[i])return cout<<0,0;
      u=l=a[i];
    }
    r=r*(u-l+1);
    if(r>=mod)r%=mod;
  }
  cout<<r;
}