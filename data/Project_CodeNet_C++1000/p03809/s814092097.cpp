#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 11;
int n, a[N], du[N], x[N];
int head[N], nex[N<<1], to[N<<1], size;
bool flag = 1;
void add(int x, int y){
    to[++size] = y;
    nex[size] = head[x];
    head[x] = size;
}
void dfs(int u, int fa){
    if(du[u] == 1){
        x[u] = a[u];
        return ;
    }
    int sum = 0, ma = 0;
    for(int i = head[u];i;i = nex[i]){
        int v = to[i];
        if(v == fa)continue;
        dfs(v, u);
        sum += x[v];
        ma = max(ma, x[v]);
    }
    int k = sum - a[u];
    if(k < 0)flag = 0;
    x[u] = sum - 2 * k;
    if(x[u] < 0)flag = 0;
    if(u == fa && x[u] > 0)flag = 0;
    if(k > min(sum / 2, sum - ma))flag = 0;
}
int main(){
    scanf("%d", &n);
    for(int i = 1;i <= n; i++){
        scanf("%d", &a[i]);
    }
    if(n == 2){
        if(a[1] == a[2])puts("YES");
        else puts("NO");
        return 0;
    }
    int u, v;
    for(int i = 1;i < n; i++){
        scanf("%d%d", &u, &v);
        du[u]++; du[v]++;
        add(u, v);
        add(v, u);
    }
    int rt = 1;
    for(int i = 1;i <= n; i++)if(du[i] != 1)rt = i;
    dfs(rt, rt);
    if(flag)puts("YES");
    else puts("NO");
    return 0;
}
