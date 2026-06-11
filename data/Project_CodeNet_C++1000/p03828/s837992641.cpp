#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  long long sum;
  sum = 1;
  long long cnt[1005] = {0};
  cin >> n;
  for (int i = 2; i <= n; i++)
  {
    int x = i;
    for (int k = 2; k <= x; k++)
    {
      while (x > 0 && x % k == 0)
      {
        cnt[k]++;
        x /= k;
      }
    }
  }
  for (int i = 0; i <= n; i++)
  {
    if (cnt[i] != 0)
    {
      sum *= cnt[i] + 1;
      sum %= (int)(1e9 + 7);
    }
  }

  cout << sum << endl;
}
