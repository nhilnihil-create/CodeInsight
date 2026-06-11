#include <iostream>

typedef long long ll;

using namespace std;

ll gcd(ll a, ll b)	{
  if (b == 0)	{
    return a;
  }
  return gcd(b, a % b);
}

ll lcm(ll a, ll b)	{
  return a / gcd(a, b) * b;
}

int main()	{
  ll n;
  cin >> n;
  ll a[n] = {0};
  for (int i = 0; i < n; i++)	{
    cin >> a[i];
  }
  ll ans = 1;
  for (int i = 0; i < n; i++)	{
    ans = lcm(ans, a[i]);
  }
  cout << ans << endl;
  return 0;
}