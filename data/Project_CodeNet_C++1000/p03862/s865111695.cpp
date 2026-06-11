#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
  int n, x;
  ll ans = 0;
  cin >> n >> x;
  vector<ll> a(n);
  for (int i = 0; i < n; i++)
  {
    cin >> a.at(i);
  }

  if (a.at(0) > x)
  {
    ans += a.at(0) - x;
    a.at(0) = x;
  }

  for (int i = 1; i < n; i++)
  {
    if (a.at(i - 1) + a.at(i) > x)
    {
      ans += a.at(i - 1) + a.at(i) - x;
      a.at(i) -= a.at(i) - x + a.at(i - 1);
    }
  }
  cout << ans << endl;
}
