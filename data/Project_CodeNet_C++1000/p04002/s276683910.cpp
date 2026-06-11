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

using P = pair<int, int>;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int h, w, n;
    cin >> h >> w >> n;

    map<P, int> m;
    rep (i, n)
    {
        int a, b;
        cin >> a >> b;
        --a, --b;
        rep (j, 3)
        {
            rep (k, 3)
            {
                int y = a - j;
                int x = b - k;
                if (IN(0, h - 2, y) && IN(0, w - 2, x))
                {
                    ++m[P{x, y}];
                }
            }
        }
    }

    vs32 ans(10, 0);
    for (auto& item : m)
    {
        ++ans[item.second];
    }
    s64 zero = (s64)(h - 2) * (w - 2);
    rep (i, 10) zero -= ans[i];

    cout << zero << "\n";
    for (int i = 1; i < 10; ++i)
    {
        cout << ans[i] << "\n";
    }

    return 0;
}

