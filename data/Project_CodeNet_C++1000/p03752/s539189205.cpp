#include <bits/stdc++.h>
#define FOR(i, a, n) for(ll i = (ll)a; i < (ll)n; i++)
#define rep(i, n) FOR(i, 0, n)
#define ALL(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;

constexpr int mod = 1e9 + 7;

template <class T> inline bool chmax(T &a, const T b) {
    if(a >= b) return false;
    a = b;
    return true;
}
template <class T> inline bool chmin(T &a, const T b) {
    if(a <= b) return false;
    a = b;
    return true;
}

/*-------------------------------------------*/

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int k, n, a[20];
    ll ans = 1e18;

    cin >> n >> k;
    rep(i, n) cin >> a[i];

    rep(i, 1 << n) {
        int cnt = 0;
        int mx = 0;
        ll cost = 0;
        rep(j, n) {
            if((i >> j) & 1) {
                if(!chmax(mx, a[j])) cost += (++mx) - a[j];
                cnt++;
            } else if(chmax(mx, a[j]))
                cnt++;
        }
        if(cnt >= k) chmin(ans, cost);
    }

    cout << ans << endl;

    return 0;
}