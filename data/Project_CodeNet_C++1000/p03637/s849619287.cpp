#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
  ll n, even, odd, four;
  even = odd = four = 0;
  cin >> n;
  vector<ll> a(n);
  for (ll i = 0; i < n; i++)
  {
    cin >> a.at(i);
    if (a.at(i) % 4 == 0)
    {
      four++;
    }
    else if (a.at(i) % 2 == 0)
    {
      even++;
    }
    else
    {
      odd++;
    }
  }
  if (four + 1 == odd && four + odd == n)
  {
    cout << "Yes" << endl;
  }
  else if (four < odd)
  {
    cout << "No" << endl;
  }
  else
  {
    cout << "Yes" << endl;
  }
}
