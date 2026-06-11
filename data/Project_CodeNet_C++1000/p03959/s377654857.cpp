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

int main(){
  ll n,t[100010],a[100010],m[100010]={},M[100010]={},ans=1;
  cin>>n;
  Fr(i,n) cin>>t[i];
  fr(i,n) cin>>a[i];
  t[0]=0;a[n]=0;
  Fr(i,n){
    M[i]=t[i];
    if(t[i]!=t[i-1]) m[i]=t[i];
    else m[i]=1;
  }
  iFr(i,n){
    M[i]=min(M[i],a[i-1]);
    if(a[i]!=a[i-1]) m[i]=max(m[i],a[i-1]);
  }
  Fr(i,n) ans=mlt(ans,max(0ll,M[i]-m[i]+1));
  cout<<ans<<endl;
}