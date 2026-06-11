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
  string S;
  cin >> S;

  sort(S.begin(), S.end());
  for (int i = 0; i < S.size() - 1; i++) {
    if (S[i] == S[i+1]) {
      cout << "no" << endl;
      return;
    }
  }
  cout << "yes" << endl;
}

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}
