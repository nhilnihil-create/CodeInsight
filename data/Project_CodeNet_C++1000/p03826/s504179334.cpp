#include <bits/stdc++.h>
using namespace std;
int main()
{
  int a, b, c, d;
  cin >> a >> b >> c >> d;

  int s, t;
  s = a * b;
  t = c * d;

  if (s >= t) {
    cout << s << endl;
  } else {
    cout << t << endl;
  }

  return 0;
}