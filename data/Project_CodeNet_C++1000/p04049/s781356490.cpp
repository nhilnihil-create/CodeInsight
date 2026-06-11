#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=1e5;
int n,K,fst[N],nxt[N],to[N],dep[N],ans,cnt,mm;
void ade(int u,int v){to[++mm]=v,nxt[mm]=fst[u],fst[u]=mm;}
void dfs(int u,int fa,int lim)
{
    dep[u]=dep[fa]+1;++cnt;if(lim==dep[u])return;
    for(int i=fst[u];i;i=nxt[i])
    {
        int v=to[i];if(v==fa)continue;
        dfs(v,u,lim);
    }
}
int main()
{
    scanf("%d%d",&n,&K);
    for(int i=1,u,v;i<n;i++)scanf("%d%d",&u,&v),ade(u,v),ade(v,u);
    if(~K&1)for(int i=1;i<=n;i++)cnt=0,dfs(i,0,(K>>1)+1),ans=max(ans,cnt);
    else for(int i=1;i<=n;i++)for(int j=fst[i];j;j=nxt[j])cnt=0,dep[to[j]]=0,dfs(i,to[j],(K>>1)+1),dep[i]=0,dfs(to[j],i,(K>>1)+1),ans=max(ans,cnt);
    cout<<n-ans<<endl;
}