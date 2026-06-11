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
  string S; cin >> S;

  S = S.substr(0, S.size()-1);

  int ans = 0;
  for (int i = 1; i <= S.size()/2; i++) {
    string s = S.substr(0, i);
    s = s+s;
    if (equal(s.begin(), s.end(), S.begin())) {
      ans = s.size();
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
