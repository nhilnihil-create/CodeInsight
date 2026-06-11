#include <bits/stdc++.h>
using namespace std;

long long n;
vector<set<int>> g;
vector<vector<long long>> v;
vector<long long> a, cnt;

bool solve();

int main() {
  cin >> n;
  a.resize(n);
  g.resize(n);
  v.resize(n);
  cnt.assign(n, 0);
  for (auto& p : a) cin >> p;
  for (int i = 1; i < n; ++i) {
    int x, y;
    cin >> x >> y;
    g[--x].insert(--y);
    g[y].insert(x);
    ++cnt[x];
    ++cnt[y];
  }
  if (solve())
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}

bool solve() {
  queue<long long> qu;
  for (int i = 0; i < n; ++i)
    if (cnt[i] == 1) qu.push(i);
  while (qu.size()) {
    int now = qu.front();
    qu.pop();
    long long sum = 0;
    for (auto p : v[now]) sum += p;
    sort(v[now].begin(), v[now].end(), greater<long long>());
    long long num = 0;
    if (v[now].size() > 1) {
      if (sum < a[now] || a[now] * 2 < sum || v[now][0] > a[now]) return 0;
      num = a[now] * 2 - sum;
    } else if (v[now].size() == 1) {
      if (sum != a[now]) return 0;
      num = a[now];
    } else
      num = a[now];
    if (cnt[now]) {
      int par = *g[now].begin();
      v[par].push_back(num);
      g[par].erase(now);
      if (--cnt[par] == 1) qu.push(par);
    } else {
      if (v[now].size() == 1)
        return a[now] == sum;
      else
        return a[now] * 2 == sum;
    }
  }
}