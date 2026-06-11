#include <cmath>

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

using ll = long long;
using ld = long double;
using vi = vector<int>;

ll n;
ll m;

void input() {
  cin >> n >> m;
}

bool check(ll x) {
  ll a = n;
  ll b = m;

  ll need = x - a;

  if (need > 0) {
    b -= need * 2;

    if (b <= 0)
      return true;
  }

  return b / 2 < x;
}

void solve() {
  ll l = 0;
  ll r = 1e18;

  while (r - l > 1) {
    ll mid = (l + r) / 2;

    if (check(mid))
      r = mid;
    else
      l = mid;
  }

  cout << l << '\n';
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

  _times = 2;
#endif

  // cin >> _times;

  while (_times--) {
    input();
    solve();
  }
}
