#line 1 "/mnt/c/Users/leafc/dev/compro/lib/template.hpp"


#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < n; i++)
#define FOR(i, m, n) for (int i = m; i < n; i++)
#define ALL(v) (v).begin(), (v).end()
#define coutd(n) cout << fixed << setprecision(n)
#define ll long long int
#define vl vector<ll>
#define vi vector<int>
#define MM << " " <<

using namespace std;

template <class T> void say(bool val, T yes = "Yes", T no = "No") { cout << (val ? yes : no) << "\n"; }

template <class T> void chmin(T &a, T b) {
  if (a > b)
    a = b;
}

template <class T> void chmax(T &a, T b) {
  if (a < b)
    a = b;
}


#line 2 "tmp.cpp"

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n, k;
  cin >> n >> k;
  vl a(n);
  REP(i, n) { cin >> a[i]; }
  vl cum(n + 1, 0), plus(n + 1, 0);
  REP(i, n) {
    cum[i + 1] = cum[i] + a[i];
    plus[i + 1] = plus[i] + max(a[i], 0LL);
  }
  ll ans = 0;
  FOR(i, 1, n - k + 2) {
    ll tmp = plus[i - 1] + (plus[n] - plus[i + k - 1]) + max(cum[i + k - 1] - cum[i - 1], 0LL);
    chmax(ans, tmp);
  }

  cout << ans << endl;

  return 0;
}
