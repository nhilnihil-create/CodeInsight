#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  cin >> n;
  vector<int64_t> as(n);
  for (int i = 0; i < n; i++)
  {
    cin >> as[i];
  }
  int64_t ans = as[0] / 2;
  as[0] %= 2;
  for (int i = 1; i < n; i++)
  {
    if (as[i - 1] && as[i])
    {
      ans++;
      as[i]--;
    }
    ans += as[i] / 2;
    as[i] %= 2;
  }
  cout << ans << endl;
}