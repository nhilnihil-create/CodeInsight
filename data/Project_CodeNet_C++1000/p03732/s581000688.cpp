#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < n; i++)
#define FOR(i, m, n) for (int i = m; i < n; i++)
#define ll long long int
const int INF = 2147483647;

using namespace std;

int main()
{
  ll w0;
  ll n, W;
  cin >> n >> W;
  vector<vector<ll>> v(4);
  REP(i, n)
  {
    int w;
    ll V;
    cin >> w >> V;
    if (i == 0)
    {
      w0 = w;
    }
    v[w - w0].push_back(V);
  }

  REP(i, 4)
  {
    sort(v[i].begin(), v[i].end(), greater<ll>());
  }

  ll cum[4][101] = {};
  REP(i, 4)
  {
    cum[i][0] = 0;
    FOR(j, 1, v[i].size() + 1)
    {
      cum[i][j] = cum[i][j - 1] + v[i][j - 1];
    }
  }

  ll ans = 0;
  REP(i, v[0].size() + 1)
  {
    REP(j, v[1].size() + 1)
    {
      REP(k, v[2].size() + 1)
      {
        REP(l, v[3].size() + 1)
        {
          if (i * w0 + j * (w0 + 1) + k * (w0 + 2) + l * (w0 + 3) > W)
            continue;
          ans = max(ans, cum[0][i] + cum[1][j] + cum[2][k] + cum[3][l]);
        }
      }
    }
  }
  cout << ans << endl;
}
