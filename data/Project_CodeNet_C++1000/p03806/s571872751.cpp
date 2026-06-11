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
#include <time.h>
#pragma warning(disable:4996) 

typedef long long ll;
typedef unsigned long long ull;
#define MIN(a, b) ((a)>(b)? (b): (a))
#define MAX(a, b) ((a)<(b)? (b): (a))
#define LINF  9223300000000000000
#define LINF2 1223300000000000000
#define LINF3 1000000000000
#define INF 2140000000
const long long MOD = 1000000007;
//const long long MOD = 998244353;

using namespace std;

int x0[205][205];
int x1[205][205];

void solve()
{
    int n, ma, mb;
    scanf("%d%d%d", &n, &ma, &mb);
    vector<int> a(n), b(n), c(n);
    int i, j;
    for (i = 0; i < n; i++) {
        scanf("%d%d%d", &a[i], &b[i], &c[i]);
    }
    for (i = 0; i <= 200; i++) {
        for (j = 0; j <= 200; j++) {
            x0[i][j] = x1[i][j] = INF;
        }
    }

    int m = n / 2, m2 = n - m;
    for (i = 0; i < (1 << m); i++) {
        int a0 = 0, b0 = 0, c0 = 0;
        for (j = 0; j < m; j++) {
            if (i & (1 << j)) {
                a0 += a[j];
                b0 += b[j];
                c0 += c[j];
            }
        }
        x0[a0][b0] = MIN(x0[a0][b0], c0);
    }

    for (i = 0; i < (1 << m2); i++) {
        int a0 = 0, b0 = 0, c0 = 0;
        for (j = 0; j < m2; j++) {
            if (i & (1 << j)) {
                a0 += a[j+m];
                b0 += b[j+m];
                c0 += c[j+m];
            }
        }
        x1[a0][b0] = MIN(x1[a0][b0], c0);
    }

    vector < pair<pair<int, int>, int> > z;
    for (i = 0; i <= 200; i++) {
        for (j = 0; j <= 200; j++) {
            if (x0[i][j] != INF) {
                z.push_back(make_pair(make_pair(i, j), x0[i][j]));
            }
        }
    }

    int ans = INF;
    for (i = 1; i <= 400; i++) {
        int aa = ma * i, bb = mb * i;
        for (j = 0; j < (int)z.size(); j++) {
            int aa0=z[j].first.first, bb0=z[j].first.second, cc0=z[j].second;
            int aa1 = aa - aa0, bb1 = bb - bb0;
            if (aa1 >= 0 && aa1 <= 200 && bb1 >= 0 && bb1 <= 200) {
                if (x1[aa1][bb1] != LINF) {
                    ans = MIN(ans, cc0 + x1[aa1][bb1]);
                }
            }
        }
    }
    if (ans == INF) {
        printf("-1\n");
    }
    else {
        printf("%d\n", ans);
    }
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
