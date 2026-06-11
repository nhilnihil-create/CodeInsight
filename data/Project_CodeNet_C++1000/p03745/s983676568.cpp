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

int64 compare_two_int64(int64 a, int64 b) {
  if (a > b)
    return 1;
  else if (a == b)
    return 0;
  else
    return -1;
}

int main() {
  int64 N;
  cin >> N;
  vector<int64> A(N);
  cin >> A;
  int64 count = 0;
  int64 trend;
  int64 trend_prev = compare_two_int64(A[0], A[1]);
  bool is_first_element = 0;
  for (int64 i = 1; i < N - 1; i++) {
    if (is_first_element) {
      is_first_element = 0;
      trend_prev = compare_two_int64(A[i], A[i + 1]);
      continue;
    }
    trend = compare_two_int64(A[i], A[i + 1]);
    if (trend * trend_prev == -1) {
      count++;
      is_first_element = 1;
    }
    if (trend != 0) trend_prev = trend;
  }
  cout << count + 1 << endl;
  return 0;
}