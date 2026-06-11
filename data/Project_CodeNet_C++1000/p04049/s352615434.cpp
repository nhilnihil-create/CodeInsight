#include<bits/stdc++.h>
#define N 500005
using namespace std;
int n,K,x,y,kk,ans,t,opt,head[N];
struct Tree{int nxt,to,from;}e[N];
inline void add(int x,int y){e[++kk].nxt=head[x];e[kk].from=x;e[kk].to=y;head[x]=kk;}
void dfs(int u,int fa,int dep){
    if (dep>K) return;t++;
    for (int i=head[u];i;i=e[i].nxt){
        int v=e[i].to;
        if (v==fa) continue;
        dfs(v,u,dep+1);
    }
}
inline void sc(int x){
    t=0;dfs(x,-1,0);ans=min(ans,n-t);
}
inline void sc1(int x){
    t=0;dfs(e[x].to,e[x].from,0);
    dfs(e[x].from,e[x].to,0);
    ans=min(ans,n-t);
}
int main(){
    scanf("%d%d",&n,&K);
    int opt=(K&1);
    if (K%2==0) K/=2;
    else K=(K-1)/2;
    for (int i=1;i<n;i++){
        scanf("%d%d",&x,&y);
        add(x,y);add(y,x);
    }
    ans=1e9;
    if (!opt) for (int i=1;i<=n;i++) sc(i);
    if (opt) for (int i=1;i<=kk;i+=2) sc1(i);
    printf("%d\n",ans);
    return 0;
}