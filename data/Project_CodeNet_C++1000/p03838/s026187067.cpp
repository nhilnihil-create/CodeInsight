#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ll x, y;
  cin >> x >> y;
  vector<ll> d;

  if (x <= y) {
    d.push_back(y - x);
  }
  if (-x <= y) {
    d.push_back(y - (-x) + 1);
  }
  if (x <= -y) {
    d.push_back(-y - x + 1);
  }
  if (-x <= -y) {
    d.push_back(-y - (-x) + 2);
  }
  ll ans = *min_element(d.begin(), d.end());
  cout << ans << endl;
}
