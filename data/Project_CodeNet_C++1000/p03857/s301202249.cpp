#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
using namespace std;
const int MAXN = 300005;
map<pair<int,int>,int>mp;
int fa1[MAXN],fa2[MAXN],*fa,n,*head,m1,m2,cnt;
int head1[MAXN],head2[MAXN];
struct Edge{
    int to,next;
}e[MAXN<<2];
inline void insert(int u,int v)
{
    e[++cnt].to=v,e[cnt].next=head[u],head[u]=cnt;
    e[++cnt].to=u,e[cnt].next=head[v],head[v]=cnt;
}
int *vis,vis1[MAXN],vis2[MAXN],q[MAXN];
inline void bfs(int s)
{
    int front=1,back=0,u,v;
    q[++back]=s,vis[s]=1;
    while(front<=back){
        u=q[front++];
        for(int i=head[u];i;i=e[i].next){
            v=e[i].to;
            if(!vis[v]){
                vis[v]=1;
                q[++back]=v;
                fa[v]=s;
            }
        }
    }
}
int main()
{
    head=head1;
    scanf("%d%d%d",&n,&m1,&m2);
    for(int i=1;i<=m1;++i){
        int u,v;
        scanf("%d%d",&u,&v);
        insert(u,v);
    }
    head=head2;
    for(int i=1;i<=m2;++i){
        int u,v;
        scanf("%d%d",&u,&v);
        insert(u,v);
    }
    head=head1;
    fa=fa1,vis=vis1;
    for(int i=1;i<=n;++i)fa[i]=i;
    for(int i=1;i<=n;++i)if(!vis[i])bfs(i);
    head=head2;
    fa=fa2,vis=vis2;
    for(int i=1;i<=n;++i)fa[i]=i;
    for(int i=1;i<=n;++i)if(!vis[i])bfs(i);
    for(int i=1;i<=n;++i)++mp[make_pair(fa1[i],fa2[i])];
    for(int i=1;i<=n;++i)
        printf("%d ",mp[make_pair(fa1[i],fa2[i])]);
    return 0;
}