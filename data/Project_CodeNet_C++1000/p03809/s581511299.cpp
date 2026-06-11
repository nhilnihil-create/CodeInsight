#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 1e5 + 5;
int n;
int a[maxn];
vector<int> way[maxn];
ll par[maxn];
int bad;
void dfs(int u, int last) {
    int child = 0;
    for(auto v : way[u]) {
        if(v==last) continue;
        dfs(v, u);
        child++;
    }
    if(child==0) par[u] = a[u];
    else {
        par[u] = 2*a[u];
        for(auto v : way[u]) {
            if(v==last) continue;
            if(par[v]>a[u]) bad = 1;
            par[u] -= par[v];
        }
        if(par[u]>a[u]) bad = 1;
    }
    if(par[u]<0) bad = 1;
//    printf("par %d = %d\n",u,par[u]);
}
int main() {
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n-1;i++) {
        int u,v; scanf("%d%d",&u,&v);
        way[u].push_back(v);
        way[v].push_back(u);
    }
    if(n==2) {
        printf("%s",a[1]==a[2] ? "YES" : "NO");
        return 0;
    }
    int root = -1;
    for(int i=1;i<=n;i++) if(way[i].size()>1) root = i;
    dfs(root,0);
    if(par[root]!=0) bad = 1;
    printf("%s",bad?"NO":"YES");
}
