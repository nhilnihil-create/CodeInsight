#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  int ans = 10000000;
  cin >> n;
  vector<int> a(n);

  for (int i = 0; i < n; i++)
  {
    cin >> a.at(i);
  }

  for (int i = -100; i <= 100; i++)
  {
    int buf = 0;
    for (int j = 0; j < n; j++)
    {
      buf += pow((i + a.at(j)), 2.0);
    }
    ans = min(ans, buf);
  }
  cout << ans << endl;
}
