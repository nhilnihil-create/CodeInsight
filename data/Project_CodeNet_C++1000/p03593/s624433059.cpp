#include <bits/stdc++.h>
#include <type_traits>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rrep(i, n) for (int i = 1; i <= (n); ++i)
#define drep(i, n) for (int i = (n)-1; i >= 0; --i)
#define ddrep(i, n) for (int i = n; i > 0; --i)
#define srep(i, s, t) for (int i = s; i < t; ++i)
#define ssrep(i, s, t) for (int i = s; i <= t; ++i)

#define rng(a) a.begin(), a.end()
#define pb push_back
#define eb emplace_back
#define fi first
#define se second

#define chmax(x, y) (x = max(x, y))
#define chmin(x, y) (x = min(x, y))

using pi = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using ld = long double;

template <class T, class U>
ostream &operator<<(ostream &os, const pair<T, U> &p) {
  os << "(" << p.first << "," << p.second << ")";
  return os;
}

template <class T> ostream &operator<<(ostream &os, const vector<T> &v) {
  os << "{";
  rep(i, (int)v.size()) {
    if (i)
      os << ",";
    os << v[i];
  }
  os << "}";
  return os;
}

template <typename T, size_t S> void printArray(const T (&array)[S]) {
  for (auto val : array)
    std::cout << val << ", ";
  std::cout << "\n";
}

const int mod = 1e9 + 7;
const int inf = 1e9 + 5;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << std::setprecision(10);

  int h, w; std::cin >> h >> w;
  vector<string> grid(h); rep(i, h) std::cin >> grid[i];
  int hh = (h+1)/2, ww = (w+1)/2;
  map<int, int> need;
  rep(i, hh) rep(j, ww) {
    int cnt = 1;
    if (h-i > i+1) cnt++;
    if (w-j > j+1) cnt++;
    if (cnt == 3) cnt++;
    need[cnt]++;
  }
  vi cnt(26);
  rep(i, h) rep(j, w) cnt[grid[i][j]-'a']++;
  int s4 = 0, s2 = 0, s1 = 0;
  rep(i, 26) {
    s4 += cnt[i] / 4;
    cnt[i] -= (cnt[i] / 4) * 4;
    s2 += cnt[i] / 2;
    cnt[i] -= (cnt[i] / 2) * 2;
    s1 += cnt[i];
  }
  bool ok = true;
  if (s4 < need[4]) ok = false;
  else s2 += (s4-need[4]) * 2;
  if (s2 < need[2]) ok = false;
  else s1 += (s2-need[2]) * 2;
  if (s1 < need[1]) ok = false;
  std::cout << (ok ? "Yes" : "No") << "\n";
}
