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
template <typename T>
inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <typename T>
inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return 1;
    }
    return 0;
}

int main() {
    ll n, m, k;
    cin >> n >> m >> k;

    bool ok = false;
    rep(i, n + 1) {
        rep(j, m + 1) {
            if (k == j * n + i * m - 2 * i * j) ok = true;
        }
    }

    if (ok)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}