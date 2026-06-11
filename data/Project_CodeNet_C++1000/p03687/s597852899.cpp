#include <algorithm>
#include <bitset>
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
  s.push_back('.');

  int result = s.size();
  rep(i, 26) {
    char c = i + 'a';
    s.back() = c;
    int len = 0;
    int cost = 0;
    for (char p : s) {
      if (p == c) {
        cost = max(cost, len);
        len = 0;
      } else {
        len++;
      }
    }
    result = min(result, cost);
  }
  cout << result << endl;

  return 0;
}