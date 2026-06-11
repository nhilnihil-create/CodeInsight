#include <bits/stdc++.h>

using namespace std;
using int64 = long long;

constexpr int DEBUG = 0;

template<typename T> ostream& operator<<(ostream& s, const vector<T>& v) {
  int len = v.size();
  s << "[";
  for (int i = 0; i < len; i++) {
    if (i > 0) s << ", ";
    s << v[i];
  }
  s << "]";
  return s;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;
  vector<pair<int, int64>> xs;
  int64 total_sum = 0;
  for (int i = 0; i < n; i++) {
    int64 x;
    cin >> x;
    xs.push_back({i, x});
    total_sum += x;
  }
  sort(xs.begin(), xs.end(), [](const auto& p1, const auto& p2) {
    if (p1.second != p2.second) return p1.second > p2.second;
    return p1.first < p2.first;
  });

  vector<int64> rs(n);

  int index = xs[0].first;
  if (index == 0) {
    rs[0] = total_sum;
  } else {
    int64 sum = xs[0].second;
    int64 used = 0;
    for (int i = 1; i < n; i++) {
      const auto& p = xs[i];
      if (DEBUG) cout << p.first << " " << p.second << endl;
      if (p.first < index) {
        rs[index] = sum - (p.second * i) - used;
        used += rs[index];
        index = p.first;
        // cout << rs << endl;
        if (index == 0) {
          rs[0] = total_sum - used;
          break;
        }
      }
      sum += p.second;
    }
  }

  for (int i = 0; i < n; i++) {
    cout << rs[i] << "\n";
  }
}