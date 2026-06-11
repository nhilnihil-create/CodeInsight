#include <bits/stdc++.h>
#define INF 1000000000000000001
#define ll long long
#define pll pair<ll, ll>
using namespace std;

struct edge {ll to, cost;};

//=============dijkstra============================
void dijkstra(ll s, ll V, vector<vector<edge>>& G, vector<vector<bool>>& used)
{
  vector<ll> d(V, INF);
  typedef pair<ll, ll> P;// first は最短距離　second は頂点の番号
  priority_queue<P, vector<P>, greater<P>> que;
  d.at(s) = 0;
  que.push(P(0, s));
  while (!que.empty())
  {
    P p = que.top();
    que.pop();
    ll v = p.second;
    if (d.at(v) < p.first) continue;
    for (ll i = 0; i < G.at(v).size(); ++i)
    {
      edge e = G.at(v).at(i);
      if (d.at(e.to) > d.at(v) + e.cost)
      {
        // cout << "V" << v << "e.to" << e.to << endl;
        // cout << d.at(e.to) << ' ' << d.at(v) + e.cost << endl;
        d.at(e.to) = d.at(v) + e.cost;
        que.push(P(d.at(e.to), e.to));
      }
    }
  }
  for (ll i = 0; i < V; ++i)
  {
    for (ll j = 0; j < G.at(i).size(); ++j)
    {
      edge e = G.at(i).at(j);
      if (d.at(i) + e.cost == d.at(e.to))
      {
        used.at(i).at(e.to) = true;
        used.at(e.to).at(i) = true;
      }
    }
  }
}
//=================================================

int main()
{
  ll N, M;
  cin >> N >> M;
  vector<vector<edge>> G(N);
  for (ll i = 0; i < M; ++i)
  {
    ll a, b, c;
    cin >> a >> b >> c;
    G.at(a - 1).push_back({b - 1, c});
    G.at(b - 1).push_back({a - 1, c});
  }
  vector<vector<bool>> used(N, vector<bool>(N, false));
  for (ll i = 0; i < N; ++i)
  {
    dijkstra(i, N, G, used);
  }
  ll ans = M;
  for (ll i = 0; i < N - 1; ++i)
  {
    for (ll j = i + 1; j < N; ++j)
    {
      if (used.at(i).at(j))
      {
        ans -= 1;
      }
    }
  }
  cout << ans << endl;
  // for (ll i = 0; i < N; ++i)
  // {
  //   for (ll j = 0; j < N; ++j)
  //   {
  //     if (used.at(i).at(j))
  //     {
  //       cout << "T";
  //     }
  //     else
  //     {
  //       cout << "F";
  //     }
  //   }
  //   cout << endl;
  // }
}
