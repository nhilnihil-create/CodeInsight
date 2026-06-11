#ifndef TEMPLATE_HPP
#define TEMPLATE_HPP
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
template <typename T> class pqasc : public priority_queue<T, vector<T>, greater<T>> {};
template <typename T> class pqdesc : public priority_queue<T, vector<T>, less<T>> {};
template <typename T> void chmax(T &x, T y) { x = max(x, y); }
template <typename T> void chmin(T &x, T y) { x = min(x, y); }
template <typename T> T power(T x, i64 n, T e = 1) { T r = e; while (n > 0) { if (n & 1) r *= x; x *= x; n >>= 1; } return r; }
template <typename T> istream& operator>>(istream &is, vector<T> &v) { for (auto &x : v) is >> x; return is; }
template <typename T> ostream& operator<<(ostream &os, vector<T> &v) { rep(i, v.size()) { if (i) os << ' '; os << v[i]; } return os; }
template <typename T, typename U> vector<U> make_vector(T&& n, U&& val) { return vector<U>(forward<T>(n), forward<U>(val)); }
template <typename T, typename... Args> decltype(auto) make_vector(T&& n, Args&&... args) { return vector<decltype(make_vector(forward<Args>(args)...))>(forward<T>(n), make_vector(forward<Args>(args)...)); }
const int INF = 1001001001;
const i64 LINF = 1001001001001001001ll;
const int dx[] = {1, 0, -1, 0, 1, 1, -1, -1};
const int dy[] = {0, 1, 0, -1, 1, -1, 1, -1};
#endif

void solve() {
  int n, x;
  cin >> n >> x;
  int m = 2 * n - 1;
  if (x == 1 || x == m) {
    cout << "No" << endl;
    return;
  }
  if (n == 2) {
    cout << "Yes" << endl;
    cout << 1 << endl;
    cout << 2 << endl;
    cout << 3 << endl;
    return;
  }
  vi32 ans(m);
  vi32 used(m + 1);
  if (x != m - 1) {
    ans[n-2]=x+0, used[x+0]=1;
    ans[n-1]=x-1, used[x-1]=1;
    ans[n-3]=x+1, used[x+1]=1;
    ans[n-0]=x+2, used[x+2]=1;
  } else {
    ans[n-2]=x+0, used[x+0]=1;
    ans[n-1]=x+1, used[x+1]=1;
    ans[n-3]=x-1, used[x-1]=1;
    ans[n-0]=x-2, used[x-2]=1;
  }
  int num = 1;
  rep(i, m) if (ans[i] == 0) {
    while (used[num]) num++;
    ans[i]=num, used[num]=1;
  }
  cout << "Yes" << endl;
  rep(i, m) cout << ans[i] << '\n';
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(16);
  cerr << fixed << setprecision(16);
  solve();
  return 0;
}