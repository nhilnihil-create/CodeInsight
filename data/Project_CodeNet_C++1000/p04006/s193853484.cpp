#include <bits/stdc++.h>
#define FOR(i, a, n) for(ll i = (ll)a; i < (ll)n; i++)
#define rep(i, n) FOR(i, 0, n)
#define ALL(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;

constexpr ll Mod = 998244353;
constexpr ll mod = 1e9 + 7;
constexpr ll inf = 1LL << 60;

template <typename T> constexpr bool chmax(T &a, const T b) {
    if(a >= b) return false;
    a = b;
    return true;
}
template <typename T> constexpr bool chmin(T &a, const T b) {
    if(a <= b) return false;
    a = b;
    return true;
}

/*-------------------------------------------*/

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;
    ll x;
    cin >> n >> x;
    vector<ll> a(n), b(n, inf);
    ll ans = inf;
    rep(i, n) cin >> a[i];
    rep(i, n) {
        ll num = x * i;
        vector<ll> v(n);
        rep(j, n) num += (v[j] = min(b[j ? j - 1 : n - 1], a[j]));
        b = v;
        chmin(ans, num);
    }

    cout << ans << endl;

    return 0;
}