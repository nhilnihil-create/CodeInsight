#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int bigger(ll a, ll b)
{
  int pA, pB;
  pA = pB = 1;
  while (1)
  {
    if (a / 10 <= 0)
    {
      break;
    }
    pA++;
    a /= 10;
  }
  while (1)
  {
    if (b / 10 <= 0)
    {
      break;
    }
    pB++;
    b /= 10;
  }
  return max(pA, pB);
}

int main()
{
  ll n, ans = 100000, buf = 0;
  cin >> n;
  ll sqrt = pow(n, 0.5);
  for (ll i = 1; i < sqrt + 1; i++)
  {
    if (n % i == 0)
    {
      buf = bigger(i, n / i);
      ans = min(ans, buf);
    }
  }
  cout << ans << endl;
}
