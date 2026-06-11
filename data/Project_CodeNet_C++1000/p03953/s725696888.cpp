#include <bits/stdc++.h>
using namespace std;
 
namespace TYC
{
    #define int ll
 
    typedef long long ll;
    const int N = 1e5 + 10;
 
    int n, m, x[N], a[N], ans[N];
    ll K;
 
    inline int read()
    {
        int x = 0, f = 0, ch = getchar();
        while (!isdigit(ch))
            f |= (ch == '-'), ch = getchar();
        while (isdigit(ch))
            x = x * 10 + ch - '0', ch = getchar();
        return f ? -x : x;
    }
 
    inline void calc(int *r, int *x, int *y)
    {
        static int tmp[N], fir[N], to[N];
        memcpy(fir, x, sizeof(int[n]));
        memcpy(to, y, sizeof(int[n]));
        for (int i = 1; i <= n; i++)
            tmp[i] = to[fir[i]];
        memcpy(r, tmp, sizeof(int[n]));
    }
 
    void work()
    {
        n = read();
        for (int i = 0; i < n; i++)
            x[i] = read();
        for (int i = 0; i < n; i++)
            a[i] = ans[i] = i;
        m = read();
        scanf("%lld", &K);
        for (int i = 0; i < m; i++)
        {
            int t = read();
            swap(a[t - 1], a[t]);
        }
        for (; K; K >>= 1, calc(a, a, a))
            if (K & 1)
                calc(ans, a, ans);
        for (int i = 0; i < n; i++)
            a[i] = x[ans[i]] - x[ans[i] - 1];
        for (int i = 0; i < n; ++i, a[i] += a[i - 1])
            printf("%lld.0\n", a[i]);
    }
 
    #undef int
}
 
int main()
{
    TYC::work();
    return 0;
}