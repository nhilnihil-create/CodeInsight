#include <bits/stdc++.h>
using namespace std;

// 0-indexed
template <class T>
struct BIT {
  int treesize;
  vector<T> lst;
  // constructor
  BIT(int newn = 0) : treesize(newn), lst(newn + 1, 0) {}
  // a_place += num
  void add(int place, T num) {
    ++place;
    while (place <= treesize) {
      lst[place] += num;
      place += place & -place;
    }
  }
  // sum between [0,place)
  T sum(int place) {
    T res = 0;
    while (place > 0) {
      res += lst[place];
      place -= place & -place;
    }
    return res;
  }
  // sum [l,r)
  T sum(int left, int right) { return sum(right) - sum(left); }
};

using P = pair<int, int>;

int n, m;
vector<int> res;
vector<P> v;
BIT<int> bit;

void solve();

int main() {
  cin >> n >> m;
  v.resize(n);
  for (int i = 0; i < n; ++i) {
    cin >> v[i].first >> v[i].second;
    ++v[i].second;
  }
  sort(v.begin(), v.end(),
       [](P l, P r) { return (l.second - l.first) < (r.second - r.first); });
  bit = BIT<int>(m + 2);
  solve();
  for (auto p : res) cout << p << endl;
  return 0;
}

void solve() {
  for (int i = 1, id = 0; i <= m; ++i) {
    int now = 0;
    while (id < n && i > v[id].second - v[id].first) {
      bit.add(v[id].first, 1);
      bit.add(v[id].second, -1);
      ++id;
    }
    now = n - id;
    for (int j = 1; i * j <= m; ++j) now += bit.sum(i * j + 1);
    res.push_back(now);
  }
}