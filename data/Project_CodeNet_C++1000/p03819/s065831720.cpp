#include <bits/stdc++.h>
using namespace std;

struct BinaryIndexedTree {
  BinaryIndexedTree(size_t n) : n(n), v(n + 1, 0) {}

  size_t n;
  vector<int> v;

  int sum(int k) {
    int ret = 0;
    for (; k; k -= k & -k) ret += v[k];
    return ret;
  }

  void add(int k, int x) {
    for (; k <= n; k += k & -k) v[k] += x;
  }
};

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);
  int N, M;
  cin >> N >> M;

  M++;

  vector<pair<int, pair<int, int>>> v(N);
  for (int i = 0; i < N; ++i) {
    int l, r;
    cin >> l >> r;
    v[i].first = r - l + 1;
    v[i].second.first = l;
    v[i].second.second = r;
  }

  sort(v.begin(), v.end());

  int idx = 0;
  BinaryIndexedTree bit(M + 1);
  for (int d = 1; d < M; ++d) {
    while (idx < N && v[idx].first < d) {
      pair<int, int> r = v[idx].second;
      bit.add(r.first, 1);
      bit.add(r.second + 1, -1);
      idx++;
    }

    int ans = N - idx;
    for (int i = d; i < M; i += d) {
      ans += bit.sum(i);
    }

    cout << ans << endl;
  }
}
