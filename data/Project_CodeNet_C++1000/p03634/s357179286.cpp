
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <map>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
const ll INF = 1LL << 50;
struct Edge
{
    ll to;
    ll cost;
};

int main()
{
    ll n;
    cin >> n;
    vector<vector<Edge>> ab(n);
    for (int i = 0; i < n - 1; i++)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        ab[a].push_back({b, c});
        ab[b].push_back({a, c});
    }
    ll q, k;
    cin >> q >> k;
    k--;
    vector<P> xy;
    for (int i = 0; i < q; i++)
    {
        ll x, y;
        cin >> x >> y;
        x--;
        y--;
        xy.emplace_back(x, y);
    }
    priority_queue<P, vector<P>, greater<P>> Q;
    Q.push(make_pair(0, k));
    vector<ll> dist(n + 5, INF);
    dist[k] = 0;
    while (!Q.empty())
    {
        auto item = Q.top();
        Q.pop();
        for (int i = 0; i < (int)ab[item.second].size(); i++)
        {
            ll temp_to = ab[item.second][i].to;
            ll temp_cost = ab[item.second][i].cost;
            if (dist[temp_to] <= dist[item.second] + temp_cost)
            {
                continue;
            }
            dist[temp_to] = dist[item.second] + temp_cost;
            Q.emplace(dist[temp_to], temp_to);
        }
    }
    for (int i = 0; i < q; i++)
    {
        cout << dist[xy[i].first] + dist[xy[i].second] << endl;
    }
    return 0;
}
