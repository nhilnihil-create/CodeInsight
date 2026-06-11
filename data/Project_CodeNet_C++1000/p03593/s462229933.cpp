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

int main() {
  int H, W;
  cin >> H >> W;
  vector<int> cnt(26);
  char c;
  for (int i = 0; i < H * W; i++) {
    cin >> c;
    cnt[c - 'a']++;
  }
  if (H % 2 == 0 && W % 2 == 0) {
    for (int i = 0; i < 26; i++) {
      if (cnt[i] % 4 != 0) {
        cout << "No" << endl;
        return 0;
      }
    }
    cout << "Yes" << endl;
    return 0;
  }

  if (H % 2 == 1 && W % 2 == 1) {
    int ntwo = (H - 1) / 2 + (W - 1) / 2;
    int nfour = (H * W - ntwo * 2 - 1) / 4;
    for (int i = 0; i < 26; i++) {
      while (cnt[i] >= 4 && nfour > 0) {
        cnt[i] -= 4;
        nfour--;
      }
    }
    if (nfour > 0) {
      cout << "No" << endl;
      return 0;
    }
    int cnt_odd = 0;
    for (int i = 0; i < 26; i++) {
      if (cnt[i] % 2 == 1) cnt_odd++;
    }
    if (cnt_odd == 1)
      cout << "Yes" << endl;
    else
      cout << "No" << endl;
    return 0;
  }

  if (H % 2 == 1 && W % 2 == 0) {
    int ntwo = W / 2;
    int nfour = (H * W - ntwo * 2) / 4;
    debug(ntwo, nfour);
    for (int i = 0; i < 26; i++) {
      while (cnt[i] >= 4 && nfour > 0) {
        cnt[i] -= 4;
        nfour--;
      }
    }
    if (nfour > 0) {
      cout << "No" << endl;
      return 0;
    }
    int cnt_odd = 0;
    for (int i = 0; i < 26; i++) {
      if (cnt[i] % 2 == 1) cnt_odd++;
    }
    if (cnt_odd == 0)
      cout << "Yes" << endl;
    else
      cout << "No" << endl;
    return 0;
  }

  if (H % 2 == 0 && W % 2 == 1) {
    int ntwo = H / 2;
    int nfour = (H * W - ntwo * 2) / 4;
    for (int i = 0; i < 26; i++) {
      while (cnt[i] >= 4 && nfour > 0) {
        cnt[i] -= 4;
        nfour--;
      }
    }
    if (nfour > 0) {
      cout << "No" << endl;
      return 0;
    }
    int cnt_odd = 0;
    for (int i = 0; i < 26; i++) {
      if (cnt[i] % 2 == 1) cnt_odd++;
    }
    if (cnt_odd == 0)
      cout << "Yes" << endl;
    else
      cout << "No" << endl;
    return 0;
  }

  return 0;
}