#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
int n, k, nowcolor;
vector<int>color[maxn];
vector<int>G[maxn];
bool vis[maxn];
map<vector<int>, int>Map;
void dfs(int u)
{
    vis[u] = 1;color[u].push_back(nowcolor);
    for(auto v : G[u])if(!vis[v])dfs(v);
}
int main()
{
    k = 2;int a[3];
    scanf("%d%d%d", &n, &a[1], &a[2]);
    for(int i = 1; i <= k; i++)
    {
        for(int j = 1; j <= n; j++)G[j].clear(), vis[j] = 0;
        int m, u, v;
        m = a[i];
        while(m--)
        {
            scanf("%d%d", &u, &v);
            G[u].push_back(v);
            G[v].push_back(u);
        }
        nowcolor = 0;
        for(int j = 1; j <= n; j++)
            if(!vis[j])nowcolor++, dfs(j);
    }
    for(int i = 1; i <= n; i++)Map[color[i]]++;
    for(int i = 1; i <= n; i++)printf("%d ", Map[color[i]]);
    return 0;
}
