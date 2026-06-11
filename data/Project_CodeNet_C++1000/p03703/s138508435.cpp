#include <bits/stdc++.h>

using namespace std;
using int64 = long long;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
template<class T, class C> using pbds_tree =
    tree<T, null_type, C, rb_tree_tag, tree_order_statistics_node_update>;

constexpr int DEBUG = 0;

// Returns a vector of cumulative sums.
// Let c_sums be the return value.
// - c_sums[k] is the sum of xs over [0, k).
// - c_sums[r] - c_sums[l] is the xum of xs over [l, r).
template<class T> vector<T> CumulativeSumVector(const vector<T>& xs) {
  int n = xs.size(); vector<T> c_sums(n + 1);
  for (int i = 0; i < n; i++) c_sums[i + 1] = c_sums[i] + xs[i];
  return c_sums;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  int64 k;
  cin >> n >> k;
  vector<int64> xs(n);
  for (int i = 0; i < n; i++) {
    cin >> xs[i];
    xs[i] -= k;
  }
  auto c_sums = CumulativeSumVector(xs);
  
  pbds_tree<pair<int64, int>, less<pair<int64, int>>> tree;
  for (int i = 1; i <= n; i++) {
    tree.insert(make_pair(c_sums[i], i));
  }

  int64 ans = 0;
  ans += tree.size() - tree.order_of_key(make_pair(0, -1));
  if (DEBUG) cout << "ans: " << ans << endl;
  for (int i = 1; i <= n; i++) {
    tree.erase(make_pair(c_sums[i], i));
    ans += tree.size() - tree.order_of_key(make_pair(c_sums[i], -1));
    if (DEBUG) cout << "ans: " << ans << endl;
  }
  cout << ans << endl;
}