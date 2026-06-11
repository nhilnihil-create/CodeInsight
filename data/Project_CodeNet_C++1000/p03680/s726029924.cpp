#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n, now = 0;
  long long cnt = 1;
  long long max = 100000;
  cin >> n;
  vector<int> V(n);
  for (int i = 0; i < n; i++)
  {
    cin >> V.at(i);
  }
  while (max)
  {
    if (V.at(now) == 2)
    {
      cout << cnt << endl;
      return 0;
    }
    cnt++;
    now = V.at(now) - 1;
    max--;
  }
  cout << -1 << endl;
}
