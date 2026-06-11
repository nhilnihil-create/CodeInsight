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
using u64 = unsigned long long;
using f80 = long double;
using vi32 = vector<i32>;
using vi64 = vector<i64>;
using vu64 = vector<u64>;
using vf80 = vector<f80>;
using vstr = vector<string>;

inline void yes() { cout << "Yes" << '\n'; exit(0); }
inline void no() { cout << "No" << '\n'; exit(0); }
inline i64 gcd(i64 a, i64 b) { if (min(a, b) == 0) return max(a, b); if (a % b == 0) return b; return gcd(b, a % b); }
inline i64 lcm(i64 a, i64 b) { if (min(a, b) == 0) return max(a, b); return a / gcd(a, b) * b; }
inline u64 xorshift() { static u64 x = 88172645463325252ull; x = x ^ (x << 7); return x = x ^ (x >> 9); }
template <typename T> class pqasc : public priority_queue<T, vector<T>, greater<T>> {};
template <typename T> class pqdesc : public priority_queue<T, vector<T>, less<T>> {};
template <typename T> inline void amax(T &x, T y) { if (x < y) x = y; }
template <typename T> inline void amin(T &x, T y) { if (x > y) x = y; }
template <typename T> inline T exp(T x, i64 n, T e = 1) { T r = e; while (n > 0) { if (n & 1) r *= x; x *= x; n >>= 1; } return r; }
template <typename T> inline T bis(T ok, T ng, function<bool(T)> f, T eps = 1) { while (abs(ok - ng) > eps) { T mi = (ok + ng) / 2; (f(mi) ? ok : ng) = mi; } return ok; }
template <typename T> istream& operator>>(istream &is, vector<T> &v) { each(x, v) is >> x; return is; }
template <typename T> ostream& operator<<(ostream &os, vector<T> &v) { rep(i, v.size()) { if (i) os << ' '; os << v[i]; } return os; }
void solve(); int main() { ios::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(16); solve(); return 0; }

void solve() {
  int n, m;
  cin >> n >> m;
  vi32 cnt(100001);
  vi32 x(n);
  rep(i, n) {
    int x;
    cin >> x;
    cnt[x]++;
  }
  vector<queue<int>> qodd(m);
  vector<queue<int>> qeven(m);
  rep(i, 100001) {
    if (cnt[i] == 0) continue;
    if (cnt[i] % 2 == 1) {
      qodd[i % m].emplace(cnt[i]);
    } else {
      qeven[i % m].emplace(cnt[i]);
    }
  }
  int ans = 0;
  repc(i, m / 2) {
    int j = (m - i) % m;
    while (true) {
      int a = -1, b = -1;
      if (qodd[i].size()) a = qodd[i].front(), qodd[i].pop();
      if (qodd[j].size()) b = qodd[j].front(), qodd[j].pop();
      if (a != -1 && b != -1) {
        ans++;
        if (a - 1 != 0) qeven[i].emplace(a - 1);
        if (b - 1 != 0) qeven[j].emplace(b - 1);
      } else if (a != -1) {
        int c = -1;
        if (qeven[j].size()) c = qeven[j].front(), qeven[j].pop();
        if (c != -1) {
          ans++;
          qodd[j].emplace(c - 1);
        }
        if (a - 1 != 0) qeven[i].emplace(a - 1);
      } else if (b != -1) {
        int c = -1;
        if (qeven[i].size()) c = qeven[i].front(), qeven[i].pop();
        if (c != -1) {
          ans++;
          qodd[i].emplace(c - 1);
        }
        if (b - 1 != 0) qeven[j].emplace(b - 1);
      } else {
        break;
      }
    }
    while (qeven[i].size()) ans += qeven[i].front() / 2, qeven[i].pop();
    while (qeven[j].size()) ans += qeven[j].front() / 2, qeven[j].pop();
  }
  cout << ans << endl;
}
