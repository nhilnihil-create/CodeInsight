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
  vl a(n);
  map<int, ll> cnt;
  map<int, int> idx;
  REP(i, n) {
    cin >> a[i];
    if (idx.find(a[i]) == idx.end()) {
      idx[a[i]] = i;
    }
    cnt[a[i]]++;
  }

  sort(a.rbegin(), a.rend());
  a.erase(unique(a.begin(), a.end()), a.end());

  int s = a.size();
  vl ans(n, 0);

  ll now = cnt[a[0]];
  int now_idx = idx[a[0]];

  FOR(i, 1, s) {
    ans[now_idx] += (a[i - 1] - a[i]) * now;
    now += cnt[a[i]];
    chmin(now_idx, idx[a[i]]);
  }

  ans[0] += a[s - 1] * now;

  REP(i, n) { cout << ans[i] << endl; }

  return 0;
}
