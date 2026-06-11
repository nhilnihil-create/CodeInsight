#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int F(long a, long b)
{
  string sa = to_string(a);
  string sb = to_string(b);
  return max(sa.size(), sb.size());
}

int main()
{
  long n; cin >> n;
  int minlen = 11;
  for (long i = 1; i < (long)sqrt(n) + 1; i++)
  {
    if (n % i == 0)
    {
      int len = F(i, n / i);
      minlen = min(len, minlen);
    }
  }
  cout << minlen << endl;
}