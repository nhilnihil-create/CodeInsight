#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 1e9;
const int MOD = 1e9 + 7;

int main()
{
  int n;
  cin >> n;
  vector<int> p(n);
  for (auto &e : p)
    cin >> e;

  int cnt = 0;
  for (int i = 1; i < n; ++i)
  {
    if (p[i - 1] == i)
    {
      if (p[i] == i + 1)
      {
        p[i] = p[i - 1];
      }
      cnt++;
    }
    if (i == n - 1)
    {
      if (p[i] == i + 1)
      {
        cnt++;
      }
    }
  }
  cout << cnt << endl;

  return 0;
}
