#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; ++i)
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define ALL(vec) vec.begin(), vec.end()
#define rALL(vec) vec.rbegin(), vec.rend()
using namespace std;
using ll = long long;
// ------------------------------

int main() {
    int N, M;
    cin >> N >> M;
    ll ans = 1;
    if (N == M) {
        rep(i, N) ans =
            (ans * (i + 1) % (1000000000 + 7)) * (i + 1) % (1000000000 + 7);
        ans = ans * 2 % (1000000000 + 7);
    } else if (abs(N - M) == 1) {
        ans = max(N, M);
        rep(i, min(N, M)) ans =
            (ans * (i + 1) % (1000000000 + 7)) * (i + 1) % (1000000000 + 7);
    } else
        ans = 0;
    cout << ans << endl;
    return 0;
}