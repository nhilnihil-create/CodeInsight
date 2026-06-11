#include <bits/stdc++.h>

using namespace std;

//#define FILE_IO

typedef long long LL;

const LL INF = (1LL << 60);

int N;
LL v[100005];
bool f[100005][3];
LL mem[100005][3];

int gint()
{
    char ch = getchar();
    int sgn = 1;
    while(ch < '0' || '9' < ch)
    {
        if(ch == '-')   sgn = -1;
        ch = getchar();
    }
    int x = 0;
    while('0' <= ch && ch <= '9')
    {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    x *= sgn;
    return x;
}

LL solve(int pos, int grad)
{
    if(pos > N) return 0;
    if(grad < 0 || grad > 2)  return (-INF);
    if(f[pos][grad])    return  mem[pos][grad];

    f[pos][grad] = 1;
    LL val = v[pos];
    if(grad & 1)    val *= -1;

    LL slv1 = solve(pos + 1, grad - 2);
    LL slv2 = solve(pos + 1, grad - 1);
    LL slv3 = solve(pos + 1, grad);
    LL slv4 = solve(pos + 1, grad + 1);
    if(v[pos] > 0)  slv4 = -INF;

    LL ans = val + max( max(slv1, slv2), max(slv3, slv4) );
    mem[pos][grad] = ans;
    return ans;
}

int main()
{
    #ifdef FILE_IO
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    #endif

    N = gint();
    for(int i = 1; i <= N; i++)
        v[i] = gint();

    LL ans = solve(1, 0);
    printf("%lld\n", ans);

    return 0;
}
