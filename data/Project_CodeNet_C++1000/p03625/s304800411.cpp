#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
  ll n, x, y;
  x = y = 0;
  cin >> n;
  vector<ll> a(n);
  for (ll i = 0; i < n; i++)
  {
    cin >> a.at(i);
  }
  sort(a.begin(), a.end());

  bool flag = true;

  for (ll i = n - 1; i > 1; i--)
  {
    if (a.at(i - 1) == a.at(i - 2) && !flag)
    {
      y = a.at(i - 1);
      break;
    }

    if (a.at(i) == a.at(i - 1) && flag)
    {
      x = max(x, a.at(i - 1));
      flag = false;
    }
  }
  cout << x * y << endl;
}
