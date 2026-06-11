#pragma GCC optimize(3)
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<list>
#include<queue>
#include<stack>
#include<bitset>
#include<deque>
using namespace std;
#define ll long long
// #define inf 0x3f3f3f3f
#define ri register int
#define il inline
#define fi first
#define se second
#define mp make_pair
#define pi pair<int,int>
#define mem0(x) memset((x),0,sizeof (x))
#define mem1(x) memset((x),0x3f,sizeof (x))
il char gc()
{
    static const int BS = 1 << 22;
    static unsigned char buf[BS], *st, *ed;
    if (st == ed) ed = buf + fread(st = buf, 1, BS, stdin);
    return st == ed ? EOF : *st++;
}
#define gc getchar
template<class T>void in(T &x)
{
    x = 0;
    bool f = 0;
    char c = gc();
    while (c < '0' || c > '9')
    {
        if (c == '-') f = 1;
        c = gc();
    }
    while ('0' <= c && c <= '9')
    {
        x = (x << 3) + (x << 1) + (c ^ 48);
        c = gc();
    }
    if (f) x = -x;
}
#undef gc
#define pb push_back
int al[4] = {'R', 'G', 'Y', 'B'};
signed main()
{
#ifndef ONLINE_JUDGE
    //freopen("in.in", "r", stdin);
#endif
    int n, m, d;
    in(n), in(m), in(d);
    for (ri i = 1; i <= n; ++i)
    {
        for (ri j = 1; j <= m; ++j)
            printf("%c", al[(i + j + 500) / d % 2 * 2 + (i - j + 500) / d % 2]);
        puts("");
    }
    return 0;
}