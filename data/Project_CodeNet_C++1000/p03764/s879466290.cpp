#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for (int i = (int)(n - 1); i >= 0; i--)
#define all(x) (x).begin(), (x).end()
#define sz(x) int(x.size())
#define get_unique(x) x.erase(unique(all(x)), x.end());
typedef long long ll;
typedef complex<double> Complex;
const int INF = 1e9;
const ll MOD = 1e9 + 7;
const ll LINF = 1e18;
template <class T>
bool chmax(T &a, const T &b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
bool chmin(T &a, const T &b) {
    if (b < a) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
vector<T> make_vec(size_t a) {
    return vector<T>(a);
}
template <class T, class... Ts>
auto make_vec(size_t a, Ts... ts) {
    return vector<decltype(make_vec<T>(ts...))>(a, make_vec<T>(ts...));
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<ll> x(n), y(m);
    rep(i, n) cin >> x[i];
    rep(i, m) cin >> y[i];

    ll tate = 0;
    rep(i, n - 1) {
        ll now = x[i + 1] - x[i];
        (now *= (ll)(i + 1)) %= MOD;
        (now *= (ll)(n - i - 1)) %= MOD;
        (tate += now) %= MOD;
    }

    ll yoko = 0;
    rep(i, m - 1) {
        ll now = y[i + 1] - y[i];
        (now *= (ll)(i + 1)) %= MOD;
        (now *= (ll)(m - i - 1)) %= MOD;
        (yoko += now) %= MOD;
    }

    cout << tate * yoko % MOD << endl;
}
