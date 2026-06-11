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

  int K;
  cin >> K;

  for (char &c : s) {
    int d = c - 'a';
    if (d > 0 && 26 - d <= K) {
      c = 'a';
      K -= 26 - d;
    }
  }

  K %= 26;
  int d = s.back() - 'a';
  d = (d + K) % 26;
  s.back() = 'a' + d;

  cout << s << endl;

  return 0;
}