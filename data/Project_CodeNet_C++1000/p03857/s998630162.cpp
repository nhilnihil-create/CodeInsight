#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define maxn 212345
#define met(a, b) memset(a, b, sizeof(a))
class UMS
{
public:
    int f[maxn];
    UMS()
    {
        for(int i = 0; i < maxn; i++)
        {
            f[i] = i;
        }
    }
    int getf(int u)
    {
        if(u == f[u])
            return f[u];
        else
        {
            f[u] = getf(f[u]);
            return f[u];
        }
    }
    void Merge(int u, int v)
    {
        int f1 = getf(u);
        int f2 = getf(v);
        if(f1 != f2)
        {
            f[f1] = f2;
        }
    }
};
vector<int> vec[maxn];
map<int, int> q;
int main()
{
    UMS u1, u2;
    int n, k, l, u, v;
    scanf("%d%d%d", &n, &k, &l);
    while(k--)
    {
        scanf("%d %d", &u, &v);
        u1.Merge(u, v);
    }
    while(l--)
    {
        scanf("%d %d", &u, &v);
        u2.Merge(u, v);
    }
    int vis[maxn];
    met(vis, 0);
    for(int i = 1; i <= n; i++)
    {
        int fa = u1.getf(i);
        vec[fa].push_back(i);
    }
    for(int i = 1; i <= n; i++)
    {
        q.clear();
        for(int j = 0; j < vec[i].size(); j++)
        {
            q[u2.getf(vec[i][j])] ++;
        }
        for(int j = 0; j < vec[i].size(); j++)
        {
            vis[vec[i][j]] += q[u2.getf(vec[i][j])];
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
