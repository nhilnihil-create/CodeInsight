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
#define reprb(i, a, b) for(ll i = (b)-1; i >= (a); i--)
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

void pr(){
    cout << "No" << endl;
    exit(0);
}

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    ll n, x;
    cin >> n >> x;
    ll N = 2*n-1;
    if(x == 1 || x == N) pr();
    vll ans(N);
    if(x == n){
        rep(i, n-1){
            ans[i] = n-1-i;
        }
        ans[n-1] = n;
        repr(i, n, N){
            ans[i] = i+1;
        }
    }else if(x < n){
        ans[n-1] = x;
        rep(i, n-1){
            if(n-i > x) ans[i] = n-i;
            else ans[i] = n-i-1;
        }
        repr(i, n, N){
            ans[i] = i+1;
        }
    }else{
        ans[n-1] = x;
        rep(i, n-1){
            if(i+n < x) ans[i] = i+n;
            else ans[i] = i+n+1;
        }
        repr(i, n, N){
            ans[i] = N-i;
        }
    }
    cout << "Yes" << endl;
    rep(i, N) cout << ans[i] << "\n";
    return 0;
}