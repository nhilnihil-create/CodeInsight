#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;
const int N = 500007, M = 5000007, INF = 0x3f3f3f3f;


int n,m ;
int head[N], ver[M], nex[M], tot;
int ans[N];

struct node{
    int v, d, c;
}a[N];
int dist[N];
void add(int x, int y){
    ver[tot] = y;
    nex[tot] = head[x];
    head[x] = tot ++ ;
}

void dfs(int x, int color, int deep){
    if(!ans[x])ans[x] = color;
    if(deep == 0 || dist[x] >= deep)return ;
    dist[x] = deep;
    for(int i = head[x]; ~i; i = nex[i]){
        int y = ver[i];
        dfs(y, color, deep - 1);
    }
}

int main(){
    scanf("%d%d", &n,&m);
    memset(head, -1, sizeof head);
    for(int i = 1; i <= m; ++ i){
        int x, y;
        scanf("%d%d",&x, &y);
        add(x, y), add(y, x);
    }
    int q;
    scanf("%d", &q);
    for(int i = 1; i <= q; ++ i)
    scanf("%d%d%d", &a[i].v, &a[i].d, &a[i].c);
    for(int i = q; i >= 1; -- i){
        dfs(a[i].v, a[i].c, a[i].d);
    }
    
    for(int i = 1; i <= n; ++ i)
    printf("%d\n", ans[i]);
    puts("");
    return 0;
}