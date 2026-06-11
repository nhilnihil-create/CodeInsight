#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

struct edge {
    int v;
    edge *next;
} pool[N * 3], *h[N];

int n, k, p[N], top = -1, ans;
int dis[N];

inline void addedge(int u, int v) {
    edge *tmp = &pool[++top];
    tmp -> v = v; tmp -> next = h[u]; h[u] = tmp;
}

void dfs(int u) { for(edge *tmp = h[u]; tmp != NULL; tmp = tmp -> next) dis[tmp -> v] = dis[u] + 1, dfs(tmp -> v); }

int solve(int u) {
    int res = 1;
    for(edge *tmp = h[u]; tmp != NULL; tmp = tmp -> next) {
        int v = tmp -> v;
        res = max(res, solve(tmp -> v) + 1);
    }
    if(res == k) if(dis[u] > 1) ans++, res = -1;
    return res; 
}

void init() {
    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        cin >> p[i];
        if(i != 1) addedge(p[i], i);
    }
    if(p[1] != 1) ans++;
    dfs(1);
    solve(1);
    cout << ans << endl;
}

int main() {
    init();
    return 0;
}