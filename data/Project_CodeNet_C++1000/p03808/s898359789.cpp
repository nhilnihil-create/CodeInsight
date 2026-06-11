#include <bits/stdc++.h>
#define FOR(i, a, n) for(ll i = (ll)a; i < (ll)n; i++)
#define rep(i, n) FOR(i, 0, n)
using namespace std;
typedef long long ll;

const ll mod = 1e9 + 7;

template <class T> inline bool chmax(T &a, const T &b) {
    if(a >= b) return false;
    a = b;
    return true;
}
template <class T> inline bool chmin(T &a, const T &b) {
    if(a <= b) return false;
    a = b;
    return true;
}

/*-------------------------------------------*/

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    ll n;
    cin >> n;
    ll a[n], k = 0;
    rep(i, n) cin >> a[i], k += a[i];
    if(k % (n * (n + 1) / 2)) {
        cout << "NO\n";
        return 0;
    }
    k /= n * (n + 1) / 2;
    rep(i, n) {
        ll x = a[(i + 1) % n] - a[i] - k;
        if(x > 0 || (-x) % n != 0) {
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
}