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

bool ok(const vs64& a, int idx)
{
    s64 w = a[idx];
    int n = a.size();
    int l = 0, r = 0;
    while (true)
    {
        s64 sum = 0;
        while (r < n && a[r] <= 2 * w)
        {
            if (idx != r) sum += a[r];
            ++r;
        }
        if (l == r) return false;
        if (r == n) break;
        l = r;
        w += sum;
    }
    return true;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    vs64 a(n);
    rep (i, n) cin >> a[i];
    sort(a.begin(), a.end());

    int l = -1, r = n - 1;
    while (l + 1 < r)
    {
        int m = (l + r) / 2;
        if (ok(a, m)) r = m;
        else l = m;
    }

    cout << n - r << "\n";
    return 0;
}

