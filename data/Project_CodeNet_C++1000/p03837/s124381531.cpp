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
int n,m,dis[210][210];
struct Node
{
    int u,v,w;
}e[N];
signed main()
{
    memset(dis,0x3f,sizeof(dis));
    n=read(), m=read();
    for(ri int i=1;i<=n;i++) dis[i][i]=0;
    for(ri int i=1;i<=m;i++)
    {
        e[i].u=read(), e[i].v=read(), e[i].w=read();
        dis[e[i].u][e[i].v]=dis[e[i].v][e[i].u]=e[i].w;
    }
    for(ri int k=1;k<=n;k++)
    for(ri int i=1;i<=n;i++)
    for(ri int j=1;j<=n;j++)
    dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);

    int res=0;
    for(ri int i=1;i<=m;i++)
    {
        int qwq=0;
        for(ri int j=1;j<=n;j++)
        {
            if(dis[j][e[i].u]+e[i].w==dis[j][e[i].v])
            {
                qwq=1;
                break;
            }
        }
        res+=qwq;
    }
    printf("%lld\n",m-res);
    return 0;
}