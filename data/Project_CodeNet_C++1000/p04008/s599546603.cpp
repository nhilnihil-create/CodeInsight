#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=2e5+500;
int fa[N],K,n,ans;
int fst[N],nxt[N],to[N],mm,f[N];
void ade(int u,int v){to[++mm]=v,nxt[mm]=fst[u],fst[u]=mm;}
void dfs(int u)
{
    f[u]=-1;
    for(int i=fst[u];i;i=nxt[i])
    {
        int v=to[i];dfs(v);f[u]=max(f[u],f[v]);
    }
    ++f[u];if(f[u]==K-1&&fa[u]!=1)++ans,f[u]=-1;
}
int main()
{
    scanf("%d%d",&n,&K);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",fa+i);
        if(i!=1)ade(fa[i],i);
    }
    if(fa[1]!=1)++ans;
    for(int i=fst[1];i;i=nxt[i])dfs(to[i]);cout<<ans<<endl;
}