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

#define int long long

signed main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  int a, b, c, d, e, f, g;
  cin >> a >> b >> c >> d >> e >> f >> g;
  int ans = 0;
  int tk = min(a, min(d, e));
  for (int go = max(0LL, tk - 1); go <= tk; ++go) {
    ans = max(ans, ((a - go) / 2) * 2 + b + 3 * go + ((d - go) / 2) * 2 + ((e - go) / 2) * 2); 
  }
  cout << ans << '\n';
}

