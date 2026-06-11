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

  int n, x;
  cin >> n >> x;
  if (x == 1 || x == 2 * n - 1) {
    cout << "No" << endl;
    return 0;
  } else {
    cout << "Yes" << endl;
  }

  vi ans(2 * n - 1, 0), used(2 * n);
  used[0] = true;
  ans[n - 1] = x;
  used[x] = true;
  ans[n - 2] = 1;
  used[1] = true;
  ans[n] = 2 * n - 1;
  used[2 * n - 1] = true;
  if (n > 2) {
    REP(i, 2 * n - 1) {
      if (used[i])
        continue;
      if (i < x)
        ans[n + 1] = i;
      else
        ans[n - 3] = i;
      used[i] = true;
      break;
    }

    int idx = 0;
    REP(i, 2 * n - 1) {
      if (used[i])
        continue;
      while (ans[idx] != 0)
        idx++;
      ans[idx] = i;
    }
  }

  REP(i, 2 * n - 1) { cout << ans[i] << endl; }
  return 0;
}
