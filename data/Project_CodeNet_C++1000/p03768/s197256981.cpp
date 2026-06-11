#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=1e6+5;
typedef long long ll;
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
int c[N];
int vis[N],tot;
int n,m;
int deep[N];
int q[N],h,t;
int x[N],y[N],z[N];
int maxdeep[N];
void bfs(int s,int depth,int color){
    if(depth<=maxdeep[s])
        return ;
    vis[s]=tot;
    deep[s]=depth;
    maxdeep[s]=depth;
    h=t=1;
    q[1]=s;
    while(h<=t){
        int u=q[h++];
        if(!c[u])
            c[u]=color;
        if(deep[u]==0)
            continue ;
        for(int i=head[u];i;i=edge[i].nxt){
            int v=edge[i].v;
            if(vis[v]>tot&&maxdeep[v]<deep[u]-1){
                vis[v]=tot;
                deep[v]=deep[u]-1;
                maxdeep[v]=deep[u]-1;
                q[++t]=v;
            }
        }
    }
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        add_edge(u,v);
        add_edge(v,u);
    }
    int qu;
    scanf("%d",&qu);
    for(int i=1;i<=qu;i++){
        scanf("%d%d%d",&x[i],&y[i],&z[i]);
    }
    for(int i=1;i<=n;i++)
        vis[i]=qu+1,maxdeep[i]=-1;
    for(tot=qu;tot>=1;tot--){
        bfs(x[tot],y[tot],z[tot]);
    }
    for(int i=1;i<=n;i++)
        printf("%d\n",c[i]);
}
