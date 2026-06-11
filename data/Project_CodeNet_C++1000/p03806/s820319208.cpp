#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <functional>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <numeric>
using namespace std;
using llong = long long;

const llong INF = 1ll << 60ll;
llong n;
llong x, y;
llong ta[45];
llong tb[45];
llong tc[45];
llong dp[45][405][405];

int main() {
    for (int i = 0; i < 45; i++) {
        for (int j = 0; j < 405; j++) {
            for (int k = 0; k < 405; k++) {
                if (j == 0 && k == 0) dp[i][j][k] = 0;
                else dp[i][j][k] = INF;
            }
        }
    }

    cin >> n >> x >> y;
    for (int i = 1; i <= n; i++) {
        cin >> ta[i] >> tb[i] >> tc[i];
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 400; j++) {
            for (int k = 1; k <= 400; k++) {
                dp[i][j][k] = dp[i - 1][j][k];
                if (j >= ta[i] && k >= tb[i] && dp[i - 1][j - ta[i]][k - tb[i]] != INF) {
                    dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j - ta[i]][k - tb[i]] + tc[i]);
                }
            }
        }
    }

    llong ans = INF;
    llong tmpx = x;
    llong tmpy = y;
    while (tmpx <= 400 && tmpy <= 400) {
        ans = min(ans, dp[n][tmpx][tmpy]);
        tmpx += x;
        tmpy += y;
    }

    if (ans == INF) {
        cout << -1 << endl;
    }
    else {
        cout << ans << endl;
    }
    
    return 0;
}
