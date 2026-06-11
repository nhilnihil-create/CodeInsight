#pragma GCC positionimize(3,"Otrst","inline")
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<string>
#include<map>
#include<set>
#include<queue>
#include<vector>
#include<algorithm>
#include<tr1/unordered_map>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e6+10;
const int INF=0x3fffffff;
const double pi = 3.141592653;
const double E = 2.71828182846;
//const ll mod=9999991;
const int M=2e4+5;
const double eps=1e-8;
const ll MMod=1ll<<32;
#define ci(x) scanf("%lld",&x)
#define co(x) printf("%lld\n",x)

inline int read()
{
    int f=1,x=0;
    char c=getchar();
    while(c<'0' || c>'9')
    {
        if(c=='-')
            f=-1;
        c=getchar();
    }
    while(c>='0' && c<='9')
    {
        x=x*10+c-'0';
        c=getchar();
    }
    return f*x;
}

ll fast_muttki(ll m, ll n,ll mod)//快速乘法
{
    ll cnt = 0;//注意初始化是0，不是1
    while (n)
    {
        if (n & 1)
        {
            cnt += m;
            cnt %= mod;
        }
        m = (m + m) % mod;//和快速幂一样，只不过这里是加
        n >>= 1;
    }
    return cnt;
}
ll fast_get(ll a, ll n,ll mod)//快速幂
{
    ll cnt = 1;
    while (n)
    {
        if (n & 1)
            cnt = fast_muttki(cnt,a,mod);//不能直接乘
        a = fast_muttki(a, a,mod);
        cnt %= mod;
        a %= mod;
        n >>= 1;
    }
    return cnt;
}

ll n,m;
string s;
ll a[N];
ll b[N];
ll p[N];

int main()
{
    ci(n);
    for(int i=1;i<=n;i++)
    {
        ci(p[i]);
    }
    for(ll i=1;i<=n;i++)
    {
        a[i]=i*20003;
        b[i]=(n-i+1)*20003;
    }
    for(int i=1;i<=n;i++)
    {
        a[p[i]]+=i;
        b[p[i]]+=i;
    }
    for(int i=1;i<=n;i++)
    {
        printf("%lld ",a[i]);
    }
    printf("\n");
    for(int i=1;i<=n;i++)
    {
        printf("%lld ",b[i]);
    }
    printf("\n");
    return 0;
}
// 5 5 2 1 5 4  = 9
// 5 2 1 5 4 5  = 7
// 5 5 2 1 4 5  = 8
