#include <bits/stdc++.h>
using namespace std;
#define N 100001
vector<int> e[N];
int n, k, ans;
int dfs(int u) {
    int l = 1, d;
    for (int v : e[u])
        if ((d = dfs(v)) == k)
            ans++;
        else
            l = max(d + 1, l);
    return l;
}
int main() {
    scanf("%d%d", &n, &k);
    for (int i = 1, x; i <= n; i++) {
        scanf("%d", &x);
        if (i > 1)
            e[x].push_back(i);
        else
            ans += x != 1;
    }
    for (auto v : e[1]) dfs(v);
    printf("%d\n", ans);
    return 0;
}