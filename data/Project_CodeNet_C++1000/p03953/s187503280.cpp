#include <bits/stdc++.h>
using namespace std;
int read();
int n, m;
long long x[200005], k;
int a[200005], nx[200005];
int res[200005], vis[200005], st[200005], top;
int main() {
    n = read();
    for (int i = 1; i <= n; ++i) x[i] = read(), nx[i] = i;
    for (int i = n; i >= 1; --i) x[i] -= x[i - 1];
    m = read(), scanf("%lld", &k);
    for (int i = 1; i <= m; ++i) a[i] = read();
    for (int j = 1; j <= m; ++j) swap(nx[a[j]], nx[a[j] + 1]);

    for (int i = 1, j; i <= n; ++i) {
        if (vis[i]) continue;
        st[top = vis[i] = 1] = i, j = nx[i];
        while (j != i) st[++top] = j, j = nx[j], vis[j] = 1;
        for (j = 1; j <= top; ++j) res[st[j]] = st[(j + k - 1) % top + 1];
    }
    long long t = 0;
    for (int i = 1; i <= n; ++i) t += x[res[i]], printf("%lld.0\n", t);
    return 0;
}

int read() {
    int x = 0, f = 1;
    char c = getchar();
    while (c < '0' || c > '9') f = (c == '-') ? -1 : f, c = getchar();
    while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
    return x * f;
}