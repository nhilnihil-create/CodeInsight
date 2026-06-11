#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <queue>
#include <set>
#include <unordered_map>
#include <vector>
using namespace std;
using ll = int64_t;
#define rep(i, j, n) for (int i = j; i < (int)n; ++i)

int main() {
  int n;
  cin >> n;
  int a;
  unordered_map<int, int> mp;
  rep(i, 0, n) {
    cin >> a;
    mp[a]++;
    mp[a - 1]++;
    mp[a + 1]++;
  }
  int ans = 0;
  for (auto m : mp) ans = max(ans, m.second);
  cout << ans << endl;
  return 0;
}
