#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <bitset>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <numeric>
#include <iostream>
#include <iomanip>
#include <string>
#include <chrono>
#include <random>
#include <cmath>
#include <cassert>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <functional>
#include <sstream>

using namespace std;


int main(int argc, char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(12);


    int n;
    int ma, mb;
    cin >> n >> ma >> mb;

    int mx = 40 * 10 + 10;

    const int INF = 1 << 28;
    vector<vector<int>> dp(mx + 1, vector<int>(mx + 1, INF));
    dp[0][0] = 0;

    for (int i = 0; i < n; ++i) {
        int a, b, c;
        cin >> a >> b >> c;

        for (int j = mx; j >= 0; --j) {
            for (int k = mx; k >= 0; --k) {
                int nj = j + a;
                int nk = k + b;
                if (nj <= mx && nk <= mx) {
                    dp[nj][nk] = min(dp[nj][nk], dp[j][k] + c);
                }
            }
        }
    }

    auto res = INF;
    for (int i = 1; i <= mx; ++i) {
        for (int j = 1; j <= mx; ++j) {
            if (i * mb == j * ma) {
                res = min(res, dp[i][j]);
            }
        }
    }

    if (res >= INF) {
        cout << -1 << '\n';
    } else {
        cout << res << '\n';
    }

    return 0;
}