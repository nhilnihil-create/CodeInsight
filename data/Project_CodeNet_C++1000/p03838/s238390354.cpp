#include <iostream>

using namespace std;
using ll = long long;

ll labs(ll a)
{
  if (a >= 0) return a;
  else return -a;
}

ll diffabs(ll a, ll b)
{
  if (a >= b) return a - b;
  else return b - a;
}

int main()
{
  ll x, y;
  cin >> x >> y;

  int ans = diffabs(labs(x), labs(y));
  if (x * y > 0 && x > y)
    ans += 2;
  else if (x * y == 0 && x > y)
    ans += 1;
  else if (x * y < 0)
    ans += 1;
  
  cout << ans << endl;
}