#include <iostream>
#include <vector>

using namespace std;

#define int long long

const int MOD = 998244353;
const int N = 2e5 + 111;
const int INF = 1e9;

int n, k;
vector<int> graph[N];
int ans = 0;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    if (k % 2 == 0)
    {
        for (int i = 1; i <= n; i++)
        {
            vector<int> q = {i};
            vector<int> dist(n + 1, INF);
            dist[i] = 0;
            for (int j = 0; j < q.size(); j++)
            {
                int v = q[j];
                for (auto u : graph[v])
                {
                    if (dist[u] > dist[v] + 1)
                    {
                        dist[u] = dist[v] + 1;
                        if (dist[u] <= k / 2)
                        {
                            q.push_back(u);
                        }
                    }
                }
            }
            ans = max(ans, (int)q.size());
        }
    }
    else
    {
        for (int i = 1; i <= n; i++)
        {
            for (auto x : graph[i])
            {
                vector<int> q = {i, x};
                vector<int> dist(n + 1, INF);
                dist[i] = 0;
                dist[x] = 0;
                for (int j = 0; j < q.size(); j++)
                {
                    int v = q[j];
                    for (auto u : graph[v])
                    {
                        if (dist[u] > dist[v] + 1)
                        {
                            dist[u] = dist[v] + 1;
                            if (dist[u] <= k / 2)
                            {
                                q.push_back(u);
                            }
                        }
                    }
                }
                ans = max(ans, (int)q.size());
            }
        }
    }
    cout << n - ans << "\n";
}
