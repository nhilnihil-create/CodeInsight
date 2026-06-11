#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  long long n, t, T;
  cin >> n >> T;
  set<pair<long long, long long>> count;
  for (int i = 0; i < n; ++i) {
    cin >> t;
    count.insert({t, 1});
    count.insert({t+T, -1});
  }
  long long res = 0, p, cnt = 0;
  for (auto &c : count) {
    if (c.second == 1) {
      if (cnt == 0) p = c.first;
    } else {
      if (cnt == 1) res += c.first-p;
    }
    cnt += c.second;
  }
  cout << res << endl;

  return 0;
}

