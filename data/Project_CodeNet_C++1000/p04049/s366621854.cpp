#include <bits/stdc++.h>
  
using namespace std;
  
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)((x).size()))
  
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef long long int64;
typedef unsigned int uint;
typedef unsigned long long uint64;
  
#define gi(x) ((x) = F())
#define gii(x, y) (gi(x), gi(y))
#define giii(x, y, z) (gii(x, y), gi(z))
  
int F()
{
    char ch;
    int x, a;
    while (ch = getchar(), (ch < '0' || ch > '9') && ch != '-');
    if (ch == '-') ch = getchar(), a = -1;
    else a = 1;
    x = ch - '0';
    while (ch = getchar(), ch >= '0' && ch <= '9')
        x = (x << 1) + (x << 3) + ch - '0';
    return a * x;
}
  
const int N = 2010;
  
VI edge[N];
  
int n, k, dep[N], mxd;
  
void dfs(int u, int fa, int d)
{
    if (k & 1) if(d > k / 2 + 1) return;
    if (!(k & 1)) if (d > k / 2) return;
    ++dep[d];
    mxd = max(mxd, d);
    for (auto v : edge[u])
        if (v != fa)
        {
            dfs(v, u, d + 1);
        }
}
  
int main()
{
    gii(n, k);
    for (int i = 1; i < n; ++i)
    {
        int u, v;
        gii(u, v);
        edge[u].pb(v);
        edge[v].pb(u);
    }
    int res = 0;
    for (int root = 1; root <= n; ++root)
    {
        int mx = 0, s = 1;
        for (auto son : edge[root])
        {
            mxd = 0;
            dfs(son, root, 1);
            if (k & 1) mx = max(mx, dep[k / 2 + 1]);
            if (k & 1) s -= dep[k / 2 + 1];
            for (int i = 1; i <= mxd; ++i) s += dep[i], dep[i] = 0;
        }
        res = max(res, s + mx);
    }
    printf("%d\n", n - res);
    return 0;
}