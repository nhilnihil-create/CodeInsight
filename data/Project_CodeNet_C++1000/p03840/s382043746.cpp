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

  ll i, o, t, j, l, s, z;
  cin >> i >> o >> t >> j >> l >> s >> z;
  ll ans = o + 2 * (i / 2) + 2 * (j / 2) + 2 * (l / 2);
  if (i >= 1 && j >= 1 && l >= 1)
    chmax(ans, o + 2 * ((i - 1) / 2) + 2 * ((j - 1) / 2) + 2 * ((l - 1) / 2) + 3);
  cout << ans << endl;
  return 0;
}
