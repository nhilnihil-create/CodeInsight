#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef pair<ll,ll> P;
#define pb push_back
#define mp make_pair
#define fr(i,n) for(int i=0;i<n;i++)
#define Fr(i,n) for(int i=0;i++<n;)
#define ifr(i,n) for(int i=n-1;i>=0;i--)
#define iFr(i,n) for(int i=n;i>0;i--)

const ll MOD=1e9+7;

ll ad(ll x,ll y=0){
  return (x+y)%MOD;
}

ll mlt(ll x,ll y=1){
  return (x*y)%MOD;
}

ll pwr(ll x,ll y){
  ll pw[32]={},w=1;
  pw[0]=x;
  fr(i,31) pw[i+1]=mlt(pw[i],pw[i]);
  fr(i,32){
    w=mlt(w,1+(y%2)*(pw[i]-1));
    y/=2;
  }
  return w;
}

ll inv(ll x){
  return pwr(x,MOD-2);
}

ll fc[200010]={1};
ll fct(ll x){
  if(fc[x]==0) fc[x]=mlt(x,fct(x-1));
  return fc[x];
}

ll ifc[200010]={1};
ll ifct(ll x){
  if(ifc[x]==0) ifc[x]=inv(fct(x));
  return ifc[x];
}

ll comb(ll n,ll r){
  if(n<0 || r<0 || n<r) return 0;
  return mlt(fct(n),mlt(ifct(r),ifct(n-r)));
}

ll pt(ll a,ll b){
  return comb(a+b-2,a-1);
}

int main(){
  ll h,w,a,b,ans=0;
  cin>>h>>w>>a>>b;
  Fr(i,h-a) ans=ad(ans,mlt(pt(i,b),pt(h-i+1,w-b)));
  cout<<ans<<endl;
}