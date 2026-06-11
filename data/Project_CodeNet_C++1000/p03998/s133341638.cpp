#include <bits/stdc++.h>
using namespace std;

int main()
{
  string a, b, c;
  cin >> a >> b >> c;
  char s = a[0];
  a.erase(0, 1);
  if (a.length() == 0)
  {
    cout << 'A' << endl;
    return 0;
  }

  while (1)
  {
    if (s == 'a')
    {
      if (a.length() == 0)
      {
        cout << 'A' << endl;
        break;
      }
      s = a[0];
      a.erase(0, 1);
    }
    else if (s == 'b')
    {
      if (b.length() == 0)
      {
        cout << 'B' << endl;
        break;
      }
      s = b[0];
      b.erase(0, 1);
    }
    else if (s == 'c')
    {
      if (c.length() == 0)
      {
        cout << 'C' << endl;
        break;
      }
      s = c[0];
      c.erase(0, 1);
    }
  }
}
