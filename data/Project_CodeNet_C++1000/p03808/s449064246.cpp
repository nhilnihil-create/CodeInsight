#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
#include <sstream>
#include <complex>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>

#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n) - 1; i >= 0; i--)
#define reps(i, n) for (int i = 1; i <= (n); i++)
#define repi(i, a, b) for (int i = (a); i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define bit(b) (1ull << (b))

using namespace std;
using i32 = long long;
using u32 = unsigned long long;
using i64 = long long;
using u64 = unsigned long long;
using f64 = double;
using vi32 = vector<i32>;
using vu32 = vector<u32>;
using vi64 = vector<i64>;
using vu64 = vector<u64>;
using vf64 = vector<f64>;
using vstr = vector<string>;
using vvi32 = vector<vi32>;
using vvu32 = vector<vu32>;
using vvi64 = vector<vi64>;
using vvu64 = vector<vu64>;
using vvf64 = vector<vf64>;

template<typename T, typename S> void amax(T &x, S y) { if (x < y) x = y; }
template<typename T, typename S> void amin(T &x, S y) { if (y < x) x = y; }

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << fixed << setprecision(16);
  i64 n;
  cin >> n;
  vi32 a(n);
  rep(i, n) cin >> a[i];
  i64 sum = 0;
  rep(i, n) sum += a[i];
  if (sum % (n * (n + 1) / 2) != 0) {
    cout << "NO" << endl;
    return 0;
  }
  i64 C = sum / (n * (n + 1) / 2);
  i64 kyokai = 0, futsu = 0;
  rep(i, n) {
    int prev = i, next = i + 1;
    if (next >= n) next = 0;
    i64 D = a[next] - a[prev];
    if ((C - D) % n != 0) {
      cout << "NO" << endl;
      return 0;
    }
    if (D > C || D < (1 - n) * C) {
      cout << "NO" << endl;
      return 0;
    }
    i64 c = (C - D) / n;
    if (c > C || c < 0) {
      cout << "NO" << endl;
      return 0;
    }
    kyokai += c;
    futsu += C - c;
  }
  if (kyokai == C && futsu == (n - 1) * C) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
  return 0;
}
