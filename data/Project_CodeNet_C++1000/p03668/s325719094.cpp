#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;

typedef long long ll;

const int maxn = 1e5+1;
vector<int> g[maxn];
int n;
int sg[maxn];
void dfs(int cur, int p)
{
    sg[cur] = 0;
    for (int i = 0; i < g[cur].size(); ++i)
    {
        int nxt = g[cur][i];
        if (nxt != p)
        {
            dfs(nxt, cur);
            sg[cur] ^= (1+sg[nxt]);
        }
    }
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n-1; ++i)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1, 0);
    puts(sg[1]?"Alice":"Bob");
}