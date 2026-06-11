#include <iostream>
#include <algorithm>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#include <cmath>
#include <bitset>
#include <complex>
#include <functional>
#include <numeric>
#include <iomanip>

// output
#define SPBR(w, n) std::cout<<(w + 1 == n ? '\n' : ' ');
#define YES cout << "YES" << endl
#define Yes cout << "Yes" << endl
#define NO cout << "NO" << endl
#define No cout << "No" << endl
// utility
#define ALL(i) (i).begin(), (i).end()
#define FOR(i, a, n) for(int i=(a);i<(n);++i)
#define RFOR(i, a, n) for(int i=(n)-1;i>=(a);--i)
#define REP(i, n) for(int i=0;i<int(n);++i)
#define RREP(i, n) for(int i=int(n)-1;i>=0;--i)
#define IN(a, x, b) (a<=x && x<b)
#define OUT(a, x, b) (x<a || b<=x)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

// type/const
#define int ll
using ll = long long;
using ull = unsigned long long;
using ld = long double;
const int MOD = 1000000007;
/* const int MOD = 998244353; */
const int INF = 1e18;
const double PI = acos(-1);

using namespace std;
struct INIT { INIT(){
  cin.tie(0); ios::sync_with_stdio(false);
  cout << fixed << setprecision(10);
}}INIT;

template<typename T>
struct bit {
  vector<T> data;
  bit(int sz) {
    data.assign(++sz, 0);
  }
  bit(int sz, int v){
    data.assign(++sz, v);
    REP(i, sz) data[i+(i&-i)] += data[i];
  }
  T sum(int k) {
    T ret = 0;
    for(++k; k > 0; k -= k & -k) ret += data[k];
    return ret;
  }
  void add(int k, T x) {
    for(++k; k < data.size(); k += k & -k) data[k] += x;
  }
};

signed main() {
  int N, K;
  cin >> N >> K;

  vector<int> A(N);
  REP(i, N) cin >> A[i];

  int sum = 0;
  vector<int> v(N+1);
  REP(i, N+1){
    v[i] = sum-i*K;
    if(i != N) sum += A[i];
  }

  vector<int> o(N+1);
  iota(ALL(o), 0);

  sort(ALL(o), [&](int const & l, int const & r){
      if(v[l] != v[r]) return v[l] > v[r];
      return l > r;
      });

  bit<int> bit(N+1);

  int ans = 0;
  REP(i, N+1){
    bit.add(o[i], 1);
    ans += bit.sum(N)-bit.sum(o[i]);
  }

  cout << ans << "\n";

  return 0;
}