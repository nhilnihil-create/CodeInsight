#include <bits/stdc++.h>

using namespace std ;
typedef long long ll;

int n, k;
int a, b;
vector < vector < int > > V;
bool vis[2020];
int dfs(int u, int d = 0)
{
    if (vis[u]) return 0;
    int cur = d > k/2;
    vis[u] = 1;
    for (auto v: V[u])
        cur += dfs(v, d+1);
    vis[u] = 0;
    return cur;
}
int dfsOdd(int u, int u2, int d = 0)
{
    if (u == u2) return 0;
    if (vis[u]) return 0;
    int cur = d > (k-1)/2;
    vis[u] = 1;
    for (auto v: V[u])
        cur += dfsOdd(v, u2, d+1);
    vis[u] = 0;
    return cur;
}
int main()
{
    scanf("%d%d", &n, &k);
    V.resize(n);
    for (int i = 1; i < n; ++i)
    {
        scanf("%d%d", &a, &b);
        --a; --b;
        V[a].push_back(b);
        V[b].push_back(a);
    }
    int ans = INT_MAX;
    for (int i = 0; i < n; ++i)
    {
        if (k&1)
        {
            for (auto u: V[i])
                ans = min(ans, dfsOdd(i, u) + dfsOdd(u, i));
        }
        else
            ans = min(ans, dfs(i));
    }
    printf("%d\n", ans);

    return 0 ;
}
