#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; ++i)
using ll = long long;
using namespace std;
const int INF = 1e9;

int main() {
    ll N, A, B;
    cin >> N >> A >> B;
    vector<int> X(N);
    rep(i, N) cin >> X[i];

    ll ans = 0, now = X[0];
    for (int i = 1; i < N; ++i) {
        ans += min(B, (X[i] - now) * A);
        now = X[i];
    }

    cout << ans << "\n";

    return 0;
}