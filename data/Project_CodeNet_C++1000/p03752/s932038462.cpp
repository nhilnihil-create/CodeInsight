#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
#define reps(i, n) for (int i = 1, i##_len = (n); i <= i##_len; ++i)
#define rrep(i, n) for (int i = ((int)(n)-1); i >= 0; --i)
#define rreps(i, n) for (int i = ((int)(n)); i > 0; --i)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define repc2(i, s, n) for (int i = (s); i <= (int)(n); i++)
#define inf 2e9
#define linf 9000000000000000000ll
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;

int n, k;

int main() {
    cin >> n >> k;
    vector<ll> v(n);
    rep(i, n) cin >> v[i];
    ll ans = linf;
    for (int bit = 0; bit < (1 << n); bit++) {
        if (__builtin_popcount(bit) == k) {
            ll cur_max = 0, res = 0;
            rep(i, n) {
                if ((bit >> i) & 1) {
                    cur_max = max(v[i], cur_max + 1);
                    res += cur_max - v[i];
                } else {
                    cur_max = max(cur_max, v[i]);
                }
            }
            ans = min(ans, res);
        }
    }
    cout << ans << endl;
    return 0;
}