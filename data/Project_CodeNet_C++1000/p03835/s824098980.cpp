#include <bits/stdc++.h>
using namespace std;

int main()
{
  long long k, s;
  cin >> k >> s;
  long long cnt = 0;
  for (size_t x = 0; x <= k; x++)
  {
    for (size_t y = 0; y <= k; y++)
    {
      if (x + y <= s)
      {
        long long z = s - (x + y);
        if (0 <= z && z <= k)
        {
          if (x != y && y != z && z != x)
          {
            cnt += 1;
          }
          else if (x == y && y == z && z == x)
          {
            cnt += 1;
          }
          else
          {
            cnt += 1;
          }
        }
      }
    }
  }

  cout << cnt << endl;
}
