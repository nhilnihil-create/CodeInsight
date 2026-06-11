#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
  int a, b, c, d;
  cin >> a >> b >> c >> d;

  if (b <= c)
  {
    cout << 0 << endl;
    return 0;
  }
  else if (d <= a)
  {
    cout << 0 << endl;
    return 0;
  }

  if (a <= c && b <= d)
  {
    cout << b - c << endl;
  }
  else if (c <= a && d <= b)
  {
    cout << d - a << endl;
  }
  else if (a <= c && d <= b)
  {
    cout << d - c << endl;
  }
  else if (c <= a && b <= d)
  {
    cout << b - a << endl;
  }
}
