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

int main() {
  int64 n;
  cin >> n;
  vector<int64> a(n);
  cin >> a;
  int64 shou = n / 2;
  int amari = n % 2;
  string str = "";
  for (int64 i = 0; i < shou; i++) {
    str += to_string(a[n - 1 - i * 2]);
    str += ' ';
  }
  if (amari == 0) {
    for (int64 i = 0; i < shou; i++) {
      str += to_string(a[i * 2]);
      str += ' ';
    }
  } else {
    str += to_string(a[0]);
    str += ' ';
    for (int64 i = 0; i < shou; i++) {
      str += to_string(a[i * 2 + 1]);
      str += ' ';
    }
  }
  str.pop_back();
  cout << str << endl;
  return 0;
}