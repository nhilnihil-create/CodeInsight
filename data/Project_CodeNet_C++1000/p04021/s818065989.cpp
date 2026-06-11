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

// {10, 3, 1, -5, 1} -> {3, 2, 1, 0, 1}
template<typename T>
vector<T> CoordinateCompression(const vector<T> &x){
    int n = x.size();
    vector<T> y = x, ret(n);
    sort(y.begin(), y.end());
    y.erase(unique(y.begin(), y.end()), y.end());
    for(int i = 0; i < n; i++) {
        ret[i] = lower_bound(y.begin(), y.end(), x[i]) - y.begin();
    }
    return ret;
}
int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    ll n;
    cin >> n;
    vll a(n);
    rep(i, n){
        cin >> a[i];
    }
    a = CoordinateCompression(a);
    ll ans = 0;
    for(int i = 0; i < n; i += 2){
        if(a[i]%2!=0) ans++;
    }
    print(ans);
}
