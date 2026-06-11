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

struct edge
{
    int from, to, cost;
};

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    vector< edge > e;
    const int inf = 1e9;
    int d[n][n];
    rep (i, n) for (int j = i + 1; j < n; ++j) d[i][j] = d[j][i] = inf;
    rep (i, n) d[i][i] = 0;
    rep (i, m)
    {
        int a, b, c;
        cin >> a >> b >> c;
        --a, --b;
        e.push_back({a, b, c});
        e.push_back({b, a, c});
        d[a][b] = c;
        d[b][a] = c;
    }

    rep (k, n)
    {
        rep (i, n)
        {
            rep (j, n)
            {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }

    int ans = 0;
    rep (i, e.size())
    {
        bool found = false;
        rep (j, n)
        {
            int from = e[i].from;
            int to = e[i].to;
            int cost = e[i].cost;
            if (d[j][to] == d[j][from] + cost)
            {
                found = true;
                break;
            }
        }
        if (!found) ++ans;
    }

    cout << ans / 2 << "\n";
    return 0;
}

