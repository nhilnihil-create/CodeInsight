#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; ++i)
using ll = long long;
using namespace std;
const int INF = 1e9;

int main() {
    ll N;
    cin >> N;
    vector<ll> A(N), B(N);
    rep(i, N) cin >> A[i] >> B[i];

    ll ans = 0;
    for (int i = N - 1; i >= 0; --i) {
        ans += (B[i] - (A[i] + ans) % B[i]) % B[i];
    }

    cout << ans << endl;

    return 0;
}