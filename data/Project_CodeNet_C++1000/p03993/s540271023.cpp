#include <bits/stdc++.h>

#define REP(i, x) REPI(i, 0, x)
#define REPI(i, a, b) for (int i = int(a); i < int(b); ++i)
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N;
  cin >> N;
  map<pair<int, int>, int> count;
  int a;
  REPI(i, 1, N + 1) {
    cin >> a;
    pair<int, int> key = make_pair(min(i, a), max(i, a));
    if (count.find(key) == count.end()) {
      count.insert(make_pair(key, 1));
    } else {
      ++count.at(key);
    }
  }

  int ans = 0;
  for (auto const &it : count) {
    if (it.second == 2) {
      ++ans;
    }
  }

  cout << ans << endl;

  return 0;
}
