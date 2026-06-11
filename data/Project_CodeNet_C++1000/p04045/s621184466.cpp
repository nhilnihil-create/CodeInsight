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

void get_kurai_vec(int S, vector<int>& store) {
  int shou = S / 10;
  int amari = S % 10;
  store.insert(store.begin(), amari);
  if (shou < 10) {
    if (shou != 0) store.insert(store.begin(), shou);
    return;
  }
  get_kurai_vec(shou, store);
}

int main() {
  int K, N;
  cin >> N >> K;
  vector<int> D(K);
  cin >> D;
  bool break_flag;
  int tmp = N;
  while (1) {
    break_flag = 0;
    vector<int> kurai_vec(0);
    get_kurai_vec(tmp, kurai_vec);
    for (int i = 0; i < kurai_vec.size(); i++) {
      for (int j = 0; j < D.size(); j++) {
        if (kurai_vec[i] == D[j]) {
          break_flag = 1;
          break;
        }
      }
      if (break_flag) break;
    }
    if (!break_flag) {
      cout << tmp << endl;
      return 0;
    }
    tmp++;
  }
  return 0;
}