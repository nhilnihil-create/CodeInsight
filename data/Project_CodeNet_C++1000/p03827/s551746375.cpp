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

void solve() {
  int N;
  string S;
  cin >> N >> S;

  int ans = 0;
  int x = 0;

  for (char c:S) {
    if (c == 'I') {
      x++;
    } else {
      x--;
    }

    ans = max(ans, x);
  }
  cout << ans << endl;
}

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}
