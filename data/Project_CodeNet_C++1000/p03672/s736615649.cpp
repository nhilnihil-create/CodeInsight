#include <algorithm>
#include <cmath>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <queue>
#include <set>
#include <tuple>
#include <vector>

using namespace std;

#define rep(i, n) for (int64_t i = 0; i < (int64_t)(n); i++)
#define irep(i, n) for (int64_t i = 0; i <= (int64_t)(n); i++)
#define rrep(i, n) for (int64_t i = (n)-1; i >= 0; i--)
#define rirep(i, n) for (int64_t i = n; i >= 0; i--)

int main() {
  string s;
  cin >> s;

  rrep(i, s.size()) {
    bool c = true;
    rep(j, i / 2) { c = c && (s[j] == s[j + i / 2]); }
    if (c) {
      cout << i / 2 * 2 << endl;
      return 0;
    }
  }
  return 0;
}