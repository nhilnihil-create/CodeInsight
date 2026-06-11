#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main()
{
  ll n, p;
  p = 1;
  cin >> n;

  for (ll i = 1; i <= n; i++)
  {
    if (p > (ll)(1e9 + 7))
    {
      p %= (ll)(1e9 + 7);
    }

    p *= i;
  }
  cout << p % (ll)(1e9 + 7) << endl;
}
