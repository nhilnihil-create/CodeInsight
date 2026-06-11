#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
typedef long long ll;
using namespace std;
int main()
{
  ll a, b;
  cin >> a >> b;
  if (a > 0 && b >= a)
  {
    cout << "Positive" << endl;
  }
  else if (b >= a && b < 0)
  {
    if ((b - a + 1) % 2 == 0)
    {
      cout << "Positive" << endl;
    }
    else
    {
      cout << "Negative" << endl;
    }
  }
  else
  {
    cout << "Zero" << endl;
  }
  return 0;
}