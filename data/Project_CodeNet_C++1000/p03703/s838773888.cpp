#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < int(n); i++)
#define rrep(i, n) for (int i = int(n) - 1; i >= 0; i--)
#define reps(i, n) for (int i = 1; i <= int(n); i++)
#define rreps(i, n) for (int i = int(n); i >= 1; i--)
#define repc(i, n) for (int i = 0; i <= int(n); i++)
#define rrepc(i, n) for (int i = int(n); i >= 0; i--)
#define repi(i, a, b) for (int i = int(a); i < int(b); i++)
#define repic(i, a, b) for (int i = int(a); i <= int(b); i++)
#define all(a) (a).begin(), (a).end()
#define bit32(x) (1 << (x))
#define bit64(x) (1ll << (x))
#define sz(v) ((int) v.size())

using namespace std;

using i64 = long long;
using f80 = long double;
using vi32 = vector<int>;
using vi64 = vector<i64>;
using vf80 = vector<f80>;
using vstr = vector<string>;

void yes() { cout << "Yes" << endl; exit(0); }
void no() { cout << "No" << endl; exit(0); }
template <typename T> class pqasc : public priority_queue<T, vector<T>, greater<T>> {};
template <typename T> class pqdesc : public priority_queue<T, vector<T>, less<T>> {};
template <typename T> void amax(T &x, T y) { x = max(x, y); }
template <typename T> void amin(T &x, T y) { x = min(x, y); }
template <typename T> T exp(T x, i64 n, T e = 1) { T r = e; while (n > 0) { if (n & 1) r *= x; x *= x; n >>= 1; } return r; }
template <typename T> istream& operator>>(istream &is, vector<T> &v) { for (auto &x : v) is >> x; return is; }
template <typename T> ostream& operator<<(ostream &os, vector<T> &v) { rep(i, v.size()) { if (i) os << ' '; os << v[i]; } return os; }
void solve(); int main() { ios::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(16); solve(); return 0; }

const int INF = 1001001001;
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

template <typename T>
struct FenwickTree {
  vector<T> v;
  int n;
  FenwickTree(int n) : n(n) {
    v = vector<T>(n);
  }
  void update(int i, T x) {
    for (i++; i <= n; i += i & -i) v[i - 1] += x;
  }
  T query(int i) {
    T r = 0;
    for (; i >= 1; i -= i & -i) r += v[i - 1];
    return r;
  }
};

void solve() {
  int n, k;
  cin >> n >> k;
  vi32 a(n);
  cin >> a;
  vi32 b(n);
  rep(i, n) b[i] = a[i] - k;
  using P = pair<i64, int>;
  vector<P> v;
  i64 sum = 0;
  rep(i, n) {
    sum += b[i];
    v.emplace_back(sum, i);
  }
  sort(all(v), [&](P a, P b) {
    return a.first < b.first;
  });
  map<int, int> mp;
  rep(i, n) mp[v[i].second] = i;
  FenwickTree<int> ft(n);
  rep(i, n) ft.update(i, 1);
  i64 ans = 0;
  i64 tar = 0;
  rep(i, n) {
    int ok = n, ng = -1;
    while (abs(ok - ng) != 1) {
      int md = (ok + ng) / 2;
      (v[md].first >= tar ? ok : ng) = md;
    }
    ans += ft.query(n) - ft.query(ok);
    ft.update(mp[i], -1);
    tar += b[i];
  }
  cout << ans << endl;
}
