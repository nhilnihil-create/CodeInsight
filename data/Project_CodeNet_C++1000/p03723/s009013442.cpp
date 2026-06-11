#include <algorithm>
#include <climits>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <vector>

#define int long long int
constexpr int INF = std::numeric_limits<int>::max();
constexpr int NINF = std::numeric_limits<int>::min();
using namespace std;

bool odd(vector<int> &v) {
  for (auto &a: v) {
    if (a %2 == 1) {
      return true;
    }
  }
  return false;
}

void solve() {
  vector<int> v(3), w(3);
  cin >> v[0] >> v[1] >> v[2];

  int ans = 0;
  while (true) {
    if (odd(v)) {
      break;
    }

    if (v[0] == v[1] && v[1] == v[2]) {
      ans = -1;
      break;
    }

    for (int i = 0; i < 3; i++) {
      w[(i + 1)%3] += v[i]/2;
      w[(i + 2)%3] += v[i]/2;
    }

    ans++;
    v = w;
    w = vector<int>(3);
  }

  cout << ans << endl;
}

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}
