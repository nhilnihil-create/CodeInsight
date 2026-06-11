#pragma GCC optimize("Ofast,inline,unroll-loops,fast-math")
#include <iostream>
#include <algorithm>
#include <cstdio>
#define N 2020
#define M 4000020
#define MOD 1000000007
using namespace std;
 
int Power(int, int);
 
namespace Comb
{
    int f[M], g[M];
 
    void InitComb(void)
    {
        int i;
 
        for(i = f[0] = 1; i < M; i ++)
            f[i] = (long long)f[i - 1] * i % MOD;
        g[M - 1] = Power(f[M - 1], MOD - 2);
        for(i = M - 2; i > -1; i --)
            g[i] = (long long)g[i + 1] * (i + 1) % MOD;
 
        return;
    }
 
    int C(int n, int m)
    {
        return m < 0 || m > n ? 0 : (long long)f[n] * g[n - m] % MOD * g[m] % MOD;
    }
}
 
int f[N][N];
 
inline int Mod(int x)
{
    return x + ((x >> 31) & MOD);
}
 
int Power(int x, int y)
{
    int o;
 
    for(o = 1; y; y >>= 1)
    {
        if(y & 1)
            o = (long long)o * x % MOD;
        x = (long long)x * x % MOD;
    }
 
    return o;
}
 
int main(void)
{
    int n, k;
    int i, j;
 
    Comb::InitComb();
    scanf("%d %d", &n, &k);
    if(k == 1)
    {
        printf("1\n");
 
        return 0;
    }

    f[0][0] = 1;
    for(i = 1; i <= n; i ++)
        for(j = 0; j <= i; j ++)
        {
            f[i][j] = f[i - 1][j];
            if(j)
                f[i][j] = Mod(f[i][j] + (long long)f[i][j - 1] * (n - j + 1) % MOD * Comb::C(n * k - i - (j - 1) * (k - 1) - 1, k - 2) % MOD - MOD);
        }
    printf("%d\n", f[n][n]);

    return 0;
}
