#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; ++i)
using ll = long long;
using namespace std;
const int INF = 1e9;

int main() {
    int N, K;
    cin >> N >> K;
    vector<ll> A(N), B(N);
    rep(i, N) cin >> A[i];

    ll ans = 1e18;
    rep(bit, 1 << N) {
        if (__builtin_popcount(bit) < K)
            continue;
        B = A;

        ll now = 0, ma = A[0];
        for (int i = 1; i < N; i++) {
            if (bit & (1 << i)) {
                B[i] = max(ma + 1, B[i]);
                now += B[i] - A[i];
            }
            ma = max(ma, B[i]);
        }
        ans = min(ans, now);
    }
    cout << ans << endl;

    return 0;
}