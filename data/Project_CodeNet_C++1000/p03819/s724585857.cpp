#include <bits/stdc++.h>

using namespace std;
using int64 = long long;

constexpr int DEBUG = 0;

// Supports two operations.
// - Adds a value to a single element.
// - Returns a sum of a range.
// Verified: CF573Div1D
class BinaryIndexedTree {
 private:
  int n;
  vector<int> xs;
 public:
  BinaryIndexedTree(int n) : n(n), xs(n) {}

  // Adds x to the i-th element.
  void Add(int i, int x) {
    int cur = i;
    while (cur < n) {
      xs[cur] += x;
      cur = cur | (cur + 1);
    }
  }

  // Returns a sum of a range [l r).
  int SumOfRange(int l, int r) {
    if (l >= r) return 0;
    if (l > 0) {
      return SumOfRange(0, r) - SumOfRange(0, l);
    }
    int s = 0;
    int i = r - 1;
    while (i >= 0) {
      s += xs[i];
      i = (i & (i + 1)) - 1;
    }
    return s;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, m;
  cin >> n >> m;
  vector<vector<pair<int, int>>> length_to_segments(m + 1);
  for (int i = 0; i < n; i++) {
    int l, r;
    cin >> l >> r;
    length_to_segments[r + 1 - l].push_back({l, r + 1});
  }

  BinaryIndexedTree bit(m + 1);
  int c = n;
  for (int d = 1; d <= m; d++) {
    for (const auto& segment : length_to_segments[d - 1]) {
      if (DEBUG) cout << segment.first << " " << segment.second << endl;
      bit.Add(segment.first, 1);
      bit.Add(segment.second, -1);
      c--;
    }

    int r = c;
    for (int x = d; x <= m; x += d) {
      r += bit.SumOfRange(0, x + 1);
    }
    cout << r << "\n";
  }
}