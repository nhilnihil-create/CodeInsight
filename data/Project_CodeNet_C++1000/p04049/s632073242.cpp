#include <bits/stdc++.h>
 

using namespace std;

const int Maxn = 4000 + 100;
int Begin[Maxn], To[Maxn], Next[Maxn], e;
int sum[Maxn], dis[Maxn];
int n, K, maxi;
vector<int> graph[Maxn];

void add_edge(int x, int y)
{
    To[++e] = y;
    Next[e] = Begin[x];
    Begin[x] = e;
}
void dfs (int x, int fa)
{
    maxi = max(maxi, dis[x]);
    sum[dis[x]] ++;
    for (int i = 0; i < graph[x].size(); i++)
    {
        int y = graph[x][i];
        if (y == fa) 
        	continue;
        dis[y] = dis[x] + 1;
        dfs(y, x);
    }
}

int main()
{
    cin >> n >> K;
    for (int i = 1; i < n; ++i)
    {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
        add_edge(x, y);
        add_edge(y, x);
    }
    int ans = 1000 * 1000 * 1000;
    for (int i = 1; i <= n; ++i)
    {
        memset(sum, 0, sizeof(sum));
        memset(dis, 0, sizeof(dis));
        maxi = 0;
        dfs(i, 0);
        int cnt = 0;
        for (int j = K / 2 + 1; j <= maxi; ++j)
            cnt += sum[j];
        if (!(K & 1))
        {
        	ans = min(ans, cnt);
        }
        else 
        {
            for (int j = Begin[i]; j; j = Next[j])
            {
                int y = To[j];
                int tmp = 0;
                memset(sum, 0, sizeof(sum));
                memset(dis, 0, sizeof(dis));
                maxi = 0;
                dfs(i, y);
                for (int k = K / 2 + 1; k <= maxi; ++k)
                {
                    tmp += sum[k];
                }
                memset(sum, 0, sizeof(sum));
                memset(dis, 0, sizeof(dis));
                maxi = 0;
                dfs(y, i);
                for (int k = K / 2 + 1; k <= maxi; k++)
                {
                    tmp += sum[k];
                }
                ans = min(ans, tmp);
            }
        }
    }
    cout << ans << endl;
}
 

   
