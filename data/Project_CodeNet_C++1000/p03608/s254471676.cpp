#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<(b);++i)
const int INF = 0x3f3f3f3f;

bool vis[10];
int ans=INF;
int n,m,r;
int R[10];
int d[205][205];
void dfs(int x,int cur)         //x是地点编号，cur是已经走过的距离
{
    bool flag = 1;
    for(int i=1;i<=r;i++) if(!vis[R[i]]) flag=0 ;
    if(flag&&cur<ans){              //已经经过了所有的r个点
        ans=cur;
        return;
    }

    for(int i=1;i<=r;i++){
        if(vis[R[i]]) continue;
        if(d[x][R[i]]>=INF) continue;
        vis[R[i]]=true;
        dfs(R[i],cur+d[x][R[i]]);
        vis[R[i]]=false;
    }
    return ;
}

int main()
{
    scanf("%d%d%d",&n,&m,&r);
    rep(i,1,r+1) scanf("%d",&R[i]);

    for(int i=0;i<205;i++) for(int j=0;j<205;j++) {
        if(i==j) d[i][j]=0;
        else d[i][j]=INF;
    }

    rep(i,0,m){
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        d[u][v]=w;              //bidirectional双向边
        d[v][u]=w;
    }

    for(int k=1;k<=n;k++)       //floyd
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                d[i][j] = min(d[i][j],d[i][k]+d[k][j]);

    memset(vis,0,sizeof(vis));
    for(int i=1;i<=r;i++){      //枚举起点
        vis[R[i]]=true;
        dfs(R[i],0);
        vis[R[i]]=false;
    }
    printf("%d\n",ans);
}
