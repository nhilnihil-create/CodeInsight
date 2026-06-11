#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
using namespace std;
const int N=1e6+5;
typedef long long ll;
struct node{
    int u,v,nxt;
}edge[N*2];
int head[N],mcnt;
int du[N];
int a[N];
int n;
void add_edge(int u,int v){
    mcnt++;
    du[u]++;
    edge[mcnt].u=u;
    edge[mcnt].v=v;
    edge[mcnt].nxt=head[u];
    head[u]=mcnt;
}
void nosol(){
    puts("NO");
    exit(0);
}
void dfs(int u,int fa){
    if(du[u]==1)
        return ;
    int sum=0,mx=0;
    for(int i=head[u];i;i=edge[i].nxt){
        int v=edge[i].v;
        if(v==fa)
            continue;
        dfs(v,u);
        sum+=a[v];
        mx=max(mx,a[v]);
    }
    if(sum<a[u]||sum>2*a[u])
        nosol();
    if(mx>a[u])
        nosol();
    a[u]=2*a[u]-sum;
}
int main()
{
    //freopen("tree.in","r",stdin);
    //freopen("tree.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    if(n==2){
        if(a[1]==a[2])
            puts("YES");
        else
            puts("NO");
        return 0;
    }
    for(int i=1;i<n;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        add_edge(u,v);
        add_edge(v,u);
    }
    int root=1;
    while(du[root]==1)
        root++;
    dfs(root,0);
    if(a[root])
        nosol();
    puts("YES");
}
