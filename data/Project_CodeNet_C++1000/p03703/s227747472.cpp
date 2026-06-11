

#include <cstdio>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cctype>
#include <iomanip>
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

template <class T>
class FenwickTree {
 public:
  FenwickTree(const std::vector<T>& data) : n_(data.size() + 1), data_(data) {
    Initialize();
  }
  void Add(size_t pos, T value) {
    ++pos;
    while (pos < n_) {
      node_[pos] += value;
      pos += pos & -pos;
    }
  }
  // return sum of [0, i]
  T GetSum(size_t pos) {
    ++pos;
    T sum = 0;
    while (pos > 0) {
      sum += node_[pos];
      pos -= pos & -pos;
    }
    return sum;
  }
  // return sum of [left, rihgt]
  T GetRangeSum(int left, int right) {
    return GetSum(right) - GetSum(left - 1);
  }
  // for range add query
  class RAQ {
   public:
    RAQ(const std::vector<T>& data)
        : n_(data.size()),
          ft1_(FenwickTree<T>(data)),
          ft2_(FenwickTree<T>(data)) {}
    // add range [left, right)
    void RangeAdd(int left, int right, T value) {
      Add(ft1_, left, right, value);
      Add(ft2_, left, right, -value * static_cast<T>(left - 1));
      Add(ft2_, right, n_, value * static_cast<T>(right - left));
    }
    // get sum of [0, i]
    T GetSum(size_t pos) {
      return ft1_.GetSum(pos) * static_cast<T>(pos) + ft2_.GetSum(pos);
    }
    // get sum of [left, right]
    T GetRangeSum(int left, int right) {
      return GetSum(right) - GetSum(left - 1);
    }

   private:
    size_t n_;
    FenwickTree<T> ft1_;
    FenwickTree<T> ft2_;
    void Add(FenwickTree<T>& ft, int left, int right, T value) {
      ft.Add(left, value);
      ft.Add(right, -value);
    }
  };

 private:
  size_t n_;
  std::vector<T> data_;
  std::vector<T> node_;
  void Initialize() {
    node_.assign(n_ + 1, 0);
    for (size_t i = 0; i < n_ - 1; ++i) Add(i, data_[i]);
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

  FenwickTree<int> ft(vector<int>(n + 1, 0));

  CoodinateCompression<int64> cc(sum);
  ft.Add(cc[0].after, 1);

  int64 ans = 0;

  for (int i = 1; i < n + 1; ++i) {
    ans += static_cast<int64>(ft.GetSum(cc[i].after));
    ft.Add(cc[i].after, 1);
  }

  printf("%lld\n", ans);

  return 0;
}
