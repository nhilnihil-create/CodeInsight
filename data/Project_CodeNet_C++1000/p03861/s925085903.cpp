#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
  ll a, b, x;
  a = b = x = 0;
  cin >> a >> b >> x;

  if (a == 0)
  {
    cout << (b / x) + 1 << endl;
  }
  else
  {
    cout << (b / x) - ((a - 1) / x) << endl;
  }
}
