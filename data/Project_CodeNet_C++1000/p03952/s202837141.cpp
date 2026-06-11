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

    s64 n, x;
    cin >> n >> x;

    if (x == 1 || x == 2 * n - 1)
    {
        cout << "No\n";
        return 0;
    }

    if (n == 2)
    {
        cout << "Yes\n";
        cout << "1\n";
        cout << "2\n";
        cout << "3\n";
        return 0;
    }

    int idx = 0;
    s64 *ans;
    s64 ans1[4] = {x + 1, x - 1, x, x + 2};
    s64 ans2[4] = {x - 2, x + 1, x, x - 1};
    if (IN(1, 2 * n, x + 2)) ans = ans1;
    else if (IN(1, 2 * n, x - 2)) ans = ans2;
    s64 now = 1;
    cout << "Yes\n";
    rep (i, 2 * n - 1)
    {
        if (IN(n - 2, n + 2, i))
        {
            cout << ans[idx++] << "\n";
        }
        else
        {
            while (IN(x - 1, x + 3, now)) ++now;
            cout << now << "\n";
            ++now;
        }
    }

    return 0;
}

