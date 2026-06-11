#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, n) for (ll i = 0; i < n; ++i)
#define P pair<ll, ll>
#define Graph vector<vector<ll>>
#define fi first
#define se second
constexpr ll mod = 1000000007;
constexpr ll INF = (1ll << 60);
constexpr double pi = 3.14159265358979323846;
template <typename T>
inline bool chmax(T &a, T b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <typename T>
inline bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return 1;
    }
    return 0;
}

ll mypow(ll a, ll b) {
    ll ret = 1;
    while (b--) {
        ret *= a;
    }
    return ret;
}

int main() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];

    sort(a.begin(), a.end());
    ll ans = 0;
    rep(i, a[n - 1] + 1) {
        vector<ll>::iterator pos1, pos2;
        pos1 = upper_bound(a.begin(), a.end(), i - 2);
        pos2 = upper_bound(a.begin(), a.end(), i + 1);
        ll key1 = distance(a.begin(), pos1);
        ll key2 = distance(a.begin(), pos2);
        chmax(ans, key2 - key1);
    }

    cout << ans << "\n";
    return 0;
}