#include <algorithm>
#include <cstring>
#include <deque>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <vector>
using namespace std;
using ll = long long;

struct Enclosure {
  int l, r, len;
  Enclosure(int l_, int r_) : l(l_), r(r_), len(r_ - l_ + 1) {}
  bool operator<(const Enclosure& other) const { return len < other.len; }
};

template <class T>
struct fenwick_tree {
  vector<T> x;
  fenwick_tree(int n) : x(n, 0) {}
  T sum(int i, int j) {
    if (i == 0) {
      T S = 0;
      for (; j >= 0; j = (j & (j + 1)) - 1) S += x[j];
      return S;
    } else
      return sum(0, j) - sum(0, i - 1);
  }
  void add(int k, T a) {
    for (; k < x.size(); k |= k + 1) x[k] += a;
  }
};

int main() {
  int N, M;
  while (cin >> N >> M) {
    vector<Enclosure> enclosures;
    for (int i = 0; i < N; i++) {
      int l, r;
      cin >> l >> r;
      enclosures.emplace_back(Enclosure(l, r));
    }
    sort(enclosures.begin(), enclosures.end());
    fenwick_tree<int> ft(M + 10);
    int k = 0;
    for (int d = 1; d <= M; d++) {
      while (k < N && enclosures[k].len < d) {
        ft.add(enclosures[k].l, +1);
        ft.add(enclosures[k].r + 1, -1);
        ++k;
      }
      int ans = N - k;
      for (int p = 0; p <= M; p += d) {
        ans += ft.sum(0, p);
      }
      cout << ans << endl;
    }
  }
  return 0;
}
