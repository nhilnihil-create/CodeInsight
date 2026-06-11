
/* -------------------------------- Template -------------------------------- */

#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstring>
#include <deque>
#include <functional>
#include <iomanip>
#include <locale>
#include <iostream>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

#define REP(i,n) for(int i=0;i<(int)(n);i++)
#define ALL(x) (x).begin(),(x).end()

using ll = long long;
using ld = long double;

template <typename T> T &chmin(T &a, const T &b) { return a = std::min(a, b); }
template <typename T> T &chmax(T &a, const T &b) { return a = std::max(a, b); }
template <typename T> int len(const T &x) { return x.size(); }

// template<typename T> constexpr T inf;
// template<> constexpr int inf<int> = 1e9;
// template<> constexpr ll inf<ll> = 1e18;
// template<> constexpr ld inf<ld> = 1e30;

struct yes_no : std::numpunct<char> {
  string_type do_truename()  const { return "Yes"; }
  string_type do_falsename() const { return "No"; }
};

void solve();

int main() {
  std::locale loc(std::locale(), new yes_no);
  std::cout << std::boolalpha << std::setprecision(12) << std::fixed;
  std::cout.imbue(loc);
  solve();
  return 0;
}

using namespace std;

/* -------------------------------- Library -------------------------------- */

/* ---------------------------------- Main ---------------------------------- */

ll A[128000];
ll B[128000];

void solve() {
  ll N;
  cin >> N;
  vector<int> idx;
  REP(i,N) {
    if (i > 0) {
      string op;
      cin >> op;
      if (op == "-") idx.push_back(i);
    }
    cin >> A[i];
  }
  REP(i,N) B[i+1] = B[i] + A[i];

  ll sum = accumulate(A, A + N, 0LL);
  if (idx.empty()) {
    cout << sum << endl;
    return;
  }

  ll res = -1e18;
  ll dec = 0;
  REP(i,idx.size()-1) {
    chmax(res, sum - dec * 2 - (B[idx[i+1]] - B[idx[i]]) * 2);
    dec += A[idx[i]];
  }
  chmax(res, sum - dec * 2 - A[idx.back()] * 2);
  cout << res << endl;
}
