#include <bits/stdc++.h>
using namespace std;

int main()
{
  int w, h, n;
  cin >> w >> h >> n;
  vector<vector<int>> a(n, vector<int>(3));
  for (int i = 0; i < n; i++)
  {
    for (int k = 0; k < 3; k++)
    {
      cin >> a.at(i).at(k);
    }
  }
  int x_max, x_min, y_max, y_min;
  x_max = w;
  x_min = 0;
  y_max = h;
  y_min = 0;

  for (int i = 0; i < n; i++)
  {
    if (a.at(i).at(2) == 1 && x_min < a.at(i).at(0))
    {
      x_min = a.at(i).at(0);
    }
    if (a.at(i).at(2) == 2 && x_max > a.at(i).at(0))
    {
      x_max = a.at(i).at(0);
    }
    if (a.at(i).at(2) == 3 && y_min < a.at(i).at(1))
    {
      y_min = a.at(i).at(1);
    }
    if (a.at(i).at(2) == 4 && y_max > a.at(i).at(1))
    {
      y_max = a.at(i).at(1);
    }
  }
  if (x_max > x_min && y_max > y_min)
  {
    int ans = abs(x_max - x_min) * abs(y_max - y_min);
    cout << ans << endl;
  }
  else
  {
    cout << 0 << endl;
    return 0;
  }
}
