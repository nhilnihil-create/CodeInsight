#include <bits/stdc++.h>
#include<algorithm>
#define int long long
using namespace std;
typedef pair<int,int> P;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define INF 1000000000000

int MOD=1000000007;
int modpow(int a,int x){
  if(a<0)a+=MOD;
  int ans=1;
  while(x>0){
    if(x&1) ans=ans*a%MOD;
      a=a*a%MOD;
      x>>=1;
  }
  return ans;
}

int gyaku(int n){
    return modpow(n,MOD-2);
}
////////////////////////////////////////////////////////////

signed main() {
  int xl=0,xr,yb=0,yt;
  cin>>xr>>yt;
  int n;
  cin>>n;
  rep(i,n){
    int x,y,a;
    cin>>x>>y>>a;
    if(a==1)xl=max(xl,x);
    if(a==2)xr=min(xr,x);
    if(a==3)yb=max(yb,y);
    if(a==4)yt=min(yt,y);
  }
  if(xr-xl<=0||yt-yb<=0)cout<<0<<endl;
  else cout<<(xr-xl)*(yt-yb)<<endl;
}
