#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
const int maxn = 1000005;

vector<int> G[maxn];
int sg[maxn];

void dfs(int u, int fa)
{
    sg[u] = 0;
    for (auto v : G[u]) {
        if (v == fa)
            continue;
        dfs(v, u);
        sg[u] ^= sg[v] + 1;
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        G[u].push_back(v), G[v].push_back(u);
    }
    dfs(1, 0);
    printf("%s\n", sg[1] ? "Alice" : "Bob");
    cin >> ws;
    return 0;
}