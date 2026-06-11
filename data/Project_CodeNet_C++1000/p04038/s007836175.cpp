#include <iostream>
#include <cstdio>
#include <algorithm>

template <typename Tp>
inline void read(Tp &x) {
    x = 0;
    bool f = true; char ch = getchar();
    for ( ; ch < '0' || ch > '9'; ch = getchar()) f ^= ch == '-';
    for ( ; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + (ch ^ 48);
    x = f ? x : -x;
}

const int N = 2e3 + 7, M = 4e6 + 7, P = 1e9 + 7;

int Dp[N][N], Fac[M], iFac[M];

inline int Power(int a, int x) {
    int res = 1;
    while (x) {
        if (x & 1) res = 1LL * res * a % P;
        a = 1LL * a * a % P;
        x >>= 1;
    }
    return res;
}

inline int Inv(int x) {
    return Power(x, P - 2);
}

inline int C(int n, int m) {
    if (m > n || m < 0) return 0;
    return 1LL * Fac[n] * iFac[n - m] % P * iFac[m] % P;
}

int main() {
    Fac[0] = 1;
    for (int i = 1; i < M; ++i) Fac[i] = 1LL * Fac[i - 1] * i % P;
    iFac[M - 1] = Inv(Fac[M - 1]);
    for (int i = M - 2; i >= 0; --i) iFac[i] = 1LL * iFac[i + 1] * (i + 1) % P;
    int n, k;
    read(n), read(k);
    if (k == 1) return printf("1\n"), 0;
    for (int i = 0; i <= n; ++i) Dp[i][0] = 1;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= i; ++j) Dp[i][j] = (Dp[i - 1][j] + 1LL * Dp[i][j - 1] * (n - j + 1) % P * C(n * k - i - (j - 1) * (k - 1) - 1, k - 2) % P) % P;
    printf("%d\n", Dp[n][n]);
    return 0;
}