#include "bits/stdc++.h"
#include "math.h"
 
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<int> vin;
typedef pair<ll,ll> P;
typedef vector<P> vp;
#define rep(i,a,b) for(ll i=(a);i<(b);++i)
#define drep(i,a,b) for(ll i=(a);i>=(b);--i)
#define SIZE(a) int((a).size())
#define out(a) cout<<(a)<<endl;
const int INF=INT_MAX;
const int MAX = 510000;
const ll MOD = 1000000007;
ll fac[MAX], finv[MAX], inv[MAX];
ll modpow(ll x, ll n){
	ll r=1;
	while(n){
		if(n&1) r=r*x%MOD;
		x=x*x%MOD;
		n>>=1;
	}
	return r;
}
int main(){
  ll n;cin>>n;
  vll k(n);
  rep(i,0,n){
    ll a;cin>>a;
    k[a]++;
  }
  if(n%2){
    bool ok=false;
    if(k[0]!=1){ok=true;}
    rep(i,2,n){
      if(i%2==0&&k[i]!=2){
        ok=true;
      }
      if(i%2&&k[i]!=0){
        ok=true;
      }
    }
    if(ok){cout<<0<<endl;}
    else{
      cout<<modpow(2,n/2)<<endl;
    }
  }
  else{
    bool ok=false;
    rep(i,0,n){
      if(i%2&&k[i]!=2){
        ok=true;
      }
      if(i%2==0&&k[i]!=0){
        ok=true;
      }
    }
    if(ok){cout<<0<<endl;}
    else{cout<<modpow(2,n/2)<<endl;}
  }
}

