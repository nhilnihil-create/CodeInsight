#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = (int) 2e5 + 7;
int n, a[N], t[4 * N];
ll dp[N];

void build(int v, int tl, int tr) {
  if (tl == tr) {
    t[v] = a[tl];
  } else {
    int tm = (tl + tr) / 2;
    build(2 * v, tl, tm);
    build(2 * v + 1, tm + 1, tr);
    t[v] = min(t[2 * v], t[2 * v + 1]);
  }
}

int get(int v, int tl, int tr, int l, int r) {
  if (tr < l || r < tl) {
    return (int) 1e9;
  }
  if (l <= tl && tr <= r) {
    return t[v];
  }
  int tm = (tl + tr) / 2;
  return min(get(2 * v, tl, tm, l, r), get(2 * v + 1, tm + 1, tr, l, r));
}

int get(int l, int r) {
  return get(1, 1, n, l, r);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  build(1, 1, n);
  ll sol = 0;
  for (int i = n; i >= 1; i--) {
    int l = i + 1, r = n, ans = i;
    while (l <= r) {
      int m = (l + r) / 2;
      if (get(i, m) == a[i]) {
        ans = m;
        l = m + 1;
      } else {
        r = m - 1;
      }
    }
    dp[i] = (ll) a[i] * (ans - i + 1) + dp[ans + 1];
    sol += dp[i];
  }
  cout << sol << "\n";


}
