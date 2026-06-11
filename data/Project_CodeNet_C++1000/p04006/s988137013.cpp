#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N 2001
int f[N][N], n;
ll ans = 1e18, x;
int query(int l, int r) { return l > 0 ? f[l][r] : min(f[l + n][n], f[1][r]); }
int main() {
    scanf("%d%lld", &n, &x);
    for (int i = 1; i <= n; i++) scanf("%d", &f[i][i]);
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++) f[i][j] = min(f[i][j - 1], f[j][j]);
    for (int i = 0; i < n; i++) {
        ll sum = 0;
        for (int j = 1; j <= n; j++) sum += query(j - i, j);
        ans = min(ans, sum + x * i);
    }
    printf("%lld\n", ans);
}