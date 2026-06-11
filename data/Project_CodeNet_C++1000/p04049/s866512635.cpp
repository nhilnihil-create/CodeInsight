#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N 2010
#define M 4010
int hd[N], nx[M], e[M];
int n, k, ans = -1;
int dfs(int x, int fa, int dep) {
    int num = dep > k / 2;
    for (int i = hd[x]; i; i = nx[i])
        if (e[i] != fa) num += dfs(e[i], x, dep + 1);
    return num;
}
int main() {
    scanf("%d%d", &n, &k);
    for (int i = 1, Num = 0, x, y; i < n; i++) {
        scanf("%d%d", &x, &y);
        nx[++Num] = hd[x], hd[x] = Num, e[Num] = y;
        nx[++Num] = hd[y], hd[y] = Num, e[Num] = x;
    }
    if (k & 1) {
        for (int i = 1; i <= n; i++)
            for (int j = hd[i]; j; j = nx[j]) {
                int x = dfs(i, e[j], 0) + dfs(e[j], i, 0);
                if (ans == -1 || ans > x) ans = x;
            }
    } else
        for (int i = 1; i <= n; i++) {
            int x = dfs(i, 0, 0);
            if (ans == -1 || ans > x) ans = x;
        }
    printf("%d\n", ans);
    return 0;
}