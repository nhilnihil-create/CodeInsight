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

template <class T> void say(bool val, T yes = "Yes", T no = "No") { cout << (val ? yes : no) << endl; }

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

  int n, c, k;
  cin >> n >> c >> k;
  vi t(n);
  REP(i, n) { cin >> t[i]; }
  sort(ALL(t));

  int ans = 0;
  int itr = 0;
  while (itr < n) {
    int next = upper_bound(ALL(t), t[itr] + k) - t.begin();
    if (next == itr) {
      itr++;
    } else {
      itr = next - itr > c ? itr + c : next;
    }
    ans++;
  }
  cout << ans << endl;

  return 0;
}
