#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define LL long long
#define int LL
#define P pair<int, int>
const LL N = 2e3 + 10;
const LL mod = 1e9 + 7;
const LL inf = 0x3f3f3f3f;
using namespace std;
template <typename tp>
inline void read(tp &x)
{
    x = 0;char c = getchar();bool f = 0;
    for (; c < '0' || c > '9'; f |= (c == '-'), c = getchar());
    for (; c >= '0' && c <= '9'; x = (x << 3) + (x << 1) + c - '0', c = getchar());
    if (f) x = -x;
}
int n, k, f[N][N], fac[N * N + N * 2], inv[N * N + N * 2];
void updata(int &x, int y) { x += y, x -= x >= mod ? mod : 0; }
int C(int n, int m) { return fac[n] * inv[m] % mod * inv[n - m] % mod; }
signed main()
{
    read(n),read(k); k--;
    if (!k) return 0*puts("1");
    fac[0] = fac[1] = inv[0] = inv[1] = 1;
    for (int i = 2; i <= n * k + n + k; i++) fac[i] = (LL)fac[i - 1] * i % mod, inv[i] = (LL)(mod - mod / i) * inv[mod % i] % mod;
    for (int i = 2; i <= n * k + n + k; i++) inv[i] = (LL)inv[i - 1] * inv[i] % mod;
    f[0][0] = 1;
    for (int i = 0; i <= n; i++)
        for (int j = i; j <= n; j++)
        {
            if (i) updata(f[i][j], f[i - 1][j]);
            if (j) updata(f[i][j], (LL)f[i][j - 1] * C(i + (j - 1) * k + k - 1, k - 1) % mod);
        }
    printf("%lld\n", f[n][n] * fac[n] % mod);
    return 0;
}