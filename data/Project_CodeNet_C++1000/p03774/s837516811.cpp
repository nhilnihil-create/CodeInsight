#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr long long MOD = 1000000007;
constexpr long long INF = 1LL << 60;
const long double PI = acosl(-1.0);
constexpr long double EPS = 1e-11;
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
int main(){
    ll n, m;
    cin >> n >> m;
    ll a[n], b[n];
    for (ll i = 0; i < n; i++) cin >> a[i] >> b[i];
    ll c[m], d[m];
    for (ll i = 0; i < m; i++) cin >> c[i] >> d[i];
    for (ll i = 0;i<n;i++){
        ll ans = INF;
        ll res;
        for (ll j = 0; j < m; j++) {
            if (chmin(ans, abs(a[i] - c[j]) + abs(b[i] - d[j]))) res = j + 1;
        }
        cout << res << endl;
    }
}