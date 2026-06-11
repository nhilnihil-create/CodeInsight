#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main()
{
  ll w, a, b, ans;
  cin >> w >> a >> b;

  if (b > a + w)
  {
    ans = b - (a + w);
  }
  else if (a > b + w)
  {
    ans = a - (b + w);
  }
  else
  {
    cout << 0 << endl;
    return 0;
  }
  cout << ans << endl;
}
