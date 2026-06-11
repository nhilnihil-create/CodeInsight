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

bool check1(deque<int> &path, vector<vi> &g, set<int> &s) {
  for (const auto v : g[path[0]]) {
    if (s.find(v) == s.end()) {
      path.push_front(v);
      s.insert(v);
      return false;
    }
  }
  return true;
}

bool check2(deque<int> &path, vector<vi> &g, set<int> &s) {
  for (const auto v : g[path[path.size() - 1]]) {
    if (s.find(v) == s.end()) {
      path.push_back(v);
      s.insert(v);
      return false;
    }
  }
  return true;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n, m;
  cin >> n >> m;
  vector<vi> g(n);
  REP(i, m) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  deque<int> path;
  set<int> set;
  path.push_back(0);
  path.push_back(g[0][0]);
  set.insert(0);
  set.insert(g[0][0]);

  while (true) {
    if (check1(path, g, set) && check2(path, g, set))
      break;
  }

  int s = path.size();
  cout << s << endl;
  REP(i, s) { cout << path[i] + 1 << (i == s - 1 ? "\n" : " "); }

  return 0;
}
