#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define maxn 100010
using namespace std;
typedef long long ll;
int read()
{
    int x=0,f=1;
    char ch=getchar();
    while(ch-'0'<0||ch-'0'>9){if(ch=='-') f=-1;ch=getchar();}
    while(ch-'0'>=0&&ch-'0'<=9){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int n;
int a[maxn];
int head[maxn],nxt[maxn*2],to[maxn*2],tot;
void add(int u,int v)
{
    tot++;
    nxt[tot]=head[u];
    head[u]=tot;
    to[tot]=v;
}
int deg[maxn],rt;
ll solve(int x,int las)
{
    if(deg[x]==1)  return a[x];
    int rem=2*a[x];
    for(int i=head[x];i;i=nxt[i])
    {
        if(to[i]==las)  continue;
        ll tmp=solve(to[i],x);
        if(tmp>a[x])
        {
            puts("NO");
            exit(0);
        }
        rem-=tmp;
    }
    if(rem<0||rem>a[x])
    {
        puts("NO");
        exit(0);
    }
    return rem;
}
int main()
{
    n=read();
    for(int i=1;i<=n;i++)  a[i]=read();
    for(int i=1;i<n;i++)
    {
        int q=read(),w=read();
        add(q,w);
        add(w,q);
        deg[w]++;deg[q]++;
    }
    if(n==2)
    {
        if(a[1]!=a[2])  puts("NO");
        else            puts("YES");
        return 0;
    }
    for(int i=1;i<=n;i++)
    {
        if(deg[i]>1)
        {
            rt=i;
            break;
        }
    }
    if(solve(rt,0))  puts("NO");
    else             puts("YES");
    return 0;
}