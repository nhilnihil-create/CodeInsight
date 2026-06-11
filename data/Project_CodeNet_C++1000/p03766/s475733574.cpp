#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 1000000, INDEX = 1;
const long long MOD = 1000000007;

long long n, dp[MAX_N + INDEX], ps[MAX_N + INDEX];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    cin >> n;

    dp[0] = 1, dp[1] = n;
    ps[0] = 0, ps[1] = n;

    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + ps[max(0, i - 3)] + n * (n - 1) - max(0, i - 3);

        dp[i] %= MOD;

        ps[i] = ps[i - 1] + dp[i];

        ps[i] %= MOD;
    }

    cout << dp[n] << endl;

    return 0;
}
