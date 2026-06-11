#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, ll> l4;
typedef pair<double, double> dd;
#define mp make_pair
#define pb push_back
#define debug(x) cerr << #x << " = " << x << " "

const int N = 1e5+1;
ll n, a[N], delta[N];
bool solve()
{
  ll sum = 0;
  for (int i = 0; i < n; ++i)
    scanf("%lld", a+i), sum += a[i];
  ll subsum = n * (n + 1) / 2;
  if (sum % subsum) return false;
  ll t = sum / subsum;
  for (int i = 0; i < n; ++i)
    {
      ll delta = a[i] - a[(i+n-1)%n];
      ll x = t - delta;
      if (x < 0 || x % n) return false;
    }
  return true;
}
int main()
{
  while (~scanf("%lld", &n)) puts(solve()?"YES":"NO");
}
