#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int max_n=100005;
int n;
vector<int> G[max_n];
int dis[max_n];
int d[2][max_n];
void dfs(int u,int fa){
    for(auto v:G[u]){
        if(v==fa)continue;
        dis[v]=dis[u]+1;
        dfs(v,u);
    }
}
void work(int s,int d[]){
    dis[s]=0;
    dfs(s,0);
    for(int i=1;i<=n;i++)d[i]=dis[i];
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<n;i++){
        int u,v;scanf("%d%d",&u,&v);
        G[u].push_back(v),G[v].push_back(u);
    }
    work(1,d[0]),work(n,d[1]);
    int cnt=0;
    for(int i=1;i<=n;i++)if(d[0][i]<=d[1][i])cnt++;
    if(cnt>n-cnt)printf("Fennec\n");
    else printf("Snuke\n");
    return 0;
}