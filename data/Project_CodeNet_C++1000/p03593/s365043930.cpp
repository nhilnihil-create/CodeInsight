#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < int(n); i++)
#define rrep(i, n) for (int i = int(n) - 1; i >= 0; i--)
#define reps(i, n) for (int i = 1; i <= int(n); i++)
#define rreps(i, n) for (int i = int(n); i >= 1; i--)
#define repc(i, n) for (int i = 0; i <= int(n); i++)
#define rrepc(i, n) for (int i = int(n); i >= 0; i--)
#define repi(i, a, b) for (int i = int(a); i < int(b); i++)
#define repic(i, a, b) for (int i = int(a); i <= int(b); i++)
#define each(x, y) for (auto &x : y)
#define all(a) (a).begin(), (a).end()
#define bit32(x) (1 << (x))
#define bit64(x) (1ll << (x))

using namespace std;

using i32 = int;
using i64 = long long;
using f80 = long double;
using vi32 = vector<i32>;
using vi64 = vector<i64>;
using vf80 = vector<f80>;
using vstr = vector<string>;

inline void yes() { cout << "Yes" << '\n'; exit(0); }
inline void no() { cout << "No" << '\n'; exit(0); }
inline i64 gcd(i64 a, i64 b) { if (min(a, b) == 0) return max(a, b); if (a % b == 0) return b; return gcd(b, a % b); }
inline i64 lcm(i64 a, i64 b) { if (min(a, b) == 0) return max(a, b); return a / gcd(a, b) * b; }
template <typename T> class pqasc : public priority_queue<T, vector<T>, greater<T>> {};
template <typename T> class pqdesc : public priority_queue<T, vector<T>, less<T>> {};
template <typename T> inline void amax(T &x, T y) { if (x < y) x = y; }
template <typename T> inline void amin(T &x, T y) { if (x > y) x = y; }
template <typename T> inline T exp(T x, i64 n, T e = 1) { T r = e; while (n > 0) { if (n & 1) r *= x; x *= x; n >>= 1; } return r; }
template <typename T> istream& operator>>(istream &is, vector<T> &v) { each(x, v) is >> x; return is; }
template <typename T> ostream& operator<<(ostream &os, vector<T> &v) { rep(i, v.size()) { if (i) os << ' '; os << v[i]; } return os; }
void solve(); int main() { ios::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(16); solve(); return 0; }

void solve() {
  int h, w;
  cin >> h >> w;
  vstr a(h);
  cin >> a;
  vstr out(h);
  rep(i, h) out[i] = string(w, '-');
  vi32 cnt(26);
  rep(i, h) rep(j, w) cnt[a[i][j] - 'a']++;
  rep(i, h) rep(j, w) {
    set<pair<int, int>> se;
    se.emplace(i, j);
    se.emplace(i, w - j - 1);
    se.emplace(h - i - 1, j);
    se.emplace(h - i - 1, w - j - 1);
    int c = 0;
    each(p, se) {
      if (out[p.first][p.second] == '-') c++;
    }
    if (c == 0) continue;
    bool ok = false;
    rep(k, 26) {
      if (cnt[k] == 0) continue;
      if (c == 1 && cnt[k] % 4 == 1 ||
          c == 2 && cnt[k] % 4 == 2 ||
          c == 4 && cnt[k] % 4 == 0) {
        ok = true;
        cnt[k] -= c;
        each(p, se) {
          out[p.first][p.second] = (char) (k + 'a');
        }
        break;
      }
    }
    if (ok) continue;
    rep(k, 26) {
      if (cnt[k] >= c) {
        ok = true;
        cnt[k] -= c;
        each(p, se) {
          out[p.first][p.second] = (char) (k + 'a');
        }
        break;
      }
    }
    if (!ok) no();
  }
  yes();
}
