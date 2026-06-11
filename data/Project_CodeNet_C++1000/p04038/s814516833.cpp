// In The Name Of The Queen
#include<bits/stdc++.h>
using namespace std;
const int N = 2009, MXN = N * N, Mod = 1e9 + 7;
int n, k, dp[N][N], F[MXN], I[MXN];
inline int Power(int a, int b)
{
    int ret = 1;
    for (; b; b >>= 1, a = 1LL * a * a % Mod)
        if (b & 1) ret = 1LL * ret * a % Mod;
    return (ret);
}
inline void Add(int &a, int b)
{
    a += b;
    if (a >= Mod)
        a -= Mod;
}
inline int nCr(int n, int r)
{
    if (r < 0 || n < r)
        return 0;
    return (F[n] * 1LL * I[r] % Mod * I[n - r] % Mod);
}
int main()
{
    scanf("%d%d", &n, &k);
    if (k == 1)
        return !printf("1\n");
    for (int i = F[0] = 1; i < MXN; i ++)
        F[i] = 1LL * F[i - 1] * i % Mod;
    I[MXN - 1] = Power(F[MXN - 1], Mod - 2);
    for (int i = MXN - 2; ~ i; i --)
        I[i] = 1LL * I[i + 1] * (i + 1) % Mod;
    dp[0][0] = 1;
    for (int i = 0; i <= n; i ++)
        for (int j = 0; j <= i; j ++)
        {
            if (i < n)
                Add(dp[i + 1][j], dp[i][j]);
            if (j < i)
                Add(dp[i][j + 1], dp[i][j] * 1LL * nCr(n * k - j * (k - 1) - i - 1, k - 2) % Mod);
        }
    return !printf("%lld\n", dp[n][n] * 1LL * F[n] % Mod);
}