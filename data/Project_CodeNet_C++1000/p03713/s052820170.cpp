#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll solve(ll h, ll w) {
  if (h % 3 == 0 || w % 3 == 0) {
    return 0;
  } else {
    ll a, b, c;
    a = h * (w / 3) + (w % 3 == 2) * h;
    b = (h / 2) * ((2 * (w / 3)) + 1);
    c = (h / 2 + h % 2) * ((2 * (w / 3)) + 1);
    return max(max(abs(a - b), abs(a - c)), abs(b - c));
  }
}
int main() {
  ll h, w;
  cin >> h >> w;
  if (h == w)
    cout << min(h, solve(h, w)) << endl;
  else
    cout << min(min(h, w), min(solve(h, w), solve(w, h))) << endl;
}
