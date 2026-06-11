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

  int n;
  cin >> n;
  vi p(n);
  REP(i, n) {
    cin >> p[i];
    p[i]--;
  }

  vi a(n), b(n);
  REP(i, n) {
    a[i] = (i + 1) * n;
    b[i] = (n - i) * n;
  }

  REP(i, n) { a[p[i]] += i; }

  REP(i, n) { cout << a[i] << (i == n - 1 ? "\n" : " "); }
  REP(i, n) { cout << b[i] << (i == n - 1 ? "\n" : " "); }
  return 0;
}
