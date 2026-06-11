#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

struct jie
{
    int x,t,c;
}mp[500005];
struct jie1
{
    int v,d,c;
}a[500005];
int d[500005],us[500005],head[500005],cnt,n,c[500005],f[500005][12];
void add(int x,int y,int c)
{
    cnt++;
    mp[cnt].x=y;
    mp[cnt].c=c;
    mp[cnt].t=head[x];
    head[x]=cnt;
}
void dfs(int u,int d,int l,int co)
{
    if(d>l||f[u][l-d]==1) return ;
    for(int j=0;j<=l-d;j++)
    {
        f[u][j]=1;
    }
    if(c[u]==0)
    {
        c[u]=co;
    }
    int i;
    for(i=head[u];i!=-1;i=mp[i].t)
    {
        int v=mp[i].x;
        dfs(v,d+1,l,co);
    }
    return ;
}
int main()
{
    int m,i;
    cnt=1;
    memset(head,-1,sizeof(head));
    scanf("%d %d",&n,&m);
    for(i=1;i<=m;i++)
    {
        int u,v;
        scanf("%d %d",&u,&v);
        add(u,v,1);
        add(v,u,1);
    }
    int T;
    scanf("%d",&T);
    for(i=1;i<=T;i++)
    {
        scanf("%d %d %d",&a[i].v,&a[i].d,&a[i].c);
    }
    for(i=T;i>=1;i--)
    {
        dfs(a[i].v,0,a[i].d,a[i].c);
    }
    for(i=1;i<=n;i++)
    {
        printf("%d\n",c[i]);
    }
    return 0;
}
