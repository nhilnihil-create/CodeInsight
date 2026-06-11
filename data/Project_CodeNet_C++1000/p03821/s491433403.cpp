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
    ll n; cin >> n;
    vector<ll> a(n), b(n);
    rep(i, n) cin >> a[i] >> b[i];
    ll ans = 0;
    ll sum = 0;
    for(ll i=n-1; i>=0; i--) {
        ll cnt;
        if((a[i]+sum) % b[i] == 0) cnt = 0;
        else cnt = b[i] - ((a[i]+sum) % b[i]);
        ans += cnt;
        sum += cnt;
    }
    cout << ans << endl;
}