#include <bits/stdc++.h>
using namespace std;
const int N=2000;
typedef long long ll;

struct edge
{
    ll head,w,to;
}ed[10*N];

int tot=1;
ll dis[N];
int num[N];
int n,m;
int vis[N];
ll ans;
void Bellman_ford(int x)
{

    for(int i=0;i<=n;i++) dis[i]=1e18;
    dis[x]=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            int x=ed[j].head,y=ed[j].to;
            if(dis[y]>dis[x]+ed[j].w){
                dis[y]=dis[x]+ed[j].w;
            }
        }
    }
    ans=dis[n];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            int x=ed[j].head,y=ed[j].to;
            if(dis[y]>dis[x]+ed[j].w){
                dis[y]=dis[x]+ed[j].w;
                vis[x]=1;
                vis[y]=1;
            }
        }
    }
}
int main() {

    cin>>n>>m;
    for(int i=1;i<=m;i++){
        ll x,y,z;
        cin>>x>>y>>z;
        ed[i].head=x;
        ed[i].to=y;
        ed[i].w=-z;
    }
    Bellman_ford(1);
    if(vis[n]) puts("inf");
    else cout<<-ans<<endl;
    return 0;
}


