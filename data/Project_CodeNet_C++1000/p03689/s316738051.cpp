// Crt. 2019-12-03  21:31:25
#include <algorithm>
#include <iostream>
#include <cstdio>
#define N 503
using namespace std;

int n, m, x, y, ans[N * 2][N * 2];

int main() {
#ifdef LOCAL_JUDGE
    freopen("work.in", "r", stdin);
    freopen("work.out", "w", stdout);
#endif

    cin >> n >> m >> x >> y;

    for (int i = x; i <= n; i += x)
        for (int j = y; j <= m; j += y)
            ans[i][j] = - (1000 * (x * y - 1) + 1);

    long long sum = 0;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            sum += ans[i][j] ? ans[i][j] : ans[i][j] = 1000;

    if (sum <= 0) return puts("No"), 0;

    puts("Yes");

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j)
            printf("%d ", ans[i][j]);
        puts("");
    }

    return 0;
}
