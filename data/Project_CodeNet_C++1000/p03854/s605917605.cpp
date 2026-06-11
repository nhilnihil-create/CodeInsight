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

bool isMatch(const string& S, const string& m, int idx) {
  for (int i = 0; i < m.size(); i++) {
    if (S[idx + i] != m[i]) return 0;
  }
  return 1;
}

int main() {
  string S;
  cin >> S;
  int right = S.size();
  int idx = 0;
  while (right != 0) {
    debug(right, idx);
    if (right == 11) {
      if (isMatch(S, "dreameraser", idx)) {
        cout << "YES" << endl;
        return 0;
      } else {
        if (isMatch(S, "eraser", idx)) {
          idx += 6;
          right -= 6;
          continue;
        }
        if (isMatch(S, "dream", idx) || isMatch(S, "erase", idx)) {
          idx += 5;
          right -= 5;
          continue;
        }
        cout << "NO" << endl;
        return 0;
      }
    }
    if (right == 10) {
      if (isMatch(S, "dreamerase", idx)) {
        cout << "YES" << endl;
        return 0;
      } else {
        if (isMatch(S, "dream", idx) || isMatch(S, "erase", idx)) {
          idx += 5;
          right -= 5;
          continue;
        }
        cout << "NO" << endl;
        return 0;
      }
    }
    if (right == 7) {
      if (isMatch(S, "dreamer", idx)) {
        cout << "YES" << endl;
        return 0;
      } else {
        cout << "NO" << endl;
        return 0;
      }
    }
    if (right == 6) {
      if (isMatch(S, "eraser", idx)) {
        cout << "YES" << endl;
        return 0;
      } else {
        cout << "NO" << endl;
        return 0;
      }
    }
    if (right == 5) {
      if (isMatch(S, "dream", idx) || isMatch(S, "erase", idx)) {
        cout << "YES" << endl;
        return 0;
      } else {
        cout << "NO" << endl;
        return 0;
      }
    }
    if (isMatch(S, "dreameraser", idx)) {
      idx += 11;
      right -= 11;
    } else if (isMatch(S, "dreamerase", idx)) {
      idx += 10;
      right -= 10;
    } else if (isMatch(S, "dreamer", idx)) {
      idx += 7;
      right -= 7;
    } else if (isMatch(S, "eraser", idx)) {
      idx += 6;
      right -= 6;
    } else if (isMatch(S, "erase", idx) || isMatch(S, "dream", idx)) {
      idx += 5;
      right -= 5;
    } else {
      cout << "NO" << endl;
      return 0;
    }
  }
  return 0;
}