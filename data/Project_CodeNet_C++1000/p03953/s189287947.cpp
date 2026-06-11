#include <bits/stdc++.h>
using namespace std;
const int N = 100000 + 10;
int n, m, u, x[N], nxt[N], vis[N], d[N];
long long k, a[N], p[N];
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &x[i]);
        a[i] = x[i] - x[i - 1];
        nxt[i] = i;
    }
    scanf("%d%lld", &m, &k); 
    for (int i = 1; i <= m; i++) {
        scanf("%d", &u);
        swap(nxt[u], nxt[u + 1]);
    }
    for (int i = 1; i <= n; i++) {
        if (vis[i]) continue;
        int cnt = 0;
        for (int j = i; !vis[j]; j = nxt[j]) {
            vis[j] = 1;
            d[++cnt] = j;
        }
        for (int j = 1; j <= cnt; j++) p[d[j]] = a[d[(j + k - 1) % cnt + 1]];
    }
    for (int i = 1; i <= n; i++) {
        p[i] += p[i - 1];
        printf("%lld.0\n", p[i]);
    }
    return 0;
}