#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long LL;
LL mod = 1e9 + 7;
LL f[200005];
LL qpow(LL x, LL n)
{
    LL res = 1, p = x;
    while(n)
    {
        if(n & 1)
            res = res*p%mod;
        p = p*p%mod;
        n >>= 1;
    }
    return res;
}

LL C(LL x, LL y)
{
    LL a = f[x], b = f[y]*f[x-y]%mod;
    return a*qpow(b, mod - 2)%mod;
}
int main()
{
    f[0] = 1;
    for(int i = 1; i < 2e5+5; i++)
        f[i] = f[i-1]*i%mod;
    LL h, w, a, b;
    while(~scanf("%lld%lld%lld%lld", &h, &w, &a, &b))
    {
        LL ans = 0;
        for(LL i = b + 1; i <= w; i++)
        {
            ans = (ans + C(i + h - a - 2, h - a - 1)*C(w + a - i - 1, w - i)%mod)%mod;
        }
        printf("%lld\n", ans);
    }
    return 0;
}
