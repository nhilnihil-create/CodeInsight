#include <algorithm>
#include <bitset>
#include <cmath>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <string>
#include <vector>

// Acknowledgement: Special thanks to kyomukyomupurin, who developed this
// template.
template <class T, class U>
std::ostream& operator<<(std::ostream& os, const std::pair<T, U>& p) {
  return os << '(' << p.first << ", " << p.second << ')';
}

template <class T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& vec) {
  int n = 0;
  for (auto e : vec) os << (n++ ? ", " : "{") << e;
  return os << (n ? "}" : "{}");
}

template <class T>
std::ostream& operator<<(std::ostream& os, const std::set<T>& st) {
  int n = 0;
  for (auto e : st) os << (n++ ? ", " : "{") << e;
  return os << (n ? "}" : "{}");
}

template <class T, class U>
std::ostream& operator<<(std::ostream& os, const std::map<T, U>& mp) {
  int n = 0;
  for (auto e : mp) os << (n++ ? ", " : "{") << e;
  return os << (n ? "}" : "{}");
}

template <class T>
std::istream& operator>>(std::istream& is, std::vector<T>& vec) {
  for (T& e : vec) is >> e;
  return is;
}

#ifdef LOCAL
#define debug(...) \
  std::cerr << "[" << #__VA_ARGS__ << "]: ", debug_out(__VA_ARGS__)
#else
#define debug(...)
#endif

void debug_out() { std::cerr << '\n'; }

template <class Head, class... Tail>
void debug_out(Head&& head, Tail&&... tail) {
  std::cerr << head;
  if (sizeof...(Tail) != 0) std::cerr << ", ";
  debug_out(std::forward<Tail>(tail)...);
}
using namespace std;
using int64 = long long;

template <class _Tp>
class FenwickTree {
 public:
  FenwickTree(const std::vector<_Tp>& data) : n_(data.size() + 1), data_(data) {
    initialize();
  }

  void add(int pos, _Tp value) {
    ++pos;
    while (pos < n_) {
      node_[pos] += value;
      pos += pos & -pos;
    }
  }

  // return sum of [0, i]
  _Tp get(int pos) {
    ++pos;
    _Tp sum = 0;
    while (pos > 0) {
      sum += node_[pos];
      pos -= pos & -pos;
    }
    return sum;
  }

  // return sum of [l, rihgt]
  _Tp get(int l, int r) { return get(r) - get(l - 1); }

  // return the first k where sum of [0, k] >= value
  // use only when all element in data >= 0
  int lower_bound(_Tp value) {
    if (value <= 0) return 0;
    int pos = 0;
    int k = 1;
    while (k < n_ - 1) k <<= 1;
    while (k > 0) {
      if (pos + k <= n_ - 1 && node_[pos + k] < value) {
        value -= node_[pos + k];
        pos += k;
      }
      k >>= 1;
    }
    return pos;
  }

  // for range add query
  class RAQ {
   public:
    RAQ(const std::vector<_Tp>& data)
        : n_(data.size()),
          ft1_(FenwickTree<_Tp>(data)),
          ft2_(FenwickTree<_Tp>(data)) {}

    // add value range [l, r)
    void add(int l, int r, _Tp value) {
      add(ft1_, l, r, value);
      add(ft2_, l, r, -value * static_cast<_Tp>(l - 1));
      add(ft2_, r, n_, value * static_cast<_Tp>(r - l));
    }

    // get sum of [0, i]
    _Tp get(int pos) {
      return ft1_.get(pos) * static_cast<_Tp>(pos) + ft2_.get(pos);
    }

    // get sum of [l, r]
    _Tp get(int l, int r) { return get(r) - get(l - 1); }

   private:
    int n_;
    FenwickTree<_Tp> ft1_;
    FenwickTree<_Tp> ft2_;
    void add(FenwickTree<_Tp>& ft, int l, int r, _Tp value) {
      ft.add(l, value);
      ft.add(r, -value);
    }
  };

 private:
  int n_;
  std::vector<_Tp> data_;
  std::vector<_Tp> node_;
  void initialize() {
    node_.assign(n_ + 1, 0);
    for (int i = 0; i < n_ - 1; ++i) add(i, data_[i]);
  }
};

int main() {
  int64 N, K;
  cin >> N >> K;
  vector<int64> a(N);
  cin >> a;
  vector<int64> sum(N + 1, 0);
  for (int64 i = 1; i < N + 1; i++) {
    sum[i] = sum[i - 1] + a[i - 1];
  }
  vector<int64> b(N + 1);
  for (int64 i = 0; i < N + 1; i++) {
    b[i] = sum[i] - i * K;
  }
  // 座標圧縮の準備
  debug(b);
  vector<int64> c = b;
  sort(c.begin(), c.end());
  c.erase(unique(c.begin(), c.end()), c.end());
  debug(c);

  int64 ans = 0;
  FenwickTree<int> ft(vector<int>(N + 1, 0));
  for (int64 i = 0; i < N + 1; ++i) {
    int idx = distance(c.begin(), lower_bound(c.begin(), c.end(), b[i]));
    ans += ft.get(0, idx);
    ft.add(idx, 1);
  }
  cout << ans << endl;
  return 0;
}