#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> x, id, res, cnt;
queue<int> qu;

bool solve();

int main() {
  cin >> n;
  x.resize(n);
  cnt.assign(n, 0);
  for (auto& p : x) cin >> p;
  for (int i = 0; i < n; ++i) id.push_back(i);
  sort(id.begin(), id.end(), [](int l, int r) { return x[l] < x[r]; });
  if (solve()) {
    cout << "Yes" << endl;
    for (int i = 0; i < (n * n); ++i) cout << res[i] << " \n"[i == (n * n) - 1];
  } else
    cout << "No" << endl;
  return 0;
}

bool solve() {
  for (int i = 0; i < n; ++i) {
    int now = id[i];
    for (int j = 0; j < now; ++j) qu.push(now + 1);
  }
  for (int i = 0; i < n; ++i) {
    int now = id[i];
    while (res.size() + 1 < x[now]) {
      if (qu.empty()) return 0;
      res.push_back(qu.front());
      ++cnt[qu.front() - 1];
      qu.pop();
    }
    if (res.size() + 1 != x[now] || cnt[now] != now) return 0;
    res.push_back(now + 1);
    for (int j = 0; j < n - now - 1; ++j) qu.push(now + 1);
  }
  while (qu.size()) {
    res.push_back(qu.front());
    qu.pop();
  }
  return 1;
}