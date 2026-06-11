#include <algorithm>
#include <cassert>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

using namespace std;
using ll = long long;

constexpr ll infl = 10000000000000007LL;
constexpr int inf = 1000000007;

int main() {
    int n, ma, mb;
    cin >> n >> ma >> mb;
    vector<int> c(n), d(n);
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b >> c[i];
        d[i] = mb * a - ma * b;
    }

    vector<vector<int>> dp(n, vector<int>(7201, inf));
    dp[0][d[0] + 3600] = c[0];
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j <= 7200; ++j) {
            dp[i][j] = dp[i - 1][j];
            if (j == d[i] + 3600)
                dp[i][j] = min(dp[i][j], c[i]);
            if (j - d[i] >= 0)
                dp[i][j] = min(dp[i][j], dp[i - 1][j - d[i]] + c[i]);
        }
    }

    if (dp.back()[3600] <= 4000)
        cout << dp.back()[3600] << endl;
    else
        cout << -1 << endl;
    return 0;
}