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
    ll n, x;
    cin >> n >> x;
    vector<ll> a(n), c(n, LONG_LONG_MAX);
    rep(i, n) cin >> a[i];
    ll ans = LONG_LONG_MAX;
    rep(i, n) {
        ll cost = i * x;
        rep(ii, n) {
            c[ii] = min(c[ii], a[(ii + n - i) % n]);
            cost += c[ii];
        }
        ans = min(ans, cost);
    }
    cout << ans << endl;
    return 0;
}
