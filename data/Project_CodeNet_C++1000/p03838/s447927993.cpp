#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
typedef long long ll;
typedef pair<int, int> P;
const int INF = 100100100;
const int MOD = (int)1e9 + 7;
const double EPS = 1e-9;
int main()
{
  ll x, y;
  cin >> x >> y;
  ll cnt = 0;
  if (x == 0 || y == 0)
  {
    cnt += abs(abs(x) - abs(y));
    if (0 < x || y < 0)
      cnt++;
    cout << cnt << endl;
    return 0;
  }
  int _x = x / abs(x), _y = y / abs(y);
  if (_x == -1 && _y == -1)
  {
    if (x < y)
    {
      cout << abs(abs(x) - abs(y)) << endl;
    }
    else
    {
      cout << abs(abs(x) - abs(y)) + 2 << endl;
    }
  }
  else if (_x == -1 && _y == 1)
  {
    cout << abs(abs(x) - abs(y)) + 1 << endl;
  }
  else if (_x == 1 && _y == -1)
  {
    if (abs(y) < abs(x))
    {
      cout << abs(abs(x) - abs(y)) + 1 << endl;
    }
    else
    {
      cout << abs(abs(x) - abs(y)) + 1 << endl;
    }
  }
  else
  {
    if (x < y)
    {
      cout << y - x << endl;
    }
    else
    {
      cout << x - y + 2 << endl;
    }
  }
}