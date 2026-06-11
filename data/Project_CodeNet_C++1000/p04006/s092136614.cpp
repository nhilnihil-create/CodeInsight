#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

template<class T> inline bool UpdateMin(T& a, T b) {
  if (a > b) { a = b; return 1; } return 0;
}
template<class T> inline bool UpdateMax(T& a, T b) {
  if (a < b) { a = b; return 1; } return 0;
}

template <typename T>
class SegmentTree {
 private:
  function<T(T, T)> merge_fn;
  T empty_value;
  vector<T> nodes;
  int num_nodes;

  // Returns the fold of overwrap between [node_l, node_r) and [l, r).
  // nodes[node_index] needs to correspond to [node_l, node_r).
  T GetRangeInternal(int node_index, int node_l, int node_r, int l, int r) {
    if (node_r <= l || r <= node_l) return empty_value;
    if (l <= node_l && node_r <= r) return nodes[node_index];
    int node_m = (node_l + node_r) / 2;
    return merge_fn(
        GetRangeInternal(2 * node_index, node_l, node_m, l, r),
        GetRangeInternal(2 * node_index + 1, node_m, node_r, l, r));
  }

 public:
  // Arguments:
  // in_merge: The function to merge two values. It should be a monoid.
  // in_empty_value: The identity of the monoid.
  // xs: The initial values.
  SegmentTree(
      function<T(T, T)> merge_fn, T empty_value, const vector<T>& xs) :
          merge_fn(merge_fn), empty_value(empty_value) {
    int n = xs.size();
    num_nodes = 1;
    while (num_nodes < n) num_nodes *= 2;
    num_nodes *= 2;
    nodes = vector<T>(num_nodes, empty_value);
    for (int i = 0; i < xs.size(); ++i) {
      nodes[num_nodes / 2 + i] = xs[i];
    }
    for (int i = num_nodes / 2 - 1; i >= 1; i--) {
      nodes[i] = merge_fn(nodes[2 * i], nodes[2 * i + 1]);
    }
  }

  // Updates the i-th element to x.
  void Update(int i, T x) {
    nodes[num_nodes / 2 + i] = x;
    for (int cur = (num_nodes / 2 + i) / 2; cur > 0; cur /= 2) {
      nodes[cur] = merge_fn(nodes[2 * cur], nodes[2 * cur + 1]);
    }
  }

  // Returns the value of the range [l, r) merged by merge_fn.
  T GetRange(int l, int r) {
    return GetRangeInternal(1, 0, num_nodes / 2, l, r);
  }

  T Get(int i) {
    return nodes[num_nodes / 2 + i];
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  int64 t;
  cin >> n >> t;
  vector<int64> xs(n);
  for (int i = 0; i < n; i++) {
    cin >> xs[i];
  }

  auto min_fn = [](int64 x, int64 y) { return min(x, y); };
  SegmentTree<int64> tree(min_fn, INT64_MAX, xs);

  int64 ans = INT64_MAX;
  for (int k = 0; k < n; k++) {
    vector<int64> ys = xs;
    for (int i = 0; i < n; i++) {
      int r_inclusive = i;
      int l = i - k;
      if (l >= 0) {
        ys[i] = tree.GetRange(l, r_inclusive + 1);
      }
      if (l < 0) {
        ys[i] = min(
            tree.GetRange(0, r_inclusive + 1),
            tree.GetRange(l + n, n));
      }
    }
    int64 cost = t * k;
    for (int64 y : ys) cost += y;
    UpdateMin(ans, cost);
  }

  cout << ans << endl;
}