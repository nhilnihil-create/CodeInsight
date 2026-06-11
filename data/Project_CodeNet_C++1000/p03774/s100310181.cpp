#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
  ll n, m;
  cin >> n >> m;
  vector<vector<ll>> S(n, vector<ll>(2));
  vector<vector<ll>> P(m, vector<ll>(2));

  for (int i = 0; i < n; i++)
  {
    ll a, b;
    cin >> a >> b;
    S.at(i).at(0) = a;
    S.at(i).at(1) = b;
  }
  for (int i = 0; i < m; i++)
  {
    ll c, d;
    cin >> c >> d;
    P.at(i).at(0) = c;
    P.at(i).at(1) = d;
  }

  for (int i = 0; i < n; i++)
  {
    ll man = 200000000;
    ll ans = m;
    for (int j = 0; j < m; j++)
    {
      ll d = abs(S.at(i).at(0) - P.at(j).at(0)) + abs(S.at(i).at(1) - P.at(j).at(1));
      if (man > d)
      {
        ans = j + 1;
      }
      man = min(man, d);
    }
    cout << ans << endl;
  }
}
