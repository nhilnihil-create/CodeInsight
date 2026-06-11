// Crt. 2019-12-02  22:18:17
#include <algorithm>
#include <iostream>
#include <cstdio>
#define N 302
using namespace std;

int n, m, a[N][N], num[N], ban[N], pos[N];

int main() {
#ifdef LOCAL_JUDGE
    freopen("work.in", "r", stdin);
    freopen("work.out", "w", stdout);
#endif

    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j)
            scanf("%d", a[i] + j);
        ++num[a[i][1]], pos[i] = 1;
    }

    int ans = n;
    for (int i = 1; i <= m; ++i) {
        int x = 0;
        for (int j = 1; j <= m; ++j)
            if (num[j] > num[x]) x = j;
        ans = min(ans, num[x]);
        ban[x] = 1;
        for (int j = 1; j <= m; ++j) num[j] = 0;
        for (int j = 1; j <= n; ++j) {
            while (ban[a[j][pos[j]]]) ++pos[j];
            ++num[a[j][pos[j]]];
        }
    }

    cout << ans << endl;

    return 0;
}
