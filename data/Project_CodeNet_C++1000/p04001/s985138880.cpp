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
  vector<int> a;

  for (int i = 0; i < S.size(); i++) {
    a.push_back(S[i]-'0');
  }

  int ans = 0;
  for (int i = 0; i < 1<<(S.size()-1); i++) {
    int tmp = a[0];
    for (int p = 0; p < S.size()-1; p++) {
      if (i & 1<<p) {
        ans += tmp;
        tmp = a[p+1];
      } else {
        tmp = tmp * 10 + a[p+1];
      }
    }
    ans += tmp;
  }

  cout << ans << endl;
}

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}
