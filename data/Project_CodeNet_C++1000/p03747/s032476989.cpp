#include <iostream>
#include <cmath>
#include <iomanip>
#include <algorithm>
#include <map>
#include <string>
#include <cstring>
#include <vector>
using namespace std;

#define i64 int64_t
void agc13c()
{
  i64 n, l, t;
  cin >> n >> l >> t;
  i64 x[n], w[n];
  i64 ans[n];
  i64 count = 0;
  for (i64 i = 0; i < n; i++)
  {
    cin >> x[i] >> w[i];
    if (w[i] == 1)
      ans[i] = (x[i] + t) % l;
    else
      ans[i] = ((x[i] - t) + t * l) % l;
  }
  for (i64 i = 1; i < n; i++)
  {
    if (w[0] != w[i])
    {
      if (w[0] == 1)
      {
        if (2 * t - (x[i] - x[0] - 1) < 0)
          continue;
        else
          count += 1 + (2 * t - (x[i] - x[0])) / l;
      }
      else
      {
        if (2 * t - l + (x[i] - x[0] + 1) < 0)
          continue;
        else
          count += 1 + (2 * t - l + (x[i] - x[0])) / l;
      }
      count = count % n;
    }
  }
  if (w[0] == 2)
  {
    count = (n - count) % n;
  }

  i64 ans_f = ans[0];
  sort(ans, ans + n);
  i64 index = 0;
  for (i64 i = 0; i < n; i++)
  {
    if (ans[i] == ans_f)
    {
      index = i;
      if (w[0] == 2)
        break;
    }
  }
  i64 res[n];
  for (i64 i = 0; i < n; i++)
  {
    res[(count + i) % n] = ans[(index + i) % n];
  }
  for (i64 i = 0; i < n; i++)
    cout << res[i] << endl;
}

int main(void)
{
  agc13c();
  return 0;
}
