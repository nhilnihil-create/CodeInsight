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

ll ans(ll* x,ll n){
  ll an=0,s[100010]={};
  Fr(i,n) s[i]=s[i-1]+x[i];
  Fr(i,n) an=ad(an,i*x[i]-s[i]);
  return an;
}

int main(){
  ll n,m,x[100010],y[100010];
  cin>>n>>m;
  Fr(i,n) cin>>x[i];
  Fr(i,m) cin>>y[i];
  cout<<mlt(ans(x,n),ans(y,m))<<endl;
}