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
    // ifstream in("input.txt");
    // cin.rdbuf(in.rdbuf());
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> a(n, vector<ll>(m));
    rep(i, n) rep(ii, m) cin >> a[i][ii];
    ll ans = LONG_LONG_MAX;
    rep(i, m) {
        map<ll, ll> cnt;
        rep(ii, n) cnt[a[ii][0]]++;
        ll mv = -1, mi = -1;
        for(auto x : cnt) {
            if (mv < x.second) {
                mv = x.second;
                mi = x.first;
            }
        }
        ans = min(ans, mv);
        rep(ii, n) {
            for(auto it = a[ii].begin(); it != a[ii].end(); it++) {
                if (*it == mi) {
                    a[ii].erase(it++);
                    break;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}
