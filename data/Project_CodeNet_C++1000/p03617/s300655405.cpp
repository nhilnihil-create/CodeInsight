#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
  ll q, h, s, d, n;
  cin >> q >> h >> s >> d;
  cin >> n;
  ll a = 8 * q, b = 4 * h, c = s * 2;
  ll e = min(a, min(b, min(c, d)));
  ll f = min(a/2, min(b/2, c/2));
  if (n % 2 == 0)
  {
    cout << n * e / 2;
  }
    else
    {
      cout << ((n - 1) / 2) * e + f;
    }
  }

