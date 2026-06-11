#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
const int MM = 200000;
LL fac[MM + 10],rev[MM + 10];
LL H,W,A,B;
const int MOD = 1e9 + 7;


LL quick_pow(LL a,LL x)
{
    LL ret = 1;
    while(x)
    {
        if (x & 1) ret = ret * a % MOD;
        x >>= 1;
        a = a * a % MOD;
    }
    return ret;
}

LL rv(LL x)
{
    return quick_pow(x, MOD - 2);
}

LL C(LL N,LL M)
{
    return fac[N] * rev[M] % MOD * rev[N - M] % MOD;
}

int main()
{
    fac[0] = 1;
    for (int i=1;i<=MM;i++)fac[i] = 1LL * fac[i-1] * i % MOD;
    rev[MM] = rv(fac[MM]);
    for (int i=MM - 1;i >= 0;i--)rev[i] = 1LL * rev[i + 1] * (i + 1) % MOD;
    scanf("%lld%lld%lld%lld",&H,&W,&A,&B);
    LL ans = C(H + W - 2, H - 1);
    //printf("%lld\n",ans);
    for (LL i=1;i<=B;i++) ans -= C(H - A - 1 + i - 1, i - 1) * C(W - i + A - 1, A - 1) % MOD;
    ans %= MOD;
    if (ans < 0) ans += MOD;
    printf("%lld\n",ans);
}
