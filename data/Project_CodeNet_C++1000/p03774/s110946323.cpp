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

int main() {
    ll n, m; cin >> n >> m;
    vector<ll> a(n), b(n); rep(i, n) cin >> a[i] >> b[i];
    vector<ll> c(m), d(m); rep(i, m) cin >> c[i] >> d[i];
    rep(i, n) {
        ll ans = 0, dis = INF;
        rep(j, m) if(chmin(dis, abs(a[i]-c[j])+abs(b[i]-d[j]))) ans = j;
        cout << ans + 1 << endl;
    }
}