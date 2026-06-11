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

    int N, M, R;
    cin >> N >> M >> R;

    vs32 r(R);
    rep (i, R) { cin >> r[i]; --r[i]; }

    int d[N][N];
    rep (i, N) rep (j, N) d[i][j] = 1e9;
    rep (i, N) d[i][i] = 0;

    rep (i, M)
    {
        int a, b, c;
        cin >> a >> b >> c;
        --a, --b;
        d[a][b] = c;
        d[b][a] = c;
    }

    rep (k, N)
    {
        rep (i, N)
        {
            rep (j, N)
            {
                d[i][j] = MIN(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }

    vs32 v(R);
    rep (i, R) v[i] = i;

    int ans = 1e9;
    do {
        int temp = 0;
        rep (i, R - 1)
        {
            int from = r[v[i]];
            int to = r[v[i + 1]];
            temp += d[from][to];
        }
        ans = MIN(ans, temp);
    } while (next_permutation(v.begin(), v.end()));

    cout << ans << "\n";
    return 0;
}

