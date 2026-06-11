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

vector< bool > reached;

void dfs(vector< vs32 >& g, int u)
{
    reached[u] = true;
    for (auto v : g[u])
    {
        if (!reached[v]) dfs(g, v);
    }
}

template <typename T = int>
struct edge { int from, to; T cost; };

template <typename T = int>
bool BellmanFord(vector< edge<T> >& e, vector< T >& d)
{
    int n = d.size();

    rep (i, n)
    {
        bool update = false;
        rep (j, e.size())
        {
            int from = e[j].from;
            int to = e[j].to;
            T c = e[j].cost;
            if (reached[to] && d[to] > d[from] + c)
            {
                d[to] = d[from] + c;
                update = true;
            }
        }
        if (i == n - 1 && update) return false;
    }
    return true;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    reached.resize(n, false);
    vector< vs32 > g(n);

    vector< edge<s64> > e(m);
    rep (i, m)
    {
        int u, v;
        s64 c;
        cin >> u >> v >> c;
        --u, --v;
        e[i].from = u;
        e[i].to = v;
        e[i].cost = -c;
        g[v].push_back(u);
    }

    dfs(g, n - 1);

    vs64 d(n, 1e18);
    d[0] = 0;
    if (BellmanFord<s64>(e, d))
    {
        cout << -d[n - 1] << "\n";
    }
    else
    {
        cout << "inf\n";
    }

    return 0;
}

