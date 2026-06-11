#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vvvll = vector<vvll>;
using vs = vector<string>;
using pll = pair<ll, ll>;
using vp = vector<pll>;
#define rep(i, n) for(ll i = 0; i < (n); i++)
#define repr(i, a, b) for(ll i = (a); i < (b); i++)
#define ALL(a) (a).begin(), (a).end()
#define SZ(x) ((ll)(x).size())
const ll MOD = 1000000007;
const ll INF = 100000000000000000LL;
inline ll GCD(ll a, ll b){ return b?GCD(b, a % b):a; }
inline ll LCM(ll a, ll b){ return a/GCD(a, b)*b; }
inline ll powint(ll x, ll y){ ll r=1; while(y){ if(y&1) r*=x; x*=x; y>>=1; } return r; }
inline ll powmod(ll x, ll y, ll m = MOD){ ll r=1; while(y){ if(y&1) r*=x; x*=x; r%=m; x%=m; y>>=1; } return r; }
template<class T>bool chmax(T &a, const T &b){ if(a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b){ if(b<a) { a=b; return 1; } return 0; }
#ifdef OJ_LOCAL
#include "dump.hpp"
#else
#define dump(...) ((void)0)
#endif

bool q(ll n){
    cout << "? " << n << endl;
    char ans;
    cin >> ans;
    return ans=='Y';
}
bool nq(ll n){
    cout << "? " << n << endl;
    char ans;
    cin >> ans;
    return ans=='N';
}
void qd(ll n){
    cout << "! " << n << endl;
    exit(0);
}

// [lb, ub] -> ret の範囲
// last-y: BS(1, 10, nq)-1
// first-y: BS(1, 10, q)
ll BS(ll lb, ll ub, function<bool(ll)> f){
    lb--;
    // (lb, ub]
    while(ub - lb > 1){
        ll mid = (lb + ub) / 2;
        if(f(mid)){
            // (lb, mid]
            ub = mid;
        }else{
            // (mid, ub]
            lb = mid;
        }
    }
    return ub;
}

int main(){
    ll ans = 0;
    ll first_y = BS(1e9, 1e10-1, q);
    dump(first_y);
    if(first_y == (ll)1e9){
        ans = 1;
        while(nq(ans*10-1)){
            ans *= 10;
        }
        qd(ans);
    }else{
        ans = first_y;
        while(ans % 10 == 0){
            ans /= 10;
        }
        ll r = 1;
        while(r < ans){
            r *= 10;
        }
        while(q(r)){
            r *= 10;
            ans *= 10;
        }
        qd(ans);
    }
    return 0;
}