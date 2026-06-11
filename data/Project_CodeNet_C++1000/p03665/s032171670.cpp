#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
typedef long double ld;
const int inf=1e9+7;
const ll longinf=1LL<<60;
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
#define F first
#define S second
constexpr char ln = '\n';

const int mx=100010;
const ll mod=1e9+7;

vector<ll> inv,fact,invfact;
void mod_build(int n){  
  fact.resize(n+1); inv.resize(n+1); invfact.resize(n+1);
  fact[0]=inv[0]=invfact[0]=1; inv[1]=1;
  rep(i,n){
    fact[i+1]=fact[i]*(i+1)%mod;
    if(i>0)inv[i+1]=mod-inv[mod%(i+1)]*(mod/(i+1))%mod;
    invfact[i+1]=invfact[i]*inv[i+1]%mod;
  }
}
ll perm(int n,int k){ if(n<0||k<0||k>n){ return 0; } else { return fact[n]*invfact[n-k]%mod; } }
ll comb(int n,int k){ if(n<0||k<0||k>n){ return 0; } else { return (fact[n]*invfact[n-k]%mod)*invfact[k]%mod; }}
ll modpow(ll x,ll n){
  x%=mod; ll res=1;
  while(n>0){ if(n&1){res=res*x%mod;} x=x*x%mod; n>>=1; }
  return res;
}
ll modinv(ll a){ return modpow(a, mod-2); }

ll powll(ll n,ll k){ ll ret=1; while(k){ if(k&1)ret=ret*n; n=n*n; k>>=1; } return ret; }


int main(){
  mod_build(mx);
  int n,p;
  cin >> n >> p;
  vector<int> a(n);
  map<int,ll> mp;
  rep(i,n){
    cin >> a[i];
    a[i] %= 2;
    mp[a[i]]++;
  }
  if(p==1){
    ll ans = powll(2,mp[0]);
    ll tmp = 0;
    for(ll i=1; i<=mp[1]; i+=2){
      tmp += comb(mp[1],i);
    }
    ans *= tmp;
    cout << ans << ln;
  } else {
    ll ans = powll(2,mp[0]);
    ll tmp = 0;
    for(ll i=0; i<=mp[1]; i+=2){
      tmp += comb(mp[1],i);
    }
    ans *= tmp;
    cout << ans << ln;
  }

  return 0;
}