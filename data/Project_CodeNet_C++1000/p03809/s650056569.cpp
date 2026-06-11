#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 123456;

int n;
ll a[N];
vector<int> g[N];
ll f[N];

void fuck() {
    puts("NO");
    exit(0);
}

void dfs(int v, int p) {
    f[v] = (g[v].size() == 1 ? a[v] : 2 * a[v]);
    for (int u: g[v]) {
        if (u == p) {
            continue;
        }
        dfs(u, v);
        if (f[u] > a[v]) {
            fuck();
        }
        f[v] -= f[u];
    }

    if (g[v].size() > 1) {
        if (f[v] > a[v]) {
            fuck();
        }
    }

    if (f[v] < 0) {
        fuck();
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    dfs(0, -1);

    if (f[0] != 0) {
        fuck();
    }
    
    puts("YES");
}
