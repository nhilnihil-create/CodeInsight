#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef pair<ll,ll> P;
#define pb push_back
#define ft first
#define sd second
#define mp make_pair
#define fr(i,n) for(int i=0;i<(n);i++)
#define Fr(i,n) for(int i=0;i++<(n);)
#define ifr(i,n) for(int i=(n)-1;i>=0;i--)
#define iFr(i,n) for(int i=(n);i>0;i--)

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

int main(){
    ll n,s=0,ans=0;
    cin>>n;
    vector<ll> dp1(n+3),t(n+3);
    dp1[0]=1;
    t[0]=t[1]=t[2]=1;
    ll m=mlt(n-1,n-1);
    fr(i,n){
        s=ad(s,dp1[i]);
        dp1[i+3]=ad(dp1[i+2],s);
        t[i+3]=ad(t[i+2],dp1[i+3]);
    }
    fr(i,n-1){
        ans=ad(ans,mlt(ad(m,i+1),t[i]));
    }
    ans=ad(ans,mlt(t[n-1],n-1));
    ans=ad(ans,t[n]);
    cout<<ans<<endl;
}