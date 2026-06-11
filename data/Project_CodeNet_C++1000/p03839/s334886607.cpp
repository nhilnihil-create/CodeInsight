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
  int N, K;
  cin >> N >> K;
  auto a = vector<ll>(N, 0);
  auto d = vector<ll>(N, 0);
  REP(i, N) {
    cin >> a[i];
    if(i >= 1) {
      if(a[i] > 0) {
        d[i] += d[i - 1] + a[i];
      } else {
        d[i] = d[i - 1];
      }
    } else {
      if(a[i] > 0) {
        d[i] = a[i];
      } else {
        d[i] = 0;
      }
    }
  }

  ll ans = 0;
  REP(i, N - K + 1) {
    ll sum = 0;
    if(i == 0) {
      sum += d[N - 1] - d[i + K - 1];
    } else if(i == N - K) {
      sum += d[i - 1];
    } else {
      sum += d[i - 1] + d[N - 1] - d[i + K - 1];
    }
    ll k_sum = 0;
    REPS(j, i, i + K) { k_sum += a[j]; }
    if(k_sum >= 0) {
      sum += k_sum;
    }
    ans = max(ans, sum);
  }

  cout << ans << endl;
}
