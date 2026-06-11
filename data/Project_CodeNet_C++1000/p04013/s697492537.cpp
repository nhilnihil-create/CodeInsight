#include <bits/stdc++.h>
using namespace std;

int64_t dp[51][2501];

signed main () {
    int n, a;
    cin >> n >> a;
    vector < int > x(n + 1, 0);
    dp[0][0] = 1;
    for (int i = 1; i <= n; ++i) {
        cin >> x[i];
        for (int j = n; j >= 1; --j) {
            for (int sum = 2500; sum >= x[i]; --sum) 
                dp[j][sum] += dp[j - 1][sum - x[i]];
        }
    }
    int64_t ans = 0;
    for (int i = 1; i <= n; ++i)
        ans += dp[i][a * i];
    cout << ans << '\n';
}
