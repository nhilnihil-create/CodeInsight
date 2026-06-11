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

int dfs(int cur, const vector<vi> &g) {
  if (g[cur].size() == 0)
    return 0;
  vi tmp;
  for (const auto v : g[cur]) {
    tmp.push_back(dfs(v, g));
  }
  sort(ALL(tmp));
  int ans = g[cur].size();
  int s = tmp.size();
  REP(i, s) { chmax(ans, s - i + tmp[i]); }
  return ans;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n;
  cin >> n;
  vector<vi> g(n);
  REP(i, n - 1) {
    int a;
    cin >> a;
    a--;
    g[a].push_back(i + 1);
  }

  cout << dfs(0, g) << endl;

  return 0;
}
