#include <iostream>
#include <iomanip>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <cstdio>
#include <utility>
#include <string>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <numeric>

using namespace std;

typedef uint64_t u64;
typedef int64_t s64;
typedef uint32_t u32;
typedef int32_t s32;
typedef vector<s32> vs32;
typedef vector<u32> vu32;
typedef vector<s64> vs64;
typedef vector<u64> vu64;

const double PI=3.14159265358979323846;

#define MAX(x, y) ((x) < (y) ? (y) : (x))
#define MIN(x, y) ((x) > (y) ? (y) : (x))

#define rep(i, N) for(int i = 0; i < N; ++i)

#define CEIL(x, y) (((x) + (y) - 1) / (y))
#define MOD 1000000007ULL

#define IN(l, r, x) ((l) <= (x) && (x) < (r))


int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, a, b;
    cin >> n >> a >> b;

    vs64 v(n);
    rep (i, n) cin >> v[i];

    s64 dp[n + 1][n + 1];
    rep (i, n + 1) rep (j, n + 1) dp[i][j] = 0;
    s64 dp2[n + 1][n + 1];
    rep (i, n + 1) rep (j, n + 1) dp2[i][j] = 0;
    dp2[0][0] = 1;

    rep (i, n)
    {
        rep (j, n + 1)
        {
            if (j > 0)
            {
                if (dp[i][j] < dp[i][j - 1] + v[i])
                {
                    dp[i + 1][j] = dp[i][j - 1] + v[i];
                    dp2[i + 1][j] = dp2[i][j - 1];
                }
                else if (dp[i][j] == dp[i][j - 1] + v[i])
                {
                    dp[i + 1][j] = dp[i][j];
                    dp2[i + 1][j] = dp2[i][j] + dp2[i][j - 1];
                }
                else
                {
                    dp[i + 1][j] = dp[i][j];
                    dp2[i + 1][j] = dp2[i][j];
                }
            }
            else
            {
                dp[i + 1][j] = dp[i][j];
                dp2[i + 1][j] = dp2[i][j];
            }
        }
    }

    s64 num = 1;
    s64 temp = -1;
    double ans = 0;
    s64 ans2 = 0;
    for (int i = a; i <= b; ++i)
    {
        if (temp * i < dp[n][i] * num)
        {
            num = i;
            temp = dp[n][num];
        }
        if (temp * i == dp[n][i] * num)
        {
            ans2 += dp2[n][i];
        }
    }

    ans = (double)temp / num;

    cout << std::fixed << ans << "\n";
    cout << ans2 << "\n";
    return 0;
}

