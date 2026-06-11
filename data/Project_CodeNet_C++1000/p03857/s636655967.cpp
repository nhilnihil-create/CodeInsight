#include<bits/stdc++.h>
using namespace std;
const int N = 2*1e5;
int n;
int Find(int *f, int x)
{
    if(f[x] == x)
        return x;
    else
    {
        f[x] = Find(f, f[x]);
        return f[x];
    }
}
void Merge(int *f, int x, int y)
{
    x = Find(f, x);
    y = Find(f, y);
    if(x != y)
        f[y] = x;
}
int f[N], g[N], vis[N];
vector<int> vec[N];
map<int, int> q;
void init()
{
    for(int i = 0; i <= n; i++)
        f[i] = g[i] = i;
}
int main()
{
    int k, l, u, v;
    scanf("%d %d %d", &n, &k, &l);
    init();
    while(k--)
    {
        scanf("%d %d", &u, &v);
        Merge(f, u, v);
    }
    while(l--)
    {
        scanf("%d %d", &u, &v);
        Merge(g, u, v);
    }
    memset(vis, 0, sizeof(vis));
    for(int i = 1; i <= n; i++) vec[Find(f, i)].push_back(i);
    for(int i = 1; i <= n; i++)
    {
        q.clear();
        for(int j = 0; j < vec[i].size(); j++)
        {
            q[Find(g, vec[i][j])]++;
        }
        for(int j = 0; j < vec[i].size(); j++)
        {
            vis[vec[i][j]] += q[Find(g, vec[i][j])];
        }
    }
    for(int i = 1; i <= n; i++)
    {
        printf("%d", vis[i]);
        if(i == n) printf("\n");
        else printf(" ");
    }
    return 0;
}
