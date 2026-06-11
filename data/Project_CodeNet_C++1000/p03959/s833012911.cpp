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


int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vs64 u(n, (int)1e9);
    vs64 d(n, 0);
    vs32 t(n + 1);
    vs32 a(n + 1);
    t[0] = 0;
    a[n] = 0;
    rep (i, n) cin >> t[i + 1];
    rep (i, n) cin >> a[i];

    rep (i, n)
    {
        if (t[i + 1] > t[i])
        {
            u[i] = d[i] = t[i + 1];
        }
        else
        {
            u[i] = t[i + 1];
            d[i] = 1;
        }
    }

    for (int i = n - 1; i >= 0; --i)
    {
        if (a[i] > a[i + 1])
        {
            if (u[i] < a[i] || d[i] > a[i])
            {
                cout << "0\n";
                return 0;
            }
            u[i] = d[i] = a[i];
        }
        else
        {
            if (a[i] < d[i])
            {
                cout << "0\n";
                return 0;
            }
            if (u[i] > a[i])
            {
                u[i] = a[i];
            }
        }
    }

    s64 ans = 1;
    rep (i, n)
    {
        ans *= (u[i] - d[i] + 1);
        ans %= MOD;
    }

    cout << ans << "\n";
    return 0;
}

