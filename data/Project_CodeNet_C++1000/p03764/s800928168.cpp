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
  int n, m;
  cin >> n >> m;
  auto x = vector<int>(n);
  auto y = vector<int>(m);
  REP(i, n) cin >> x[i];
  REP(i, m) cin >> y[i];

  ll sum_x = 0;
  ll sum_y = 0;
  REP(i, n - 1) {
    ll left = i + 1;
    ll right = n - left;
    ll tmp = left * right;
    tmp %= MOD;
    tmp *= x[i + 1] - x[i];
    tmp %= MOD;
    sum_x += tmp;
    sum_x %= MOD;
  }
  REP(i, m - 1) {
    ll left = i + 1;
    ll right = m - left;
    ll tmp = left * right;
    tmp %= MOD;
    tmp *= y[i + 1] - y[i];
    tmp %= MOD;
    sum_y += tmp;
    sum_y %= MOD;
  }

  ll ans = sum_x * sum_y % MOD;

  cout << ans << endl;
}
