#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2005;
struct node{
    int u,v,nxt;
}edge[N*2];
int head[N],mcnt;
void add_edge(int u,int v){
    mcnt++;
    edge[mcnt].u=u;
    edge[mcnt].v=v;
    edge[mcnt].nxt=head[u];
    head[u]=mcnt;
}
int n,k;
int du[N];
int deep[N];
void dfs(int u,int fa,int d){
    deep[u]=d;
    for(int i=head[u];i;i=edge[i].nxt){
        int v=edge[i].v;
        if(v==fa)
            continue;
        dfs(v,u,d+1);
    }
}
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<n;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        add_edge(u,v);
        add_edge(v,u);
        du[u]++;
        du[v]++;
    }
    int ans=n;
    if(k&1)
        for(int u=1;u<=n;u++)
            for(int i=head[u];i;i=edge[i].nxt){
                int v=edge[i].v;
                if(v<u)
                    continue ;
                dfs(u,v,0);
                dfs(v,u,0);
                int cnt=0;
                for(int j=1;j<=n;j++)
                    if(deep[j]>k/2)
                        cnt++;
                ans=min(ans,cnt);
            }
    else
        for(int u=1;u<=n;u++){
            dfs(u,0,0);
            int cnt=0;
            for(int j=1;j<=n;j++)
                if(deep[j]>k/2)
                    cnt++;
            ans=min(ans,cnt);
        }
    printf("%d\n",ans);
}
