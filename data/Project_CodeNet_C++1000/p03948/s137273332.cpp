#include <bits/stdc++.h>
using namespace std;

// clang-format off
#define fs first
#define sc second
#define pb emplace_back
#define mp make_pair
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define debug(x) cerr << "(" << __LINE__ << ")" << #x << ": " << (x) << endl

#define rep(i, n) for (int i = 0; i < (int)(n); ++(i))
#define reps(i, n) for (int i = 1; i <= (int)(n); ++(i))
#define rrep(i, n) for (int i = (int)(n) - 1; i >= 0; --(i))
#define rreps(i, n) for (int i = (int)(n); i > 0; --(i))

#define range(i, l, r) for (int i = (int)l; i < (int)(r); ++(i))
#define rrange(i, l, r) for (int i = ((int)(r) - 1); i >= (int)l; --(i))

#define whole(f,x,...) ([&](decltype((x)) whole) { return (f)(begin(whole), end(whole), ## __VA_ARGS__); })(x)
#define rwhole(f,x,...) ([&](decltype((x)) whole) { return (f)(rbegin(whole), rend(whole), ## __VA_ARGS__); })(x)

using int32 = int;
using int64 = long long;

constexpr int mod     = 1e9 + 7;
constexpr int32 inf   = 1001001001;
constexpr int64 infll = 1001001001001001001ll;
constexpr int dx[]    = {0, -1, 1, 0, -1, 1, -1, 1},
              dy[]    = {-1, 0, 0, 1, -1, -1, 1, 1};
const string YES = "YES", NO = "NO", Yes = "Yes", No = "No", yes = "yes", no = "no";

template <typename T> ostream &operator<<(ostream &os, vector<T> &v) { os << v[0]; for (int i = 1; i < v.size(); ++i) os << " " << v[i]; return os; }
template <typename T> istream &operator>>(istream &is, vector<T> &v) { for (T &in : v) is >> in; return is; }
template <typename T1, typename T2> ostream &operator<<(ostream &os, pair<T1, T2> p) { os << p.fs << " " << p.sc; return os; }
template <typename T1, typename T2> istream &operator>>(istream &is, pair<T1, T2> &p) { is >> p.fs >> p.sc; return is; }

struct IoSetup { IoSetup(){ cin.tie(0); ios::sync_with_stdio(0); cout << fixed << setprecision(10); cerr << fixed << setprecision(10); } } iosetup;

template<typename T = int64> T input() { T x; cin >> x; return x; }

template <typename T> vector<T> make_v(size_t a, T b) { return vector<T>(a, b); }
template <typename... Ts> auto make_v(size_t a, Ts... ts) { return vector<decltype(make_v(ts...))>(a, make_v(ts...)); }

template <typename T1, typename T2> inline bool chmax(T1 &a, T2 b) { return a < b && (a = b, true); }
template <typename T1, typename T2> inline bool chmin(T1 &a, T2 b) { return a > b && (a = b, true); }
// clang-format on

void solver() {
  int N = input(), T = input();
  vector<int> A(N);
  cin >> A;
  
  int diff = -inf;
  int min_A = A[0];
  int ans = 0;

  range(i, 1, N) {
    if (chmax(diff, (A[i] - min_A))) {
      ans = 1;
    } else if (diff == (A[i] - min_A)) {
      ans++;
    }

    chmin(min_A, A[i]);
  }

  cout << ans << endl;
}

signed main(int argc, char *argv[]) {
    solver();
}
