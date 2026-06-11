#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <list>
#include <iterator>
#include <cassert>
#include <numeric>
#include <functional>
#include <cassert>
//#include <numeric>
#pragma warning(disable:4996) 
 
typedef long long ll;
typedef unsigned long long ull;
#define MIN(a, b) ((a)>(b)? (b): (a))
#define MAX(a, b) ((a)<(b)? (b): (a))
#define LINF  9223300000000000000
#define LINF2 1223300000000000000
#define INF 2140000000
const long long MOD = 1000000007;
//const long long MOD = 998244353;

using namespace std;

ll d[200][200];

void solve()
{
    int n, m, R;
    scanf("%d%d%d", &n, &m, &R);
    vector<int> r(R);
    int i, j;
    for (i = 0; i < R; i++) {
        scanf("%d", &r[i]); r[i]--;
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (i != j) d[i][j] = LINF2;
        }
    }

    for (i = 0; i < m; i++) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c); a--; b--;
        d[a][b] = MIN(d[a][b], c);
        d[b][a] = MIN(d[b][a], c);
    }

    for(int k = 0; k < n; ++k)
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < n; ++j) d[i][j] = min(d[i][j], d[i][k] + d[k][j]);

    ll ans = LINF;
    vector<int> v(R);
    for (i = 0; i < R; i++) v[i] = i;
    do {
        ll ans0 = 0;
        for (i = 1; i < R; i++) {
            ans0 += d[r[v[i - 1]]][r[v[i]]];
        }
        ans = MIN(ans, ans0);
    } while( next_permutation(v.begin(), v.end()) );

    printf("%lld\n", ans);

    return;
}

int main(int argc, char* argv[])
{
#if 1
    solve();
#else
    int T;
    scanf("%d", &T);
    int t;
    for(t=0; t<T; t++) {
        //printf("Case #%d: ", t+1);
        solve();
    }
#endif
    return 0;
}

