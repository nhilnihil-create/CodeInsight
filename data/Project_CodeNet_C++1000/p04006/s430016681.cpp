#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <string>
#include <queue>
#include <memory>
#include <deque>
#include <set>
#include <unordered_set>
#include <cmath>
#include <list>
#include <cassert>
#include <cstring>

using namespace std;

using big = long long;

const int N = 20000;

big a[N], b[N];

int main() {
	std::ios_base::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  big ans = 1ll << 60;
  for (int moves = 0; moves < n; ++moves) {
    big s = 1ll * m * moves;
    for (int i = 0; i < n; ++i) {
      s += a[i];
    }
    for (int i = 0; i < n; ++i) {
      b[i] = min(a[i], a[(i + (n - 1)) % n]);
    }
    for (int i = 0; i < n; ++i) {
      a[i] = b[i];
    }
    ans = min(ans, s);
  }
  cout << ans << endl;
}
