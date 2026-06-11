#include<bits/stdc++.h>
using namespace std;

const int S=(1<<20)+5;
char buf[S],*H,*T;
inline char Get()
{
    if(H==T) T=(H=buf)+fread(buf,1,S,stdin);
    if(H==T) return -1;return *H++;
}
inline int read()
{
    int x=0;char c=Get();
    while(!isdigit(c)) c=Get();
    while(isdigit(c)) x=x*10+c-'0',c=Get();
    return x;
}

const int N=100010;
struct Edge{int to,next;} e[N<<1];
int h[N],n,K,sum=0;
int fa[N],deg[N],dep[N];
int c[N],id[N];
bool done[N];

void add_edge(int u,int v)
{
    e[++sum].to=v;
    e[sum].next=h[u];
    h[u]=sum;
}

void dfs(int u)
{
    if(done[u]) return;
    for(int t=h[u];t;t=e[t].next)
    {
        dep[e[t].to]=dep[u]+1;
        dfs(e[t].to);
    }
}

int main()
{
    n=read();K=read();
    for(int i=1;i<=n;i++) fa[i]=read();
    for(int i=2;i<=n;i++)
    {
        add_edge(fa[i],i);//反向建图
        deg[fa[i]]++;
    }
    dfs(1);
    for(int i=1;i<=n;i++) c[dep[i]]++;
    for(int i=1;i<=n;i++) c[i]+=c[i-1];
    for(int i=1;i<=n;i++) id[c[dep[i]]--]=i;//三行桶排
    reverse(id+1,id+1+n);//上面排序是按深度从小到大的，现在要反转过来
    int ans=(fa[1]!=1);//如果fa[1]一开始不等于1，就要修改一次，让它等于1
    for(int i=1;i<=n;i++)
    {
        int x=id[i];
        if(deg[x]==0&&dep[x]>K)
        {
            int u=x;
            for(int j=1;j<K;j++) u=fa[u];
            ans++;dep[u]=1;dfs(u);
            deg[fa[u]]--;
            done[u]=1;//特别注意必须要有done标记
        }
    }
    printf("%d\n",ans);
    return 0;
}