#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <random>
#include <iomanip>
#include <functional>
#include <cassert>

using namespace std;

typedef long long ll;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  int n;
  cin >> n;
  n = 2 * n - 1;
  vector <int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  auto get = [&] (int x) {
    vector <int> b(n);
    for (int i = 0; i < n; ++i) {
      if (a[i] >= x) b[i] = 1;
      else b[i] = 0;
    }
    int p = n / 2;
    int cnt_l = 0, cnt_r = 0;
    for (int i = p - 1; i >= 0; --i) {
      if (b[i] != b[i + 1]) {
        ++cnt_l;
      } else {
        break;
      }
    }
    for (int i = p + 1; i < n; ++i) {
      if (b[i] != b[i - 1]) {
        ++cnt_r;
      } else {
        break;
      }
    }
    int c = min(cnt_l, cnt_r) % 2;
    return b[p] ^ c;
  };
  int l = 0, r = n;
  while (r - l > 1) {
    int m = (l + r) >> 1;
    if (get(m) == 1) l = m;
    else r = m;
  }
  cout << l << '\n';
}

