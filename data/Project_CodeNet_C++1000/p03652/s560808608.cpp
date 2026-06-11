#include <bits/stdc++.h>
using namespace std;

const int maxn = 310;
int n, m, cnt[maxn], a[maxn][maxn];

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    function<int(int, int)> solve = [&](int n, int m) {
        if (!m) return INT_MAX;
        memset(cnt, 0, sizeof(cnt));
        for (int i = 1; i <= n; i++) {
            cnt[a[i][1]]++;
        }
        int mx = 1;
        for (int i = 1; i <= 300; i++) {
            if (cnt[i] > cnt[mx]) mx = i;
        }
        int tmp = cnt[mx];
        for (int i = 1; i <= n; i++) {
            for (int j = 1, k = 0; j <= m; j++) {
                if (mx == a[i][j]) continue;
                a[i][++k] = a[i][j];
            }
        }
        return min(tmp, solve(n, m - 1));
    };
    printf("%d\n", solve(n, m));
    return 0;
}