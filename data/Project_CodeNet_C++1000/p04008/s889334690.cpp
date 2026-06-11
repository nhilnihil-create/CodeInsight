#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
int n, k, ans, fa[N], dep[N];
int tot, lnk[N], nxt[N], son[N];
void add (int x, int y) {
    nxt[++tot] = lnk[x], lnk[x] = tot, son[tot] = y;
}
void dfs (int x) {
    dep[x] = 1;
    for (int j = lnk[x]; j; j = nxt[j]) {
        dfs(son[j]);
        dep[x] = max(dep[x], dep[son[j]] + 1);
    }
    if (dep[x] >= k && fa[x] != 1) ++ans, dep[x] = 0;
}
int main () {
    cin >> n >> k, ans = 0;
    for (int i = 1; i <= n; ++i) scanf("%d", &fa[i]);
    if (fa[1] != 1) fa[1] = 1, ans = 1;
    for (int i = 2; i <= n; ++i) add(fa[i], i);
    dfs(1);
    printf("%d\n", ans);
    return 0;
}