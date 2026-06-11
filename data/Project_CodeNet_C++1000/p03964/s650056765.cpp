#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <vector>
#define rep(i, f, n) for (ll i = (f); i < (ll)(n); i++)
#define repe(i, f, n) for (ll i = (f); i <= (ll)(n); i++)
using namespace std;
using ll = long long;
using pint = pair<int, int>;

int main() {
  int n;
  cin >> n;
  vector<ll> a(n), b(n);
  rep(i, 0, n) cin >> a[i] >> b[i];

  ll num = 1, x = a[0], y = b[0];
  rep(i, 1, n) {
    num = max((a[i - 1] * num + a[i] - 1) / a[i],
              (b[i - 1] * num + b[i] - 1) / b[i]);
    x = a[i] * num;
    y = b[i] * num;
  }

  cout << x + y << endl;

  return 0;
}
