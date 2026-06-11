#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

template <class T, class U>
void chmin(T& t, const U& u) {
    if (t > u) t = u;
}
template <class T, class U>
void chmax(T& t, const U& u) {
    if (t < u) t = u;
}

int main() {
    int N, K;
    cin >> N >> K;
    vector<ll> a(N);
    rep(i, N) cin >> a[i];

    ll ans = 10e16;
    for (int bit = 0; bit < (1 << (N - 1)); ++bit) {
        if (__builtin_popcount(bit) + 1 < K) continue;

        bool ok = true;
        ll tmp = 0;
        ll lmax = a[0];
        for (int i = 0; i < N - 1; ++i) {
            if (bit & (1 << i)) {
                ll next = max(lmax + 1, a[i + 1]);
                tmp += next - a[i + 1];
                lmax = next;
            } else {
                if (a[i + 1] > lmax) {
                    ok = false;
                    break;
                }
            }
        }
        if (ok) chmin(ans, tmp);
    }
    cout << ans << endl;
}