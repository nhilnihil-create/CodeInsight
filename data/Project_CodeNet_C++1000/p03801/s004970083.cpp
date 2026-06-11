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
    ll n;
    cin >> n;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    map<ll, vector<ll>> m;
    rep(i, n) m[a[i]].push_back(i);
    vector<ll> vals;
    for(auto x : m) vals.push_back(x.first);
    reverse(all(vals));
    vals.push_back(0);
    vector<ll> ans(n, 0);
    ll cnt = 0, idx = LONG_LONG_MAX;
    rep(i, sz(vals) - 1) {
        rep(ii, sz(m[vals[i]])) {
            idx = min(idx, m[vals[i]][ii]);
        }
        cnt += sz(m[vals[i]]);
        ans[idx] += cnt * (vals[i] - vals[i + 1]);
    }
    rep(i, n) printf("%lld\n", ans[i]);
    return 0;
}
