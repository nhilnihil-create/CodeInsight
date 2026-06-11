#include <bits/stdc++.h>

using namespace std;

const int NMAX = 2010;
long long a[NMAX];
long long dp[NMAX][NMAX];

int main() {
    int n;
    long long x;
    cin >> n >> x;

    for (int i = 0; i < n; ++i) cin >> a[i];
    
    for (int i = 0; i < n; ++i) {
        dp[i][0] = a[i];
        for (int k = 1; k < n; ++k) {
            int diff = (i - k + n) % n;
            dp[i][k] = min(dp[i][k - 1], a[diff]);
        }
    }

    long long ans = INT64_MAX;
    for (int k = 0; k < n; ++k) {
        long long tmp = k * x;
        for (int i = 0; i < n; ++i) {
            tmp += dp[i][k];
        }
        ans = min(ans, tmp);
    }

    cout << ans << endl;
    return 0;
}