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

void solve();

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}

void solve() {
  string A, B;
  cin >> A >> B;

  if (A.size() > B.size()) {
    cout << "GREATER" << endl;
  } else if (A.size() < B.size()) {
    cout << "LESS" << endl;
  } else if (A > B) {
    cout << "GREATER" << endl;
  } else if (A < B) {
    cout << "LESS" << endl;
  } else {
    cout << "EQUAL" << endl;
  }
}
