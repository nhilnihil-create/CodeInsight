#include <bits/stdc++.h>
using namespace std;
using PP = pair<long, long>;
const int INF = 1e9;
template <class T> T Next() { T buf; cin >> buf; return buf; }

int n;
long p[100000];
vector<int> g[100000];
vector<long> f[100000];

long rec(int from, int prev) {
  if (prev != -1 && g[from].size() == 1) {
    f[from].push_back(p[from]);
    return p[from];
  }
  
  long ret = 2 * p[from];
  for (int to : g[from]) {
    if (to == prev) continue;
    long res = rec(to, from);
    f[from].push_back(res);
    ret -= res;
  }
  
  if (prev != -1) {
    f[from].push_back(ret);
  }
  return ret;
}

bool sub() {
  const int start = 0;
  long res = rec(start, -1);
  if (g[start].size() == 1) {
    if (res != p[start]) return false;
  } else {
    if (res != 0) return false;
  }
  
  for (int i = 0; i < n; ++i) {
    if (f[i].size() == 1) continue;
    sort(f[i].rbegin(), f[i].rend());
    if (f[i].back() < 0) return false;
    long sum = accumulate(f[i].begin() + 1, f[i].end(), 0ll);
    if (f[i].front() > sum) return false;
  }
  return true;
}

int main() {
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> p[i];
  for (int i = 1; i < n; ++i) {
    int a, b;
    cin >> a >> b;
    --a; --b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  cout << (sub() ? "YES" : "NO") << endl;
  return 0;
}