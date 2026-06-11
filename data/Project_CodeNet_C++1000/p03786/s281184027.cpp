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

bool f(int x, vl &a) {
  ll s = a[x];
  int n = a.size();
  for (int i = n - 1; i >= 0; i--) {
    if (i == x)
      continue;
    if (a[i] <= 2 * s) {
      s += a[i];
    } else {
      return false;
    }
  }
  return true;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n;
  cin >> n;
  vl a(n);
  REP(i, n) { cin >> a[i]; }
  sort(a.rbegin(), a.rend());
  if (!f(0, a)) {
    cout << 0 << endl;
    return 0;
  }
  int ok = 0;
  int ng = n;
  while (abs(ok - ng) > 1) {
    int mid = (ok + ng) / 2;
    if (f(mid, a)) {
      ok = mid;
    } else {
      ng = mid;
    }
  }
  cout << ok + 1 << endl;
  return 0;
}
