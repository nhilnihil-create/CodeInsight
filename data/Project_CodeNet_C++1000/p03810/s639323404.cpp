#include <iostream>
#include <iomanip>
#include <climits>
#include <limits>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <list>
#include <stack>
#include <string>
#include <functional>
#include <numeric>
#include <map>
#include <set>
#include <cstdlib>
#include <bitset>
#include <unordered_map>
#include <random>
#define _USE_MATH_DEFINES
#include <cmath>
#include <complex>
#include <cfloat>

using namespace std;

#define INFD numeric_limits<double>::infinity()
#define INFL (int)1e8
#define INFLL (long long)1e15
#define Loop(i, n) for(int i = 0; i < (int)n; i++)
#define Loop1(i, n) for(int i = 1; i <= (int)n; i++)
#define Loopr(i, n) for(int i = (int)n - 1; i >= 0; i--)
#define Loopr1(i, n) for(int i = (int)n; i >= 1; i--)
#define bitmanip(m,val) static_cast<bitset<(int)m>>(val)
typedef long long int ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> P;
typedef pair<ll, ll> Pll;
typedef vector<ll> vll;
typedef vector<vector<ll>> vvll;

/*******************************************************/


//solve x, y s.t. mx+ny=gcd(m,n)
class Extended_Euclid {
private:
  ll m, n;
  vvll mx_multiply(vvll mx1, vvll mx2) {
    vvll ret(mx1.size(), vll(mx2[0].size(), 0));
    Loop(i, mx1.size()) {
      Loop(j, mx1[0].size()) {
        Loop(k, mx2[0].size()) {
          ret[i][j] += mx1[i][k] * mx2[k][j];
        }
      }
    }
    return ret;
  }
public:
  ll x, y, gcd;
  Extended_Euclid(ll M, ll N) {
    m = M;
    n = N;
    vll r(100), k(100);
    bool swapflag = false, m_negflag = false, n_negflag = false;
    if (m < n) { swap(m, n); swapflag = true; }
    if (m < 0) { m *= -1; m_negflag = true; }
    if (n < 0) { n *= -1; n_negflag = true; }
    r[0] = m;
    r[1] = n;
    int h = 1;
    while (1) {
      k[h - 1] = r[h - 1] / r[h];
      r[h + 1] = r[h - 1] % r[h];
      if (r[h + 1] == 0) break;
      h++;
    }
    gcd = r[h];
    vvll mx1 = { { 0, 1 },{ 1, (-1) * k[h - 1] } };
    Loopr(i, h - 1) {
      vvll mx2 = { { 0, 1 },{ 1, (-1) * k[i] } };
      mx1 = mx_multiply(mx1, mx2);
    }
    x = mx1[0][0];
    y = mx1[0][1];
    if (n_negflag) { n *= -1; y *= -1; }
    if (m_negflag) { m *= -1; x *= -1; }
    if (swapflag) { swap(m, n); swap(x, y); }
  }
};


ll all_gcd(vll a) {
  ll ret = a[0];
  Loop1(i, a.size() - 1) {
    Extended_Euclid ee(ret, a[i]);
    ret = ee.gcd;
  }
  return ret;
}

bool solve(vll a, bool turn) {
  int even_cnt = 0;
  int odd_index = -1;
  Loop(i, a.size()) {
    if (a[i] % 2 == 0) even_cnt++;
    else odd_index = i;
  }
  if (even_cnt % 2 == 1) return turn;
  else {
    if (a.size() - even_cnt >= 2) return !turn;
    else if (a[odd_index] == 1) return !turn;
    // the unique hope
    else {
      a[odd_index]--;
      ll gcd = all_gcd(a);
      Loop(i, a.size()) {
        a[i] /= gcd;
      }
      return solve(a, !turn);
    }
  }
}

int main() {
  int n; cin >> n;
  vll a(n); Loop(i, n) cin >> a[i];
  bool ans = solve(a, 0);
  if (ans == 0) cout << "First" << endl;
  else cout << "Second" << endl;
}