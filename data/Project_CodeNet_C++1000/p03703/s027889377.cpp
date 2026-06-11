
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cctype>
#include <utility>

using namespace std;

using int64 = long long;

template <class T>
class CoodinateCompression {
 public:
  CoodinateCompression(const std::vector<T>& vec) : vec_(vec) {
    result_.resize(vec_.size());
    Compress();
  }
  struct state {
    T before;
    int after;
  };
  state operator[](int pos) const { return result_[pos]; }

 private:
  std::vector<T> vec_;
  std::vector<state> result_;
  void Compress() {
    std::vector<T> t = vec_;
    std::sort(t.begin(), t.end());
    t.erase(std::unique(t.begin(), t.end()), t.end());
    for (size_t i = 0; i < vec_.size(); ++i) {
      result_[i] = {vec_[i], static_cast<int>(std::distance(
                                t.begin(),
                                std::lower_bound(t.begin(), t.end(), vec_[i])))};
    }
  }
};

template <class Monoid, class Function>
class SegmentTree {
 public:
  SegmentTree(const std::vector<Monoid>& data, Monoid identity_element,
              Function function)
      : identity_element_(identity_element), data_(data), function_(function) {
    Build();
  }
  void Update(size_t position, Monoid new_value) {
    position += n_;
    node_[position] = new_value;
    while (position > 0) {
      position >>= 1;
      node_[position] = function_(node_[2 * position], node_[2 * position + 1]);
    }
  }

  Monoid Query(int left, int right) {
    Monoid vl = identity_element_, vr = identity_element_;
    for (left += n_, right += n_; left < right; left >>= 1, right >>= 1) {
      if (left & 1) vl = function_(vl, node_[left++]);
      if (right & 1) vr = function_(node_[--right], vr);
    }
    return function_(vl, vr);
  }

  Monoid operator[](size_t position) const { return node_[n_ + position]; }

 private:
  size_t n_;
  Monoid identity_element_;
  std::vector<Monoid> data_;
  std::vector<Monoid> node_;
  Function function_;
  void Build() {
    size_t SIZE = data_.size();
    n_ = 1;
    while (n_ < SIZE) {
      n_ <<= 1;
    }
    node_.assign(2 * n_, identity_element_);
    for (size_t i = 0; i < SIZE; ++i) {
      node_[i + n_] = data_[i];
    }
    for (size_t i = n_ - 1; i > 0; --i) {
      node_[i] = function_(node_[2 * i], node_[2 * i + 1]);
    }
  }
};

template<class T> inline void fastin(T &num) {
  T c;
  num = 0;
  c = getchar_unlocked();
  for (; (c > 47 && c < 58); c = getchar_unlocked()) num = (num << 3) + (num << 1) + c - 48;
}

int main() {
  int n; fastin(n);
  int64 k; fastin(k);
  vector<int64> a(n);
  for (int i = 0; i < n; ++i) {
    fastin(a[i]);
    a[i] -= k;
  }

  vector<int64> sum(n + 1, 0LL);
  for (int i = 0; i < n; ++i) {
    sum[i + 1] = sum[i] + a[i];
  }

  auto f = [](int x, int y){ return x + y; };
  SegmentTree<int, decltype(f)> seg(vector<int>(n + 1, 0), 0, f);

  CoodinateCompression<int64> cc(sum);
  seg.Update(cc[0].after, 1);

  int64 ans = 0;

  for (int i = 1; i < n + 1; ++i) {
    ans += static_cast<int64>(seg.Query(0, cc[i].after + 1));
    seg.Update(cc[i].after, seg[cc[i].after] + 1);
  }

  printf("%lld\n", ans);

  return 0;
}