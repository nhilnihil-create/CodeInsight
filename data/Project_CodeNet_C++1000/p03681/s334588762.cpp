#include <iostream>
#include <cmath>
#include <cstdlib>
#include <algorithm>

using namespace std;

#define MOD 1000000007

long long fact(long long x)	{
  long long r = 1;
  for (long long i = 1; i <= x; i++)	{
    r = (r * i) % MOD;
  }
  return (r % MOD);
}

int main()	{
  long long m, d;
  cin >> m >> d;
  if (abs(m - d) >= 2)	{
    cout << 0 << endl;
    return 0;
  }
  else if (m == d) {
    cout << ((2) * ((fact(m) % MOD) * (fact(d) % MOD) % MOD)) % MOD << endl;
  }
  else if (m == d + 1 || d == m + 1)	{
    cout << ((fact(m) % MOD) * (fact(d) % MOD)) % MOD << endl;
  }
  return 0;
}
