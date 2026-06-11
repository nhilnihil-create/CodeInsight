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
int a;
int b;

void input() {
  cin >> n >> a >> b;
}

void solve() {
  ll ans = 1 + 1ll * (n - 2) * (b - a);

  if (a > b || (n == 1 && a != b))
    ans = 0;

  if (n ==  1 && a == b)
    ans = 1;

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

  _times = 4;
#endif

  // cin >> _times;

  while (_times--) {
    input();
    solve();
  }
}
