#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    int a[n + 1];
    for (int i = 0; cin >> a[i]; i++) {
    }
    a[n] = 0;
    long long result = 0, current = 0, prefix = 0, dp[n + 1];
    dp[n] = 0;
    for (int i = n - 1; i >= 0; i--) {
        dp[i] = max(a[i], 0) + dp[i + 1];
    }
    for (int i = 0; i < k; i++) {
        current += a[i];
    }
    for (int i = 0; i + k <= n; i++) {
        result = max({result, prefix + current + dp[i + k], prefix + dp[i + k]});
        current = current - a[i] + a[i + k];
        prefix += max(a[i], 0);
    }
    cout << result;
    return 0;
}
