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

    int n, ma, mb;
    cin >> n >> ma >> mb;
    vs32 a(n), b(n), c(n);
    int sa = 0, sb = 0;
    rep (i, n)
    {
        cin >> a[i] >> b[i] >> c[i];
        sa += a[i];
        sb += b[i];
    }

    int ans = 1e9;
    int times = 1;
    while (ma * times <= sa && mb * times <= sb)
    {
        int Ma = ma * times;
        int Mb = mb * times;
        vector< vector< vs32 > > dp(n + 1, vector<vs32>(Ma + 1, vs32(Mb + 1, 1e9)));
        rep (i, n + 1) dp[i][0][0] = 0;
        rep (i, n)
        {
            rep (j, Ma + 1)
            {
                rep (k, Mb + 1)
                {
                    if (a[i] > j  || b[i] > k)
                    {
                        dp[i + 1][j][k] = dp[i][j][k];
                    }
                    else
                    {
                        dp[i + 1][j][k] = MIN(dp[i][j][k], dp[i][j - a[i]][k - b[i]] + c[i]);
                    }
                }
            }
        }
        if (dp[n][Ma][Mb] != 1e9)
        {
            ans = MIN(ans, dp[n][Ma][Mb]);
        }
        ++times;
    }

    if (ans == 1e9) ans = -1;
    cout << ans << "\n";
    return 0;
}

