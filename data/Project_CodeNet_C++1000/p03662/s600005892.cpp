#include<cstdio>
#include<vector>
std::vector<int>g[100005];
int son[100005];
int vis[100005];
int p[100005];
int seq[100005];

void dfs(int u,int ban){
    vis[u] = son[u] = 1;
    for(int v: g[u]){
        if(v!=ban && !vis[v]){
            dfs(v,ban);
            p[v] = u;
            son[u] += son[v];
        }
    }
    vis[u] = 0;
}

int main(){
    int n;
    scanf("%d",&n);
    for(int i = 1; i <= n-1; i++){
        int u,v;
        scanf("%d%d",&u,&v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    p[1] = -1;
    dfs(1,-1);
    int cur = n, size = 0;
    while(cur!=-1){
        seq[++size] = cur;
        cur = p[cur];
    }
    int L = 1, R = size;
    while(R-1>L){
        R--;
        if(L+1!=R) L++;
    }
    //printf("L = %d, R = %d\n",L,R);
    for(int i = 1; i <= n; i++) son[i] = 0;
    int start = seq[R], ban = seq[R-1];
    dfs(start,ban);
    int my = son[start], your = n-son[start];
    if(my>your) printf("Fennec\n");
    else printf("Snuke\n");
    return 0;
}
