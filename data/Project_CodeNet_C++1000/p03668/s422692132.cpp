#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;
const int MAXN = 100100;
int n;
int head[MAXN], to[MAXN << 1], nxt[MAXN << 1], cnt;
inline void addedge(int u, int v) {
    to[++cnt] = v, nxt[cnt] = head[u], head[u] = cnt,
    to[++cnt] = u, nxt[cnt] = head[v], head[v] = cnt;
}
inline int dfs(int u, int v) {
    int res = 0, tmp = head[u];
    while(tmp) {
        if(to[tmp] != v) res ^= dfs(to[tmp], u) + 1;
        tmp = nxt[tmp];
    } return res;
}
int main() {
    int u, v;
    scanf("%d", &n);
    for(int i = 1; i < n; i++) {
        scanf("%d%d", &u, &v);
        addedge(u, v);
    } if(dfs(1, 0)) puts("Alice");
    else puts("Bob");
    return 0;
}