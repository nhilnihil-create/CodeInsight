//xtwakioi! xtwddYnoi(双重含义)!
#include <bits/stdc++.h>
#define ri register
#define int long long
#define E (n+1)
using namespace std; const int N=200010;
inline int read()
{
    int s=0, w=1; ri char ch=getchar();
    while(ch<'0'||ch>'9') { if(ch=='-') w=-1; ch=getchar(); }
    while(ch>='0'&&ch<='9') s=(s<<3)+(s<<1)+(ch^48), ch=getchar();
    return s*w;
}
int n,m,dis[N],book[N];
int head[N],maxE;
struct Edge { int nxt,to,rdis; }e[N<<1];
inline void Add(int u,int v,int w) { e[++maxE].nxt=head[u]; head[u]=maxE; e[maxE].to=v; e[maxE].rdis=w; }
signed main()
{
    n=read(), m=read();
    for(ri int i=1;i<=m;i++)
    {
        int u,v,w;
        u=read(), v=read(), w=read();
        Add(u,v,-w);
    }
    queue<int> Q;
    for(ri int i=1;i<=n;i++) dis[i]=1e18;
    dis[1]=0;
    for(ri int k=1;k<n;k++)
    {
        for(ri int i=1;i<=n;i++)
        {
            for(ri int j=head[i];j;j=e[j].nxt)
            {
                int v=e[j].to;
                if(dis[i]==1e18) continue;
                if(dis[v]>dis[i]+e[j].rdis)
                dis[v]=dis[i]+e[j].rdis;
            }
        }
    }

    for(ri int k=1;k<=n;k++)
    for(ri int i=1;i<=n;i++)
    {
        for(ri int j=head[i];j;j=e[j].nxt)
        {
            int v=e[j].to;
            if(dis[i]==1e18) continue;
            if(dis[v]>dis[i]+e[j].rdis)
            {
                dis[v]=dis[i]+e[j].rdis;
                book[v]=1;
            }
            if(book[i]) book[v]=1;
        }
    }

    if(book[n]) { puts("inf"); }
    else printf("%lld\n",-dis[n]);

    return 0;
}