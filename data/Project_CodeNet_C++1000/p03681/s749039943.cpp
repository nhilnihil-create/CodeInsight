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
  ll n,m;cin>>n>>m;
  ll ans=1;
  if(n==m){
    ans=2;
    rep(i,0,n){
      ans*=(i+1);
      ans%=MOD;
    }
    rep(i,0,m){
      ans*=(i+1);
      ans%=MOD;
    }
  }
  else if(max(n,m)==min(n,m)+1){
    rep(i,0,max(n,m)){
      ans*=(i+1);
      ans%=MOD;
    }
    rep(i,0,min(m,n)){
      ans*=(i+1);
      ans%=MOD;
    }
  }
  else{
    ans=0;
  }
  cout<<ans<<endl;
}
