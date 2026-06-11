#include <bits/stdc++.h>
using namespace std;
template <class T>
inline bool chmax(T &a, T b)
{
    if (a < b)
    {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
inline bool chmin(T &a, T b)
{
    if (a > b)
    {
        a = b;
        return 1;
    }
    return 0;
}
typedef long long int ll;

#define EPS (1e-7)
#define INF (1 << 30)
#define LLINF (1LL << 60)
#define PI (acos(-1))
#define MOD (1000000007)
#define ALL(v) (v).begin(), (v).end()
#define RALL(v) (v).rbegin(), (v).rend()
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

//-------------------------------------

void bfs(vector<vector<int>> &graph, vector<int> &d, int s)
{
    queue<int> q;
    q.push(s);
    d[s] = 0;
    while (!q.empty())
    {
        int now = q.front();
        q.pop();
        for (auto v : graph[now])
        {
            if (d[v] == INF)
            {
                chmin(d[v], d[now] + 1);
                q.push(v);
            }
        }
    }
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<vector<int>> g(n);
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vector<int> fennec(n, INF);
    vector<int> snuke(n, INF);
    bfs(g, fennec, 0);
    bfs(g, snuke, n - 1);
    vector<int> color(n, 0);
    for (int i = 0; i < n; i++)
    {
        if (fennec[i] <= snuke[i])
        {
            color[i] = 1;
        }
        else
        {
            color[i] = -1;
        }
    }
    int f = count(ALL(color), 1);
    int s = count(ALL(color), -1);
    cout << (f <= s ? "Snuke" : "Fennec") << endl;
}