#include <iostream>
#include <cstdio>
#include <queue>
#define REP(i,a,n) for(int i=a;i<=n;++i)
#define pb push_back
using namespace std;

const int N = 1e6+10;
int n, k, ans, a[N], f[N];
vector<int> g[N];

void dfs(int x) { 
    f[x] = 1;
    for (int y:g[x]) dfs(y), f[x] = max(f[x], f[y]+1);
    if (f[x]==k&&a[x]!=1) ++ans,f[x]=0;
}
int main() {
    scanf("%d%d", &n, &k);
    REP(i,1,n) scanf("%d", a+i);
    ans = a[1]!=1;
    a[1] = 1;
    REP(i,2,n) g[a[i]].pb(i);
    dfs(1);
    printf("%d\n", ans);
}