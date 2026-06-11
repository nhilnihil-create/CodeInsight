#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define FOR(i,l,r) for(i=l;i<r;i++)
#define REP(i,n) FOR(i,0,n)
#define ALL(x) x.begin(),x.end()
#define P pair<ll,ll>
#define F first
#define S second
signed main(){
  ll a,b,c,H,W,h,ans=10000000000;cin>>H>>W;
  a=H/3*W;h=H-H/3;
  b=(h/2)*W;c=(h-h/2)*W;
  ans=min(ans,max({a,b,c})-min({a,b,c}));
  b=h*(W/2);c=h*(W-W/2);
  ans=min(ans,max({a,b,c})-min({a,b,c}));
  a=(H/3+1)*W;h--;
  b=(h/2)*W;c=(h-h/2)*W;
  ans=min(ans,max({a,b,c})-min({a,b,c}));
  b=h*(W/2);c=h*(W-W/2);
  ans=min(ans,max({a,b,c})-min({a,b,c}));
  swap(H,W);
  a=H/3*W;h=H-H/3;
  b=(h/2)*W;c=(h-h/2)*W;
  ans=min(ans,max({a,b,c})-min({a,b,c}));
  b=h*(W/2);c=h*(W-W/2);
  ans=min(ans,max({a,b,c})-min({a,b,c}));
  a=(H/3+1)*W;h--;
  b=(h/2)*W;c=(h-h/2)*W;
  ans=min(ans,max({a,b,c})-min({a,b,c}));
  b=h*(W/2);c=h*(W-W/2);
  ans=min(ans,max({a,b,c})-min({a,b,c}));
  cout<<ans<<endl;
  return 0;
}