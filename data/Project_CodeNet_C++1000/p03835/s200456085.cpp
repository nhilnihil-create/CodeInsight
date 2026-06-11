#include <cmath>

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

using ll = long long;
using ld = long double;
using vi = vector<int>;

int k;
int s;

void input() {
  cin >> k >> s;
}

void solve() {
  int ans = 0;

  for (int i = 0; i < k + 1; ++i) {
    for (int j = 0; j < k + 1; ++j) {
      int val = s - (i + j);
      
      if (val > -1 && val < k + 1)
        ++ans;
    }
  }

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

  _times = 2;
#endif

  // cin >> _times;

  while (_times--) {
    input();
    solve();
  }
}
