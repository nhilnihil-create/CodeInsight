
// Problem: D - ###
// Contest: AtCoder - AtCoder Regular Contest 071
// URL: https://atcoder.jp/contests/arc071/tasks/arc071_b
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll N = 1e6 + 5, mod = 1e9 + 7;

int n, m;
int x[N], y[N];

#define temptts template <class T, class... Ts>
temptts int add(T f) { return f; } temptts int add(T f, Ts... ts) { return (f + add(ts...)) % mod; }
temptts int sub(T f) { return f; } temptts int sub(T f, Ts... ts) { return (f - sub(ts...) + 1ll * mod * mod) % mod; }
temptts int mul(T f) { return f; } temptts int mul(T f, Ts... ts) { return (1ll * f * mul(ts...)) % mod; }

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> m;
  int sumx = 0, sumy = 0;
  for (int i = 1; i <= n; i++) {
    cin >> x[i];
    x[i] = (x[i] + mod) % mod;
    sumx = sub(sumx, mul(x[i], n - i));
  }
  for (int i = 1; i <= m; i++) {
    cin >> y[i];
    y[i] = (y[i] + mod) % mod;
    sumy = sub(sumy, mul(y[i], m - i));
  }
  for (int i = n; i >= 2; i--) {
    x[i] = add(x[i], x[i + 1]);
    sumx = add(sumx, x[i]);
  }
  for (int i = m; i >= 2; i--) {
    y[i] = add(y[i], y[i + 1]);
    sumy = add(sumy, y[i]);
  }
  cout << mul(sumx, sumy);
}