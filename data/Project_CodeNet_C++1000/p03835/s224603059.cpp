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
  int K, S;
  cin >> K >> S;

  int ans = 0;
  for (int x = 0; x <= K; x++) {
    for (int y = 0; y <= K; y++) {
      int z = S-x-y;
      if (0 <= z && z <= K) {
        ans++;
      }
    }
  }
  cout << ans << endl;
}

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}
