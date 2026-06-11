#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n, m;
  cin >> n;
  vector<int> T(n), buf(n);
  for (int i = 0; i < n; i++)
  {
    cin >> T.at(i);
  }
  cin >> m;
  for (int i = 0; i < m; i++)
  {
    int p, x, sum = 0;
    buf = T;
    cin >> p >> x;
    buf.at(p - 1) = x;
    for (int j = 0; j < n; j++)
    {
      sum += buf.at(j);
    }
    cout << sum << endl;
  }
}
