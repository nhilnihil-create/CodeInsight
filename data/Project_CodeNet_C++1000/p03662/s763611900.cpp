#include        <map>
#include      <queue>
#include     <string>
#include     <cstdio>
#include     <vector>
#include    <cstring>
#include   <iostream>
#include  <algorithm>
using namespace std;
#define ll long long
const ll inf = 1000000000000000000ll;
const int maxn = 1e5+5;
const ll mod = 1e9+7;
int vis[maxn]={0};
bool vis2[maxn]={0};
int to[maxn*2],nx[maxn*2],head[maxn],tot=0;
int n;
int cnt1=0,cnt2=0;

void add(int u,int v){
    to[tot] = v;
    nx[tot] = head[u];
    head[u] = tot++;

    to[tot] = u;
    nx[tot] = head[v];
    head[v] = tot++;
}
int fl=0;
bool dfs(int u,int d){
    if(u==n){
        fl = (d-1)/2;
        return true;
    }
    for(int i=head[u];i!=-1;i=nx[i]){
        int v = to[i];
        if(vis2[v]==0){
            vis2[v] = 1;
            if(dfs(v,d+1)){
                if(d<=fl)vis[v] = 1;
                else vis[v] = -1;
                return true;
            }
        }
    }
    return false;
}
void bfs1(int u){
    queue<int>q;q.push(u);
    while(!q.empty()){
        int t= q.front();q.pop();
        for(int i=head[t];i!=-1;i=nx[i]){
            int v = to[i];
            if(vis[v]==0){
                vis[v] = 2;
                cnt1++;
                q.push(v);
            }
        }
    }
}
void bfs2(int u){
    queue<int>q;q.push(u);
    while(!q.empty()){
        int t = q.front();q.pop();
        for(int i=head[t];i!=-1;i=nx[i]){
            int v = to[i];
            if(vis[v]==0){
                vis[v] = -2;
                cnt2++;
                q.push(v);
            }
        }
    }
}
int main(){
    int u, v;
    memset(head,-1,sizeof(head));
    scanf("%d",&n);
    for(int i=1;i<n;i++){
        scanf("%d%d",&u,&v);
        add(u,v);
    }
    vis2[1]=1;
    dfs(1,1);
    vis[1]=1;vis[n]=-1;


    for(int i=1;i<=n;i++){
        if(vis[i]==1){
            bfs1(i);cnt1++;
        }else if(vis[i]==-1){
            bfs2(i);cnt2++;
        }
    }

    if(cnt1>cnt2)
        puts("Fennec");
    else
        puts("Snuke");
    return 0;
}
/*

6
1 2
2 3
3 5
3 6
1 4


5
1 5
5 2
2 3
3 4


*/
