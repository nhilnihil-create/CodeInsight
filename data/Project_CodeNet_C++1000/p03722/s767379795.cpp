#include <bits/stdc++.h>
#define NIL -1
#define rep(i, n) for (int i = 0; i < (n); i++)
typedef long long int ll;
using namespace std;
const ll INF = 1LL << 60;

using Edge = pair<int, ll>;
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, m;

    cin >> n >> m;
    int a, b, c;
    vector<vector<Edge>> G;
    G.clear();
    G.resize(n);
    rep(i, m)
    {
        cin >> a >> b >> c;
        a--, b--;
        c=-c;
        G[a].push_back(Edge(b, c));
    }

    vector<ll> dist(n, INF);
    bool close = false;
    dist[0] = 0;
    rep(i, n)
    {
        rep(j, n)
        {
            for (auto v : G[j])
            {
                int from = j, to = v.first;
                ll cost = v.second;
                if (dist[from] != INF && dist[to] > dist[from] + cost)
                {
                    dist[to] = dist[from] + cost;
                    if (i == n - 1 &&to==n-1)
                    {
                        close = true;
                        break;
                    }
                }
            }
        }
    }

    if (close)
    {
        cout << "inf" << endl;
    }
    else
    {
        cout << -dist[n - 1] << endl;
    }
 //   system("pause");
    return 0;
}