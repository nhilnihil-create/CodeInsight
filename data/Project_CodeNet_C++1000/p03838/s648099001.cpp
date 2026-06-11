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

    s64 x, y;
    cin >> x >> y;

    s64 ans = 0;
    if (x == 0)
    {
        if (y < 0) ans = 1 - y;
        else ans = y;
    }
    else if (y < x)
    {
        if (x <= 0)
        {
            ans = 1 + x - y + 1;
        }
        else if (y <= 0)
        {
            if (-x > y)
            {
                ans = -y - x + 1;
            }
            else
            {
                ans = 1 + y + x;
            }
        }
        else
        {
            ans = 1 + x - y + 1;
        }
    }
    else
    {
        if (y <= 0)
        {
            ans = y - x;
        }
        else if (x <= 0)
        {
            if (y < -x)
            {
                ans = -y - x + 1;
            }
            else
            {
                ans = 1 + y + x;
            }
        }
        else
        {
            ans = y - x;
        }
    }

    cout << ans << "\n";
    return 0;
}

