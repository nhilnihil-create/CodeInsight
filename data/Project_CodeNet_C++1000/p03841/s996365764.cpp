// Crt. 2019-12-02  21:00:55
#include <algorithm>
#include <iostream>
#include <cstdio>
#define N 502
using namespace std;

int n, x[N], ans[N * N], pos[N];

bool cmp(int a, int b) {
    return x[a] < x[b];
}

int main() {
#ifdef LOCAL_JUDGE
    freopen("work.in", "r", stdin);
    freopen("work.out", "w", stdout);
#endif

    cin >> n;
    for (int i = 1; i <= n; ++i) {
        scanf("%d", x + i);
        if (x[i] > n * n) return puts("No"), 0;
        pos[i] = i, ans[x[i]] = i;
    }

    sort(pos + 1, pos + n + 1, cmp);

    int nowpos = 1;
    for (int i = 1; i <= n; ++i) {
        int now = pos[i];
        for (int j = 1; j < now; ++j) {
            while (ans[nowpos]) ++nowpos;
            if (nowpos > x[now]) return puts("No"), 0;
            ans[nowpos] = now;
        }
    }

    for (int i = 1; i <= n; ++i) {
        int now = pos[i];
        for (int j = 1; j <= n - now; ++j) {
            while (ans[nowpos]) ++nowpos;
            if (nowpos < x[now]) return puts("No"), 0;
            ans[nowpos] = now;
        }
    }

    puts("Yes");
    for (int i = 1; i <= n * n; ++i)
        printf("%d ", ans[i]);

    return 0;
}
