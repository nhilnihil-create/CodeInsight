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

void input() {
  cin >> n;
}

void solve() {
  int ans = 1;

  while (ans <= n)
    ans *= 2;

  cout << ans / 2 << '\n';
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
