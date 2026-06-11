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
    int h, w;
    cin >> w >> h;
    vector<pair<ll, int>> v;
    rep(i, w) {
        ll p;
        cin >> p;
        v.emplace_back(p, 0);
    }
    rep(i, h) {
        ll q;
        cin >> q;
        v.emplace_back(q, 1);
    }
    sort(all(v));

    ll cnt = (ll)(w + 1) * (h + 1) - 1;
    ll zero = h + 1, one = w + 1;
    ll ans = 0;
    for (auto p : v) {
        ll x = p.first;
        int k = p.second;
        if (k == 0 && zero > 0 && cnt > 0) {
            ans += x * min(zero, cnt);
            one--;
            cnt -= min(zero, cnt);
        }
        if (k == 1 && one > 0 && cnt > 0) {
            ans += x * min(one, cnt);
            zero--;
            cnt -= min(one, cnt);
        }
    }
    cout << ans << endl;
}
