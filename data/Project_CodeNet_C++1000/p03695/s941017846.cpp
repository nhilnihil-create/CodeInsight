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
    vector<ll> cnt(9);
    rep(i, n) {
        ll a;
        cin >> a;
        if (a >= 3200) a = 3200;
        cnt[a / 400]++;
    }

    ll no = 0;
    rep(i, 8) {
        if (cnt[i] == 0) no++;
    }

    if (no == 8 && cnt[8] != 0) {
        cout << 1 << " ";
    } else {
        cout << 8 - no << " ";
    }

    cout << 8 - no + cnt[8] << "\n";

    return 0;
}