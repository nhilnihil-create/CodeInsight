#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
  ll n, limit = 100005;
  cin >> n;
  ll a;
  vector<ll> m(limit);
  for (ll i = 0; i < n; i++)
  {
    cin >> a;
    m.at(a + 1)++;
    if (a != 0)
    {
      m.at(a - 1)++;
    }
    m.at(a)++;
  }
  ll ans = 0;
  for (ll i = 0; i < limit; i++)
  {
    ans = max(ans, m.at(i));
  }
  cout << ans << endl;
}
