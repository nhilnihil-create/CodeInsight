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
#define bit(b) (1ll << (b))
#define uniq(v) (v).erase(unique(all(v)), (v).end())

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
inline i64 lcm(i64 a, i64 b) { return a / gcd(a, b) * b; }
void solve(); int main() { ios::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(16); solve(); return 0; }
template <typename T> class pqasc : public priority_queue<T, vector<T>, greater<T>> {};
template <typename T> class pqdesc : public priority_queue<T, vector<T>, less<T>> {};
template <typename T> inline void amax(T &x, T y) { if (x < y) x = y; }
template <typename T> inline void amin(T &x, T y) { if (x > y) x = y; }
template <typename T> inline T power(T x, i64 n, T e = 1) { T r = e; while (n > 0) { if (n & 1) r *= x; x *= x; n >>= 1; } return r; }
template <typename T> istream& operator>>(istream &is, vector<T> &v) { each(x, v) is >> x; return is; }
template <typename T> ostream& operator<<(ostream &os, vector<T> &v) { rep(i, v.size()) { if (i) os << ' '; os << v[i]; } return os; }
template <typename T, typename S> istream& operator>>(istream &is, pair<T, S> &p) { is >> p.first >> p.second; return is; }
template <typename T, typename S> ostream& operator<<(ostream &os, pair<T, S> &p) { cout << p.first << ' ' << p.second; return os; }

void solve() {
  pqasc<int> fr;
  pqasc<pair<int, int>> md;

  int N; cin >> N;
  vi32 a(3 * N); cin >> a;

  i64 fsum = 0, bsum = 0;
  vector<bool> used(3 * N);
  rep(i, N) fr.push(a[i]), fsum += a[i];
  {
    for (int i = N; i < 3 * N; i++) md.push(make_pair(a[i], i));
    rep(i, N) {
      auto p = md.top(); md.pop();
      bsum += p.first;
      used[p.second] = true;
    }
  }

  i64 ans = fsum - bsum;
  for (int i = N; i < 2 * N; i++) {
    if (fr.top() < a[i]) {
      fsum = fsum - fr.top() + a[i];
      fr.pop(), fr.push(a[i]);
    }
    if (used[i]) {
      bsum -= a[i];
      int idx;
      while (true) {
        int v, j;
        tie(v, j) = md.top(), md.pop();
        if (j > i) { idx = j; break; }
      }
      used[idx] = true;
      bsum += a[idx];
    }
    amax(ans, fsum - bsum);
  }
  cout << ans << '\n';
}
