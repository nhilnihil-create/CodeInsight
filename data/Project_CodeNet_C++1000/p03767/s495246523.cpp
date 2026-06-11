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
#include <bitset>

using namespace std;

typedef long long ll;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  int n;
  cin >> n;
  vector <int> a(3 * n);
  for (int i = 0; i < 3 * n; ++i) cin >> a[i];
  sort(a.begin(), a.end());
  ll ans = 0;
  for (int i = 0; i < n; ++i) {
    a.pop_back();
    ans += a.back();
    a.pop_back();
  }
  cout << ans << '\n';
}
