#include <bits/stdc++.h>
using namespace std;
const long double PI = 3.14159265358979323846;
long long dp[55][55][2505] = {0};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, a;
    cin >> n >> a;
    vector<int> arr(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
    }
    dp[0][0][0] = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= n; ++j) {
            for (int k = 0; k <= 2500 - arr[i + 1]; ++k) {
                dp[i + 1][j][k] += dp[i][j][k];
                dp[i + 1][j + 1][k + arr[i + 1]] += dp[i][j][k];
            }
        }
    }
    long long ans = 0;
    for (int i = 1; i <= n; ++i) {
        ans += dp[n][i][a * i];
    }
    cout << ans << '\n';

    return 0;
}
