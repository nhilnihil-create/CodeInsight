#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int n,m,num[4],nei[400005],cnt,vis[800004],shu[800004];
int tot=1,fir[400005],to[800005],nxt[800005];
void add(int u,int v)
{
    nxt[++tot]=fir[u],fir[u]=tot,to[tot]=v;
}
void dfs(int u,int e,int&op,int&jsq,int dis)
{
    if(vis[u])return op=max(op,(dis-vis[u])&1),void();
    vis[u]=dis,++jsq;
    for(int i=fir[u];i;i=nxt[i])
        if(i/2!=e)dfs(to[i],i/2,op,jsq,dis+1);
}
int main()
{
    cin>>n>>m;
    for(int i=1,u,v;i<=m;++i)
        scanf("%d%d",&u,&v),add(u,v),add(v,u);
    for(int i=1;i<=n;++i)
    {
        if(vis[i])continue;
        int op=0,jsq=0;
        dfs(i,0,op,jsq,1);
        if(jsq==1)op=2;
        ++num[op];
        nei[++cnt]=op;
        shu[cnt]=jsq;
    }
    long long ans=0;
    for(int i=1;i<=cnt;++i){
        if(nei[i]==1)ans+=num[0]+num[1],ans+=num[2]*shu[i];
        else if(nei[i]==0)ans+=2*num[0]+num[1],ans+=num[2]*shu[i];
        else ans+=n;
    }
    cout<<ans<<endl;
    return 0;
}
