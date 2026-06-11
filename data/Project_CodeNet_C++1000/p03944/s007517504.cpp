#include <bits/stdc++.h>
using namespace std;

int main()
{
  int w, h, n, xs, ys, xe, ye;
  cin >> w >> h >> n;
  vector<int> X(n, 0), Y(n, 0), a(n, 0);

  xs = ys = 0;
  xe = w;
  ye = h;

  for (int i = 0; i < n; i++)
  {
    cin >> X.at(i) >> Y.at(i) >> a.at(i);
  }

  for (int i = 0; i < n; i++)
  {
    switch (a.at(i))
    {
    case 1:
      if (xs < X.at(i))
      {
        xs = X.at(i);
      }
      break;
    case 2:
      if (X.at(i) < xe)
      {
        xe = X.at(i);
      }
      break;
    case 3:
      if (ys < Y.at(i))
      {
        ys = Y.at(i);
      }

      break;
    case 4:
      if (Y.at(i) < ye)
      {
        ye = Y.at(i);
      }

      break;
    default:
      break;
    }
  }
  if (xe < xs || ye < ys)
  {
    cout << 0 << endl;
    return 0;
  }

  cout << (xe - xs) * (ye - ys) << endl;
}
