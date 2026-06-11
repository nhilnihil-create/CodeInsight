#include <algorithm>
#include <cmath>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <queue>
#include <set>
#include <tuple>
#include <vector>

using namespace std;

#define rep(i, n) for (int64_t i = 0; i < (n); i++)
#define irep(i, n) for (int64_t i = 0; i <= (n); i++)
#define rrep(i, n) for (int64_t i = (n)-1; i >= 0; i--)
#define rirep(i, n) for (int64_t i = n; i >= 0; i--)

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    rep(i, n)
    {
        cin >> a[i];
    }

    vector<vector<bool>> dp1(n + 1, vector<bool>(k)), dp2(n + 1, vector<bool>(k));
    irep(i, n) rep(j, k)
    {
        if (i == 0) {
            dp1[i][j] = dp2[n - i][j] = (j == 0);
        } else {
            dp1[i][j] = dp1[i - 1][j] || (j - a[i - 1] >= 0 && dp1[i - 1][j - a[i - 1]]);
            dp2[n - i][j] = dp2[n - (i - 1)][j] || (j - a[n - i] >= 0 && dp2[n - (i - 1)][j - a[n - i]]);
        }
    }

    int result = 0;
    rep(i, n)
    {
        vector<int64_t> psum(k + 1);
        psum[0] = 0;
        rep(j, k)
        {
            psum[j + 1] = psum[j] + (dp2[i + 1][j] ? 1 : 0);
        }

        int64_t cnt = 0;
        rep(j, k)
        {
            if (dp1[i][j]) {
                cnt += psum[max(0L, k - j)] - psum[max(0L, k - a[i] - j)];
            }
        }
        if (cnt == 0) {
            result++;
        }
    }
    cout << result << endl;

    return 0;
}