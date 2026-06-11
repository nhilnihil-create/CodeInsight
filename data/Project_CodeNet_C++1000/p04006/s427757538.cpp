#include <iostream>
#include <climits>
using namespace std;

int main() {
    long long n, x, result = LLONG_MAX;
    cin >> n >> x;
    long long a[n], dp[n][n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        dp[i][0] = a[i];
    }
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dp[j][i] = min(dp[j][i - 1], a[(j - i + n) % n]);
        }
    }
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dp[i][j] += dp[i - 1][j];
        }
    }
    for (int i = 0; i < n; i++) {
        result = min(result, i * x + dp[n - 1][i]);
    }
    cout << result;
    return 0;
}