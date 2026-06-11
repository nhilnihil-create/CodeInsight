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
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    ll ans = LONG_LONG_MAX;
    rep(bit, 1 << n) {
        ll cnt = __builtin_popcountll(bit);
        if (cnt != k) continue;
        ll tmp = 0, next = -1;
        rep(i, n) {
            if (i == 0) {
                next = a[i] + 1;
            }
            else if ((bit & (1 << i)) == 0) {
                next = max(next, a[i] + 1);
            }
            else {
                if (next <= a[i]) {
                    next = a[i] + 1;
                }
                else {
                    tmp += next - a[i];
                    next++;
                }
            }
        }
        ans = min(ans, tmp);
    }
    cout << ans << endl;
    return 0;
}
