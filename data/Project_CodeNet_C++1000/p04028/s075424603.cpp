#include <bits/stdc++.h>
const int maxn = 5007, mod = int(1e9) + 7;
typedef long long ll;
char str[maxn];
int ans[maxn][maxn], len, n;
ll power_mod(ll p, int q) {
    ll ret = 1;
    while (q) {
        if (q & 1) ret = ret * p % mod;
        p = p * p % mod;
        q >>= 1;
    }
    return ret;
}
int max(int a, int b) { return a > b ? a : b; }
void init() {
    len = int(strlen(str)), ans[0][0] = 1;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= i; j++) {
            ans[i + 1][j + 1] = int((1ll * ans[i][j] * 2 % mod + ans[i + 1][j + 1]) % mod);
            ans[i + 1][max(j - 1, 0)] = int((0ll + ans[i][j] + ans[i + 1][max(j - 1, 0)]) % mod);
        }
    }
}

int main() {
    scanf("%d%s", &n, str);
    init();
    printf("%d\n", int(power_mod(power_mod(2, len), mod - 2) * ans[n][len] % mod));
    return 0;
}