#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
  int n, m;
  cin >> n >> m;
  vector<int> s(n, 0);
  vector<int> e(n, 0);
  for (int i = 0; i < m; i++)
  {
    int a, b;
    cin >> a >> b;
    if (a == 1)
    {
      s.at(b) = 1;
    }
    if (b == n)
    {
      e.at(a) = 1;
    }
  }

  for (int i = 2; i < n; i++)
  {
    if (s.at(i) && e.at(i))
    {
      cout << "POSSIBLE" << endl;
      return 0;
    }
  }

  cout << "IMPOSSIBLE" << endl;
}
