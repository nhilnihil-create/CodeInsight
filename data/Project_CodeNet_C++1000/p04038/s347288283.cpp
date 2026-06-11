#include<bits/stdc++.h>
#define int long long

const int N = 2e3, M = N * N;
const int Mo = 1e9 + 7;

int n, m;
int f[N + 10][N + 10], fac[M + 10], Inv[M + 10];

inline int ksm(int a, int b) {
    int ans = 1;
    for (; b; b >>= 1, a = 1LL * a * a % Mo)
        if (b & 1) ans = 1LL * ans * a % Mo;
    return ans;
}

inline int C(int n, int m) {
    if (m < n)
        return 0;
    // printf("%d %d %d %d\n", n, fac[m], Inv[n], Inv[m - n]);
    return 1LL * fac[m] * Inv[n] % Mo * Inv[m - n] % Mo;
}

signed main() {
    scanf("%lld%lld", &n, &m);
    if (m == 1) {
        printf("1\n");
        return 0;
    }
    fac[0] = fac[1] = 1;
    for (int i = 2; i <= M; i++)
        fac[i] = (1LL * fac[i - 1] * i) % Mo;
    Inv[M] = ksm(fac[M], Mo - 2);
    // for (int i = 1; i <= n; i++)
    //     printf("%d ", fac[i]);
    for (int i = M - 1; i >= 0; i--)
        Inv[i] = 1LL * Inv[i + 1] * (i + 1) % Mo;

    // for (int i = 1; i <= n; i++)
    //     printf("%d ", Inv[i]);
    f[0][0] = 1;
    for (int i = 1; i <= n; i++)
        for (int  j= 0; j <= i; j++) {
            if (j == 0)
                f[i][j] = f[i - 1][j];
            else {
                f[i][j] = (f[i - 1][j] + 1LL * f[i][j - 1] * (n - j + 1) % Mo * 1LL * (C(m - 2, n - i + (n - j + 1) * (m - 1) - 1)) % Mo) % Mo;
                // printf("%d %d\n", C(m - 2, n - i + (n - j + 1) * (m - 1) - 1), n - i + (n - j + 1) * (m - 1) - 1);
            }
        }
    printf("%lld\n", f[n][n]);
    return 0;
}
