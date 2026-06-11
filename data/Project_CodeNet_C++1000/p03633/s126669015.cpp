#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b)
{
  if (b == 0)
    return a;
  return gcd(b, a % b);
}

ll lcm(ll a, ll b)
{
  ll g = gcd(a, b);
  return (a / g) * b;
}

int main()
{
  int n;
  cin >> n;
  ll t, ans = 1LL;
  for (int i = 0; i < n; i++)
  {
    cin >> t;
    ans = lcm(ans, t);
  }

  cout << ans << endl;
}
