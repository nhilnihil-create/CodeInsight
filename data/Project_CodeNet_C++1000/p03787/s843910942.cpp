#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define maxn 100010
#define maxm 200010
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
int n,m;
int head[maxn],nxt[maxm*2],to[maxm*2],tot;
void add(int u,int v)
{
    tot++;
    nxt[tot]=head[u];
    head[u]=tot;
    to[tot]=v;
}
ll A,B,C;
int fa[maxn],vis[maxn],flag;
int dis[maxn];
int find(int x)
{
    if(fa[x]==x)  return x;
    int tmp=fa[x],f=find(fa[x]);
    dis[x]^=dis[tmp];
    return fa[x]=f;
}
void work(int x,int y)
{
    int u=find(x),v=find(y);
    if(u==v)
    {
        if(dis[x]==dis[y])  flag=1;
        return;
    }
    dis[u]=(dis[x]^dis[y]^1);
    fa[u]=v;
}
int cnt;
void dfs(int x)
{
    cnt++;vis[x]=1;
    for(int i=head[x];i;i=nxt[i])
    {
        work(x,to[i]);
        if(vis[to[i]])  continue;
        dfs(to[i]);
    }
}
int main()
{
    n=read();m=read();
    for(int i=1;i<=m;i++)
    {
        int q=read(),w=read();
        add(q,w);
        add(w,q);
    }
    for(int i=1;i<=n;i++)  fa[i]=i;
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            cnt=0;
            flag=0;
            dfs(i);
            if(cnt==1)      C++;
            else if(!flag)  A++;
            else            B++;
        }
    }
    ll ans=0;
    ans+=C*n+C*(n-C);
    ans+=B*B;
    ans+=A*A*2;
    ans+=A*B*2;
    cout<<ans<<endl;
    return 0;
}