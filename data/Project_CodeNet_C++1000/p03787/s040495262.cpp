#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
const int N = 100000 + 10;
typedef long long LL;

int n, m, deg[N];
LL ans = 0;
int col[N];

vector<int> g[N];


int gg = 0;
void dfs(int u) {
    for (auto v: g[u]) {
        if (col[v]) {
            if (col[u] + col[v] != 3) {
                gg = 1; 
            } 
        } else {
            col[v] = 3 - col[u];
            dfs(v);
        }
    }
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i ++) {
        int u, v; scanf("%d%d", &u, &v);
        deg[u] ++, deg[v] ++;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    LL A = 0, B = 0, C = 0;
    for (int i = 1; i <= n; i ++) {
        if (deg[i] == 0) {
            C ++;
            continue;
        }
        if (col[i] == 0) {
            col[i] = 1; 
            gg = 0;
            dfs(i);
            if (gg) A ++;
            else B ++; 
        }
    }
    // printf("A = %d, B = %d, C = %d\n", A, B, C);
    ans = ans + C * n * 2 - C * C;
    ans = ans + A * B + B * A;
    ans = ans + A * A + B * B * 2;
    printf("%lld\n", ans);
}   


