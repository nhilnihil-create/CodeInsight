#include <bits/stdc++.h>
using namespace std;
const int N=100050;
int n;
struct edge
{
    int v,nxt;
}e[N<<1];
int head[N],etot;
int dis;
int p[N],siz[N];
int X,Y;
inline void ad(int u,int v)
{
    e[++etot].v=v;e[etot].nxt=head[u];head[u]=etot;
}
bool flag=false;
void dfs(int u,int fa,int dep)
{
    if(flag)return;
    for(int i=head[u];i;i=e[i].nxt)
    {
        int v=e[i].v;
        if(v==fa)continue;
        p[v]=u;
        if(v!=n)dfs(v,u,dep+1);
        else
        {
            dis=dep;flag=true;
            return;
        }
    }
}
void dfs2(int u,int fa)
{
    siz[u]=1;
    for(int i=head[u];i;i=e[i].nxt)
    {
        int v=e[i].v;
        if(v==fa)continue;
        dfs2(v,u);
        siz[u]+=siz[v];
    }
}

int main()
{
    scanf("%d",&n);
    for(int i=1;i<n;++i)
    {
        int x,y;scanf("%d%d",&x,&y);
        ad(x,y),ad(y,x);
    }
    dfs(1,0,0);
    int hal=dis/2;
    int P=n;
    for(int it=1;it<=hal;it++)
    {
        P=p[P];
    }
    Y=P;X=p[P];
    dfs2(X,Y);
    dfs2(Y,X);
    if(dis&1)
    {
        if(siz[Y]>siz[X])puts("Snuke");
        else puts("Fennec");
    }
    else
    {
        if(siz[Y]>=siz[X])puts("Snuke");
        else puts("Fennec");
    }
    return 0;
}