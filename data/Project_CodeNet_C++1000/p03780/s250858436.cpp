#pragma region template
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using vi = vector<int>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vvvll = vector<vvll>;
using vld = vector<ld>;
using vvld = vector<vld>;
using vvvld = vector<vvld>;
using vs = vector<string>;
using pll = pair<ll, ll>;
using vp = vector<pll>;
#define rep(i, n) for(ll i = 0, i##_end = (n); i < i##_end; i++)
#define repb(i, n) for(ll i = (n)-1; i >= 0; i--)
#define repr(i, a, b) for(ll i = (a), i##_end = (b); i < i##_end; i++)
#define reprb(i, a, b) for(ll i = (b)-1, i##_end = (a); i >= i##_end; i--)
#define ALL(a) (a).begin(), (a).end()
#define SZ(x) ((ll)(x).size())
const ll MOD = 1000000007;
const ll INF = 100000000000000000LL;
const ld EPS = 1e-12L;
const ld PI = 3.1415926535897932385L;
inline ll GCD(ll a, ll b){ return b?GCD(b, a % b):a; }
inline ll LCM(ll a, ll b){ return a/GCD(a, b)*b; }
inline ll powmod(ll x, ll y, ll m = MOD){ ll r=1; while(y){ if(y&1) r*=x; x*=x; r%=m; x%=m; y>>=1; } return r; }
template<typename S, typename T>inline bool chmax(S &a, const T &b){ if(a<b) { a=b; return 1; } return 0; }
template<typename S, typename T>inline bool chmin(S &a, const T &b){ if(b<a) { a=b; return 1; } return 0; }
#ifdef OJ_LOCAL
#include "dump.hpp"
#else
#define dump(...) ((void)0)
#endif
template <typename T> bool print_(const T& a) {
    cout << a;
    return true;
}
template <typename T> bool print_(const vector<T> &vec) {
    for(auto &a : vec) {
        cout << a;
        if(&a != &vec.back()) cout << " ";
    }
    return false;
}
template <typename T> bool print_(const vector<vector<T>>& vv) {
    for(auto &v : vv) {
        for(auto &a : v) {
            cout << a;
            if(&a != &v.back()) cout << " ";
        }
        if(&v != &vv.back()) cout << "\n";
    }
    return false;
}
void print() { cout << "\n"; }
template <typename Head, typename... Tail> 
void print(Head &&head, Tail &&... tail) {
    bool f = print_(head);
    if(sizeof...(tail) != 0) cout << (f ? " " : "\n");
    print(forward<Tail>(tail)...);
}
#pragma endregion

const int MAX = 5010;
using bs = bitset<5000>;
bs bl[MAX], br[MAX];

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    ll n, k;
    cin >> n >> k;
    vll a(n);
    rep(i, n){
        cin >> a[i];
    }
    sort(ALL(a));
    bl[0][0] = 1;
    br[n+1][0] = 1;
    repr(i, 1, n+1){
        bl[i] = bl[i-1] | (bl[i-1] << a[i-1]);
    }
    reprb(i, 1, n+1){
        br[i] = br[i+1] | (br[i+1] << a[i-1]);
    }
    rep(i, n){
        bs S;
        rep(j, 5000){
            if(br[i+2][j]){
                S |= bl[i] << j;
            }
        }
        bs y;
        repr(j, max(k-a[i], 0ll), k){
            y[j] = 1;
        }
    }
    // snippet
    auto cond = [&](ll mid){
        bs S;
        rep(j, 5000){
            if(br[mid+2][j]){
                S |= bl[mid] << j;
            }
        }
        bs y;
        repr(j, max(k-a[mid], 0ll), k){
            y[j] = 1;
        }
        return (S&y).any();
    };
    auto BSMin = [&](){
        ll lb = -1;
        ll ub = n;
        while(ub - lb > 1){
            ll mid = ((lb + ub) >> 1);
            (cond(mid) ? ub : lb) = mid;
        }
        return ub;
    };
    print(BSMin());
}
