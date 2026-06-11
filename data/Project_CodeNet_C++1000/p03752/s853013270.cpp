#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i<(n); i++)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
using namespace std;
using ll = long long;

ll bit_count(ll bits) {
    ll cnt = 0;
    for (; bits != 0; bits >>= 1) {
        cnt += bits & 1;
    }
    return cnt;
}

int main() {
    int N, K;
    cin >> N >> K;
    vector<ll> a(N);
    rep(i, N) cin >> a[i];
    ll ans = 1ll << 60;

    rep(bit, 1 << N) {
        if (bit_count(bit) != K) continue;
        if ((bit & 1) == 0) continue;

        ll now = 0;
        ll prev = 0;
        rep(j, N) {
            if (bit >> j & 1) {
                ll diff = max(prev + 1ll - a[j], 0ll);
                now += diff;
                chmax(prev, a[j] + diff);
            }
            prev = max(prev, a[j]);
        }
        chmin(ans, now);
    }

    cout << ans << endl;
}
