#include "bits/stdc++.h"

using namespace std;
const int maxn = 1e5 + 100;

vector<int> e[maxn];
int n, m;
int ans[maxn];
int cnt = 0;
int v[maxn], d[maxn], c[maxn];
int maxx[maxn][200];

struct node {
    int vec, d;
};

bool operator<(node a, node b) {
    return a.d < b.d;
}


queue<node> q;

void dfs(int v, int d, int c) {
    if (maxx[v][d]) return;
    if (!ans[v]) ans[v] = c;
    if (d == 0) return;
    int to = e[v].size();
    for (int i = 0; i < to; i++) {
        dfs(e[v][i], d - 1, c);
    }
    maxx[v][d] = 1;
}

int main() {
   // freopen("input.txt", "r", stdin);
    scanf("%d %d", &n, &m);
    int a, b;
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &a, &b);
        e[a].push_back(b);
        e[b].push_back(a);
    }
    int _;
    scanf("%d", &_);
    for (int i = 0; i < _; i++) {
        scanf("%d %d %d", &v[i], &d[i], &c[i]);
    }
    for (int i = _ - 1; i >= 0; i--) {
        dfs(v[i], d[i], c[i]);
    }
    for (int i = 1; i <= n; i++) {
        printf("%d\n", ans[i]);
    }
    return 0;
}