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
  int N;
  cin >> N;
  auto T = vector<int>(N);
  auto A = vector<int>(N);
  REP(i, N) cin >> T[i];
  REP(i, N) cin >> A[i];

  auto err = []() {
    cout << 0 << endl;
    exit(0);
  };

  ll ans = 1;
  REP(i, N) {
    int tfix = -1;
    int afix = -1;
    if(i == 0 || T[i - 1] < T[i]) {
      tfix = T[i];
    }
    if(i == N - 1 || A[i] > A[i + 1]) {
      afix = A[i];
    }
    dump(i, afix, tfix, A[i], T[i]);
    if(afix != tfix && afix != -1 && tfix != -1) {
      err();
    } else if(afix != -1 && tfix == -1 && T[i] < afix) {
      err();
    } else if(tfix != -1 && afix == -1 && A[i] < tfix) {
      err();
    } else if(tfix == -1 && afix == -1) {
      ll num = min(A[i], T[i]);
      ans = ans * num % MOD;
    }
  }
  cout << ans << endl;
}
