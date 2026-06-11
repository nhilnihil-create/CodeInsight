#include <bits/stdc++.h>
#define REP(i, n) for(long long i=0; i<n; i++)
#define REPR(i, n) for(long long i=n-1; i>=0; i--)
#define FOR(i, m, n) for(long long i=m; i<=n; i++)
#define FORR(i, m, n) for(long long i=m; i>=n; i--)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define VSORTR(v) sort(v.rbegin(), v.rend());
#define ALL(v) (v).begin(),(v).end()
#define FIN ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

using namespace std;
using ll = long long;
using ull = unsigned long long;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using P = pair<ll, ll>;
const ll mod = 1e9+7;
const ll inf = 1e15;
ll power(ll a,ll b){return b?power(a*a%mod,b/2)*(b%2?a:1)%mod:1;}

ll fac[2000010], finv[2000010], inv[2000010];

void init(){
    fac[0]=fac[1]=1;
    finv[0]=finv[1]=1;
    inv[1]=1;
    for(ll i=2;i<2000010;i++){
        fac[i]=fac[i-1]*i%mod;
        inv[i]=mod-inv[mod%i]*(mod/i)%mod;
        finv[i]=finv[i-1]*inv[i]%mod;
    }
}

ll C(ll n, ll k){
  return fac[n] %mod * finv[k] %mod * finv[n-k] %mod;
}

int main(){FIN
    ll ans=1;
    init();
    ll n,m;cin>>n>>m;
    if (abs(n-m)>1) {
        cout<<0<<endl;
        return 0;
    }
    if(n==m){
        ans *= fac[n] % mod;
        ans %= mod;
        ans *= fac[n] % mod;
        ans %= mod;
        ans *= 2;
        ans %= mod;

    }
    else{
        ll mx = max(n,m);
        ans *= fac[mx] % mod;
        ans %= mod;
        ans *= fac[mx-1] % mod;
        ans %= mod;
    }
    cout<<ans<<endl;
    return 0;
}
