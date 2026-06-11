#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
using namespace std;

int64_t gcd(int64_t a, int64_t b) {
  if (b == 0)
    return a;
  return gcd(b, a % b);
}

bool solve(vector<int64_t> &as) {
  int64_t rem = 0;
  int64_t odds = 0;

  int64_t mi = as[0];
  for (auto &a : as) {
    rem += a - 1;
    if (a % 2 == 1)
      odds++;

    mi = min(mi, a);
  }
  bool win = rem % 2 == 1;

  if (mi > 1 && odds == 1) {
    int g = 0;
    for (auto &a : as) {
      g = gcd(g, a / 2 * 2);
    }
    for (auto &a : as) {
      a /= g;
    }
    win |= !solve(as);
  }

  return win;
}

int main() {
  cin.tie(0);
  int n;
  cin >> n;

  vector<int64_t> as(n);
  for (auto &a : as)
    cin >> a;

  cout << (solve(as) ? "First" : "Second") << endl;

  return 0;
}