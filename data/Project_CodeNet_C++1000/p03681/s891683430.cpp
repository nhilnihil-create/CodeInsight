#include <bits/stdc++.h>
using namespace std;

int main()
{
  long long n, m, i, j;
  cin >> n >> m;

  if (abs(n - m) > 1)
  {
    cout << 0 << endl;
    return 0;
  }
  long long n1 = n;
  long long m1 = m;

  for (i = n - 1; i >= 1; i--)
  {
    n1 = (n1 * i) % (long long)(1e9 + 7);
  }

  for (j = m - 1; j >= 1; j--)
  {
    m1 = (m1 * j) % (long long)(1e9 + 7);
  }

  if (abs(n - m) == 0)
  {
    cout << (2 * n1 * m1) % (long long)(1e9 + 7) << endl;
  }
  else if (abs(n - m) == 1)
  {
    cout << (n1 * m1) % (long long)(1e9 + 7) << endl;
  }
}
