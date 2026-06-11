#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)

using namespace std;

using ll = long long int;

int main() {
    // Input
    int N, K;
    vector<short> D;

    cin >> N >> K;
    D = vector<short>(K);
    rep(i, K) cin >> D[i];

    // Process
    vector<bool> allow(10, true);
    rep(i, K) allow[D[i]] = false;

    int ans;
    for (ans = N;; ans++) {
        int n;
        for (n = ans; n > 0 && allow[n % 10]; n /= 10)
            ;

        if (n == 0) break;
    }

    // Output
    cout << ans << endl;

    return 0;
}
