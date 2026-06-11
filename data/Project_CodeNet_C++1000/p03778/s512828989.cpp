#include <bits/stdc++.h>
#define rep(i, f, n) for (ll i = (f); i < (ll)(n); i++)
#define repe(i, f, n) for (ll i = (f); i <= (ll)(n); i++)
using namespace std;
using ll = long long;
using pint = pair<int, int>;

int main() {
  int W, a, b;
  cin >> W >> a >> b;

  int x = min(a, b);
  int y = max(a, b);
  if (x + W >= y)
    cout << 0 << endl;
  else
    cout << y - (W + x) << endl;

  return 0;
}
