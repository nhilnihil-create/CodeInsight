/*{{{*/
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <unordered_map>
#include <unordered_set>
#include <cassert>
using namespace std;
typedef pair<int, int> PP;
typedef long long LL;
#define pb push_back
#define fr first
#define sc second
#define bitcnt __builtin_popcount
#define all(x) x.begin(), x.end()
inline LL ri() {LL x; scanf("%lld", &x); return x;}
#define rep2(i, n, ...) for (int i = 0; i < (n); i ++) 
#define rep3(i, a, b, ...) for (int i = (a); i < (b); i ++)
#define GET_MACRO(_1, _2, _3, NAME, ...) NAME
#define rep(...) GET_MACRO(__VA_ARGS__, rep3, rep2)(__VA_ARGS__)
#define drep2(i, n, ...) for (int i = (n) - 1; i >= 0; i --)
#define drep3(i, a, b) for (int i = (a) - 1; i >= (b); i --)
#define drep(...) GET_MACRO(__VA_ARGS__, drep3, drep2)(__VA_ARGS__)
template<typename T>inline bool smax(T&a, T b){if(a<b){a=b;return true;}return false;} 
template<typename T>inline bool smin(T&a, T b){if(a>b){a=b;return true;}return false;} 
/*}}}*/

LL a[200000], n;

int f(vector<LL>& v, int player) {
  LL s = 0;
  for (auto x : v) s += x;
  if ((n & 1) ^ (s & 1)) return player;
  if (s == n) return player ^ 1;
  int cnt = 0, idx = -1;
  rep(i, n) if (v[i] % 2 == 0) {
    cnt ++;
  } else idx = i;
  if (cnt == n - 1 && v[idx] > 1) {
    v[idx] --;
    LL x = v[0];
    rep(i, 1, n) x = __gcd(x, v[i]);
    auto newv = v;
    rep(i, n) newv[i] /= x;
    return f(newv, 1 ^ player);
  }
  return player ^ 1;
}
int main() {
  cin >> n;
  vector<LL> v;
  rep(i, n) cin >> a[i], v.pb(a[i]);

  cout << (vector<string>({"First", "Second"})[f(v, 0)]) << endl;

  return 0;
}
