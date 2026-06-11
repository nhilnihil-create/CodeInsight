#include <bits/stdc++.h>
using namespace std;

int main()
{
  int h, w;
  cin >> h >> w;
  vector<string> a(h);

  for (int i = 0; i < h; i++)
  {
    cin >> a.at(i);
  }

  for (int i = -1; i < h + 1; i++)
  {
    for (int j = -1; j < w + 1; j++)
    {
      if (i == -1 || i == h || j == -1 || j == w)
      {
        cout << "#";
      }
      else if (j == 0)
      {
        cout << a.at(i);
      }
    }
    cout << endl;
  }
}
