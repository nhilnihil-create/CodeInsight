#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(ll i = 0, i##_len = (n); i < i##_len; i++)
#define reps(i, s, n) for(ll i = (s), i##_len = (n); i < i##_len; i++)
#define rrep(i, n) for(ll i = (n) - 1; i >= 0; i--)
#define rreps(i, e, n) for(ll i = (n) - 1; i >= (e); i--)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
#define len(x) ((ll)(x).length())

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    // std::ifstream in("input.txt");
    // std::cin.rdbuf(in.rdbuf());
    const ll mod = 1e9 + 7;
    ll n;
    cin >> n;
    vector<ll> t(n), a(n);
    rep(i, n) cin >> t[i];
    rep(i, n) cin >> a[i];
    vector<pair<ll, ll>> h(n, make_pair(-1, -1));
    rep(i, n) {
        if ((i == 0) || (t[i] != t[i - 1])) {
            h[i].first = t[i];
            h[i].second = t[i];
            continue;
        }
        h[i].first = 1;
        h[i].second = t[i];
    }
    rrep(i, n) {
        if ((i == (n - 1)) || (a[i] != a[i + 1])) {
            if ((a[i] < h[i].first) || (a[i] > h[i].second)) {
                cout << 0 << endl;
                return 0;
            }
            h[i].first = a[i];
            h[i].second = a[i];
            continue;
        }
        h[i].second = min(h[i].second, a[i]);
    }
    ll ans = 1;
    rep(i, n) {
        ans = (ans * (h[i].second - h[i].first + 1)) % mod;
    }
    // rep(i, n) printf("i=%lld, h=(%lld, %lld)\n", i, h[i].first, h[i].second);
    cout << ans << endl;
    return 0;
}
