#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
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

class combination {
 public:
  static constexpr int64 divide_by = (int64)1e9 + 7;
  combination(int64 MAX) : fac(MAX), finv(MAX), inv(MAX) {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++) {
      fac[i] = fac[i - 1] * i % divide_by;
      inv[i] = divide_by - inv[divide_by % i] * (divide_by / i) % divide_by;
      finv[i] = finv[i - 1] * inv[i] % divide_by;
    }
  }

  int64 get_comb(int n, int k) {
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % divide_by) % divide_by;
  }

 private:
  vector<int64> fac, finv, inv;
};

int main() {
  int N, P;
  cin >> N >> P;
  vector<int> A(N);
  cin >> A;
  int ev = 0;
  int od = 0;
  for (int i = 0; i < N; i++) {
    if (A[i] % 2 == 1)
      od++;
    else
      ev++;
  }
  combination comb(101);
  int64 sm_even = pow(2LL, ev);
  int64 sm_odd = 0;
  if (P == 0) {
    if (od % 2 == 1) {
      for (int i = 0; i <= od - 1; i = i + 2) {
        sm_odd += comb.get_comb(od, i);
      }
    } else {
      for (int i = 0; i <= od; i = i + 2) {
        sm_odd += comb.get_comb(od, i);
      }
    }
  } else {
    if (od % 2 == 1) {
      for (int i = 1; i <= od; i = i + 2) {
        sm_odd += comb.get_comb(od, i);
      }
    } else {
      for (int i = 1; i <= od - 1; i = i + 2) {
        sm_odd += comb.get_comb(od, i);
      }
    }
  }
  debug(sm_odd, sm_even);
  cout << sm_odd * sm_even << endl;
  return 0;
}