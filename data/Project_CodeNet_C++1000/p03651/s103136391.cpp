#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 1000000000;
const int MOD = MM + 7;
const int MAX = 510000;
#define rep(i, n) for(ll i=0; i<n; i++)
#define Rep(i, j, n) for(ll i=j; i<n; i++)
#define all(vec) vec.begin(), vec.end()
template<class T> inline bool chmin(T& a, T b) {if(a > b) {a = b; return true;} return false;}
template<class T> inline bool chmax(T& a, T b) {if(a < b) {a = b; return true;} return false;}
const ll INF = 1LL << 60;
const double pi = acos(-1.0);

ll GCD(ll x, ll y) {
    if (y == 0) return x;
    else return GCD(y, x % y);
}

int main() {
    ll n, k; cin >> n >> k;
    ll gcd = 0;
    set<ll> s;
    rep(i, n) {
        ll a; cin >> a;
        s.insert(a);
        gcd = GCD(gcd, a);
    }
    cout << (s.count(k) || (k <= *s.rbegin() && k%gcd == 0) ? "POSSIBLE" : "IMPOSSIBLE") << endl;
}
