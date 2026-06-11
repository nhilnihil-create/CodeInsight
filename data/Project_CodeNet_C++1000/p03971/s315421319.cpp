#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <tuple>
#include <unordered_map>
#include <vector>
using namespace std;
using ll = int64_t;
#define rep(i, j, n) for (int i = j; i < (int)n; ++i)

int main() {
  int n, a, b;
  cin >> n >> a >> b;
  string s;
  cin >> s;

  int x = 0, y = 0;
  vector<string> ans(n);
  rep(i, 0, n) {
    if (s[i] == 'a' && x < a + b) {
      ++x;
      ans[i] = "Yes";
    } else if (s[i] == 'b' && x < a + b && y < b) {
      ++x;
      ++y;
      ans[i] = "Yes";
    } else
      ans[i] = "No";
  }
  rep(i, 0, n) cout << ans[i] << '\n';
  return 0;
}