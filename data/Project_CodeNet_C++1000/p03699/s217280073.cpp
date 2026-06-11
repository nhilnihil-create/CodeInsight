#include <cmath>

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

using ll = long long;
using ld = long double;
using vi = vector<int>;

int n;

vi a;

void input() {
  cin >> n;

  a.resize(n);
  for (auto&& i : a)
    cin >> i;
}

void solve() {
  sort(a.begin(), a.end());

  int ans = 0;

  for (auto&& i : a)
    ans += i;

  if (ans % 10 != 0) {
    cout << ans << '\n';

    return;
  }

  bool ok = false;

  for (int j = 0; j < n; ++j) {
    if ((ans - a[j]) % 10 != 0) {
      ans -= a[j];

      ok = true;

      break;
    }
  }

  if (!ok)
    ans = 0;

  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cout.precision(16);
  cout << fixed;

  int _times = 1;

#ifdef _DEBUG
  freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);

  _times = 3;
#endif

  // cin >> _times;

  while (_times--) {
    input();
    solve();
  }
}
