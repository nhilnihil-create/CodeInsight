#include <iostream>
#include <algorithm>

using namespace std;

#define ll long long

ll f[1000001], p[1000001];
ll n;

const ll mod = 1000000007;

int main ()
{
  ios_base::sync_with_stdio (0);
  cin >> n;
  for (int i=1; i <= n; ++ i) f[i] = p[i] = 0;
  f[1] = p[1] = n;
  f[2] = n*n%mod;
  p[2] = (p[1] + f[2]) % mod;
  for (int i = 3; i <= n; i++)
    {
      f[i] = f[i - 1];
      f[i] += (n-1) * (n-1);
      f[i] += p[i-3];
      f[i] += n-i+2;
      f[i] %= mod;
      p[i] = (f[i] + p[i - 1]) % mod;
    }
  cout << f[n];
  return 0;
}
