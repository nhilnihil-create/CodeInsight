#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 10;
int f[maxn], g[maxn], ans[maxn];

void init()
{
   for(int i = 0; i < maxn; i++)
        f[i] = i, g[i] = i;
}

int getf(int *data, int u)
{
    if(data[u] == u) return u;
    return data[u] = getf(data, data[u]);
}

void Merge(int *data, int u, int v)
{
    int t1 = getf(data, u);
    int t2 = getf(data, v);
    data[t2] = t1;
}

vector<int> root[maxn];
map<int, int> p;

int main()
{
    int n, k, l, u, v;
    scanf("%d %d %d", &n, &k, &l);
    init();
    for(int i = 0; i < k; i++)
    {
        scanf("%d %d", &u, &v);
        Merge(f, u, v);
    }
    for(int i = 0; i < l; i++)
    {
        scanf("%d %d", &u, &v);
        Merge(g, u, v);
    }

    for(int i = 1; i <= n; i++)
    {
       root[getf(f, i)].push_back(i);
    }
    for(int i = 1;  i <= n; i++)
    {
         p.clear();
        int len = root[i].size();
        for(int j = 0; j < len; j++)
        {
            p[getf(g, root[i][j])]++;
        }
        for(int j = 0; j < len; j++)
            ans[root[i][j]] += p[getf(g, root[i][j])];
    }
    for(int i = 1; i <= n; i++)
        printf("%d%c", ans[i], i == n ? '\n' : ' ');
}
