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

template <typename T, typename U>
vector<U> make_vector(T&& n, U&& val) {
  return vector<U>(forward<T>(n), forward<U>(val));
}
template <typename T, typename... Args>
decltype(auto) make_vector(T&& n, Args&&... args) {
  return vector<decltype(make_vector(forward<Args>(args)...))>(forward<T>(n), make_vector(forward<Args>(args)...));
}

const int INF = 1001001001;
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

void solve() {
  int n, m;
  cin >> n >> m;
  vi32 a(n);
  cin >> a;
  rep(i, n) a[i]--;
  i64 all = 0;
  vi32 cnts(m * 2 + 1);
  vi64 sums(m * 2 + 1);
  vi64 imos(m * 2 + 1);
  using T = tuple<int, int>;
  vector<vector<T>> events(m * 2 + 1);
  rep(i, n - 1) {
    int l = a[i];
    int r = a[i + 1];
    if (l > r) r += m;
    sums[l + 1] += r - l;
    sums[r + 1] -= r - l;
    cnts[l + 1] += 1;
    cnts[r + 1] -= 1;
    all += r - l;
    events[l + 1].emplace_back(0, r - l - 1);
    events[r].emplace_back(1, 0);
  }
  i64 acc = 0;
  int cnt = 0;
  repc(i, m * 2) {
    for (auto p : events[i]) {
      int kind, diff;
      tie(kind, diff) = p;
      if (kind == 0) {
        acc += diff;
        cnt += 1;
      } else {
        cnt -= 1;
      }
    }
    imos[i] = acc;
    acc -= cnt;
  }
  rep(i, m * 2 - 1) {
    sums[i + 1] += sums[i];
    cnts[i + 1] += cnts[i];
  }
  i64 ans = 1e18;
  rep(chan, m) {
    i64 sum = all;
    sum -= sums[chan] + sums[chan + m];
    sum += cnts[chan] + cnts[chan + m];
    sum += imos[chan] + imos[chan + m];
    amin(ans, sum);
  }
  cout << ans << endl;
}
