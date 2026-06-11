// ABC_052_A

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main()
{
  int a, b, c, d;
  cin >> a >> b >> c >> d;

  if ((a*b) <= (c*d)) cout << c * d << "\n";
  else cout << a * b << "\n";

  return 0;
}
