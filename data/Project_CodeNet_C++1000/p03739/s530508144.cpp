#include <bits/stdc++.h>
#define INF 1000000000000000001
#define ll long long
#define pll pair<ll, ll>
using namespace std;



int main()
{
  ll N;
  cin >> N;
  vector<ll> a(N);
  for (ll i = 0; i < N; ++i)
  {
    cin >> a.at(i);
  }
  ll ans = 0;
  ll S = 0;
  for (ll i = 0; i < N; ++i)
  {
    S += a.at(i);
    if (i % 2 == 0)
    {
      if (S > 0)
      {
        continue;
      }
      else
      {
        ans += 1 - S;
        S = 1;
      }
    }
    else
    {
      if (S < 0)
      {
        continue;
      }
      else
      {
        ans += 1 + S;
        S = -1;
      }
    }
  }

  ll ans2 = 0;
  ll S2 = 0;
  for (ll i = 0; i < N; ++i)
  {
    S2 += a.at(i);
    if (i % 2 == 1)
    {
      if (S2 > 0)
      {
        continue;
      }
      else
      {
        ans2 += 1 - S2;
        S2 = 1;
      }
    }
    else
    {
      if (S2 < 0)
      {
        continue;
      }
      else
      {
        ans2 += 1 + S2;
        S2 = -1;
      }
    }
  }
  ans = min(ans, ans2);
  cout << ans << endl;
}
