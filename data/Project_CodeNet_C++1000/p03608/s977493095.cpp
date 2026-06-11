#include <bits/stdc++.h>
#define INF 1000000000000000001
#define ll long long
#define pll pair<ll, ll>
using namespace std;

//=============warshall_floyd============================
void  warshall_floyd(ll V, vector<vector<ll>>& d)
{
  for (ll k = 0; k < V; ++k)
  {
    for (ll i = 0; i < V; ++i)
    {
      for (ll j = 0; j < V; ++j)
      {
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
      }
    }
  }
}
//=================================================


int main()
{
  ll N, M, R;
  cin >> N >> M >> R;
  vector<ll> rs(R);
  for (ll i = 0; i < R; ++i)
  {
    ll r;
    cin >> r;
    rs.at(i) = r - 1;
  }
  sort(rs.begin(), rs.end());
  // cout << "rs" << endl;
  // for (ll i = 0; i < R; ++i)
  // {
  //   cout << rs.at(i) << ' ';
  // }
  // cout << endl;
  vector<vector<ll>> dp(N, vector<ll>(N, INF));
  for (ll i = 0; i < N; ++i)
  {
    dp.at(i).at(i) = 0;
  }
  for (ll i = 0; i < M; ++i)
  {
    ll a, b, c;
    cin >> a >> b >> c;
    dp.at(a - 1).at(b - 1) = c;
    dp.at(b - 1).at(a - 1) = c;
  }
  warshall_floyd(N, dp);
  // cout << "wersahr" << endl;
  // for (ll i = 0; i < N; ++i)
  // {
  //   for (ll j = 0; j < N; ++j)
  //   {
  //     cout << dp.at(i).at(j) << ' ';
  //   }
  //   cout << endl;
  // }
  // cout << endl;
  ll ans = INF;
  while (true)
  {
    ll temp = 0;
    for (ll i = 0; i < R - 1; ++i)
    {
      temp += dp.at(rs.at(i)).at(rs.at(i + 1));
    }
    ans = min(ans, temp);
    if (!next_permutation(rs.begin(), rs.end()))
    {
      break;
    }
  }
  cout << ans << endl;
}
