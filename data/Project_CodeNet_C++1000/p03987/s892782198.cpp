#include<iostream>
#include<queue>
#include<algorithm>
#include<functional>
#include<cstdint>
#include<cstdlib>
template<typename T>
void fin(T const& t){ std::cout << t << std::endl; exit(0); }

// bit
template<typename T, int NN>
struct bit {
  typedef std::function<T(T,T)> OP;
  T data_[NN], e_; // 0-base
  OP& op_;
  bit(OP& op, T e) : e_(e), op_(op) { std::fill_n(data_, NN, e_); }
  int lb(int i){ return i&-i; }
  T query(int i) { // 1-base
    T res = e_;
    while(i > 0) { res = op_(res, data_[i-1]); i -= lb(i); }
    return res;
  }
  void add(int i, T const& v) { // 1-base
    while(i <= NN) { data_[i-1] = op_(data_[i-1], v); i += lb(i); }
  }
};

using mbit = bit<int, (1<<18)>;
mbit::OP op_mi = [](int x, int y){ return std::min(x, y); };
mbit::OP op_ma = [](int x, int y){ return std::max(x, y); };

int main() {
  std::cin.tie(0); std::ios::sync_with_stdio(false);
  int N; std::cin >> N;
  std::vector<int> a(N);
  std::vector<int64_t> num(N+1);
  for(int i = 0; i < N; ++i) std::cin >> a[i];
  // left
  mbit bma(op_ma, -1);
  for(int i = 0; i < N; ++i) {
    int v = a[i];
    num[v] = i - bma.query(v-1);
    bma.add(v, i);
  }
  // right
  mbit bmi(op_mi, N);
  for(int i = N-1; i >= 0; --i) {
    int v = a[i];
    num[v] *= bmi.query(v-1) - i;
    bmi.add(v, i);
  }
  int64_t ans = 0;
  for(int i = 1; i <= N; ++i) ans += num[i]*i;
  fin(ans);
  return 0;
}
