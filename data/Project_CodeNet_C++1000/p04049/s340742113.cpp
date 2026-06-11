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
vector<int> d(2001);
vector<vector<int>> g(2001);
void dfs(int s)
{
    for (auto v : g[s])
    {
        if (d[v] == INF)
        {
            d[v] = d[s] + 1;
            dfs(v);
        }
    }
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int ans = n;
    if (k % 2 == 0)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                d[j] = INF;
            }
            d[i] = 0;
            dfs(i);
            int cnt = 0;
            for (int j = 0; j < n; j++)
            {
                if (d[j] > k / 2)
                {
                    cnt++;
                }
            }
            chmin(ans, cnt);
        }
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            for (auto j : g[i])
            {
                if (i < j)
                {
                    for (int e = 0; e < n; e++)
                    {
                        d[e] = INF;
                    }
                    d[i] = 0;
                    d[j] = 0;
                    dfs(i);
                    dfs(j);
                    int cnt = 0;
                    for (int e = 0; e < n; e++)
                    {
                        if (d[e] > (k - 1) / 2)
                        {
                            cnt++;
                        }
                    }
                    chmin(ans, cnt);
                }
            }
        }
    }
    cout << ans << endl;
}