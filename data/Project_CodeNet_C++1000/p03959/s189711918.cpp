#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using vi = vector<int>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vvvll = vector<vvll>;
using vs = vector<string>;
using pll = pair<ll, ll>;
using vp = vector<pll>;
template<class T> using V = vector<T>;
template<class T> using VV = vector<vector<T> >;
#define rep(i, n) for(ll i = 0; i < (n); i++)
#define repb(i, n) for(ll i = (n)-1; i >= 0; i--)
#define repr(i, a, b) for(ll i = (a); i < (b); i++)
#define reprb(i, a, b) for(ll i = (a)-1; i >= (b); i--)
#define ALL(a) (a).begin(), (a).end()
#define SZ(x) ((ll)(x).size())
const ll MOD = 1000000007;
const ll INF = 100000000000000000LL;
inline ll GCD(ll a, ll b){ return b?GCD(b, a % b):a; }
inline ll LCM(ll a, ll b){ return a/GCD(a, b)*b; }
inline ll powint(unsigned long long x, ll y){ ll r=1; while(y){ if(y&1) r*=x; x*=x; y>>=1; } return r; }
inline ll powmod(ll x, ll y, ll m = MOD){ ll r=1; while(y){ if(y&1) r*=x; x*=x; r%=m; x%=m; y>>=1; } return r; }
template<class T>bool chmax(T &a, const T &b){ if(a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b){ if(b<a) { a=b; return 1; } return 0; }
#ifdef OJ_LOCAL
#include "dump.hpp"
#else
#define dump(...) ((void)0)
#endif

void pr(ll n){
    cout << n << endl;
    exit(0);
}

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    ll n;
    cin >> n;
    vll t(n);
    rep(i, n){
        cin >> t[i];
    }
    vll a(n);
    rep(i, n){
        cin >> a[i];
    }
    vll ans1(n, INF);
    vll ans2(n, INF);
    vi ansd1(n, 0);
    vi ansd2(n, 0);
    rep(i, n){
        if(i == 0 || t[i] > t[i-1]){
            chmin(ans1[i], 1ll);
            ansd1[i] = 1;
        }else{
            chmin(ans1[i], t[i]);
        }
    }
    repb(i, n){
        if(i == n-1 || a[i] > a[i+1]){
            chmin(ans2[i], 1ll);
            ansd2[i] = 1;
        }else{
            chmin(ans2[i], a[i]);
        }
    }
    rep(i, n){
        if(ansd1[i] == 1 && ansd2[i] == 1 && t[i] != a[i]){
            pr(0);
        }
        if(ansd1[i] == 1 && ansd2[i] == 0 && t[i] > a[i]){
            pr(0);
        }
        if(ansd1[i] == 0 && ansd2[i] == 1 && t[i] < a[i]){
            pr(0);
        }
    }
    ll ansm = 1;
    rep(i, n){
        ansm *= min(ans1[i], ans2[i])%MOD;
        ansm %= MOD;
    }
    cout << ansm << endl;
    return 0;
}