#include <algorithm>
#include <climits>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <vector>

#define int long long int
constexpr int INF = std::numeric_limits<int>::max();
constexpr int NINF = std::numeric_limits<int>::min();
using namespace std;

bool contain(const string &S, char c) {
  for (char s: S) {
    if (s == c) {
      return true;
    }
  }
  return false;
}

void solve() {
  string S;
  cin >> S;

  for (char c = 'a'; c <= 'z'; c++) {
    if (!contain(S, c)) {
      cout << c << endl;
      return;
    }
  }
  cout << "None" << endl;
}

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}
