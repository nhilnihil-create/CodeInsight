#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0, i##_len = (n); i < i##_len; ++i)
#define REPS(i, _s, n) for(int i = _s, i##_len = (n); i < i##_len; ++i)
#define ALL(x) (x).begin(), (x).end()
using namespace std;

#define repi(itr, ds) for(auto itr = ds.begin(); itr != ds.end(); itr++)
// vector
template <typename T>
istream &operator>>(istream &is, vector<T> &vec) {
  for(T &x : vec) is >> x;
  return is;
}
// pair
template <typename T, typename U>
ostream &operator<<(ostream &os, pair<T, U> &pair_var) {
  os << "(" << pair_var.first << ", " << pair_var.second << ")";
  return os;
}
// vector
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &vec) {
  os << "{";
  for(int i = 0; i < vec.size(); i++) {
    os << vec[i] << (i + 1 == vec.size() ? "" : ", ");
  }
  os << "}\n   ";
  return os;
}
// map
template <typename T, typename U>
ostream &operator<<(ostream &os, map<T, U> &map_var) {
  os << "{";
  repi(itr, map_var) {
    os << *itr;
    itr++;
    if(itr != map_var.end()) os << ", ";
    itr--;
  }
  os << "}";
  return os;
}
// set
template <typename T>
ostream &operator<<(ostream &os, set<T> &set_var) {
  os << "{";
  repi(itr, set_var) {
    os << *itr;
    itr++;
    if(itr != set_var.end()) os << ", ";
    itr--;
  }
  os << "}";
  return os;
}

#define DUMPOUT cerr

void dump_func() { DUMPOUT << endl; }
template <class Head, class... Tail>
void dump_func(Head &&head, Tail &&... tail) {
  DUMPOUT << head;
  if(sizeof...(Tail) > 0) {
    DUMPOUT << ", ";
  }
  dump_func(std::move(tail)...);
}
#ifdef DEBUG_
#define DEB
#define dump(...)                                                             \
  DUMPOUT << "  " << string(#__VA_ARGS__) << ": "                             \
          << "[" << to_string(__LINE__) << ":" << __FUNCTION__ << "]" << endl \
          << "    ",                                                          \
      dump_func(__VA_ARGS__)
#else
#define DEB if(false)
#define dump(...)
#endif

typedef long long int ll;
const int MOD = 1e9 + 7;
const int INF = 1e9;

int main() {
  int N, x;
  cin >> N >> x;

  if(x == 1 || x == 2 * N - 1) {
    cout << "No" << endl;
    return 0;
  }

  cout << "Yes" << endl;
  if(N == 2) {
    cout << 1 << endl;
    cout << 2 << endl;
    cout << 3 << endl;
    return 0;
  }

  int a[2 * N - 1];
  a[N - 1] = x;
  a[N] = x - 1;
  a[N - 2] = x + 1;
  if(x == 2) {
    a[N - 3] = x + 2;
  } else {
    a[N - 3] = x - 2;
  }

  int n = 1;
  REP(i, 2 * N - 1) {
    if(i >= N - 3 && i <= N) continue;
    if(x != 2) {
      if(n == x - 2) n = x + 2;
    } else {
      if(n == x - 1) n = x + 3;
    }
    a[i] = n;
    n++;
  }

  REP(i, 2 * N - 1) { cout << a[i] << endl; }
}
