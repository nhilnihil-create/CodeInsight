#include<bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,n) for(int i=1;i<=n;i++)
signed main(){
  int n,m;
  int x;
  int mod=1e9+7;
  cin>>n>>m;
  int sx=0,sy=0;
  rep(i,n)cin>>x,sx+=(i-1)*x-(n-i)*x,sx%=mod;
  rep(i,m)cin>>x,sy+=(i-1)*x-(m-i)*x,sy%=mod;
  cout<<(sx*sy)%mod<<endl;
  return 0;
}
