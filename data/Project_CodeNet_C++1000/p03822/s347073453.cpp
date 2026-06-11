#include <bits/stdc++.h>
using namespace std;

long long n;
vector<int> a, cnt, dep;
vector<vector<int>> memo;
queue<int> qu;

int main() {
  cin >> n;
  a.resize(n);
  cnt.assign(n, 0);
  dep.assign(n, 1);
  memo.resize(n);
  for (int i = 1; i < n; ++i) {
    cin >> a[i];
    ++cnt[--a[i]];
  }
  for (int i = 1; i < n; ++i)
    if (cnt[i] == 0) qu.push(i);
  int res = 1;
  while (qu.size()) {
    int now = qu.front();
    qu.pop();
    sort(memo[now].begin(), memo[now].end(), greater<int>());
    int len = memo[now].size(), nmax = 1;
    for (int i = 0; i < len; ++i) nmax = max(nmax, memo[now][i] + i + 1);
    dep[now] = nmax;
    res = max(res, dep[now]);
    memo[a[now]].push_back(nmax);
    if (--cnt[a[now]] == 0) qu.push(a[now]);
  }
  cout << res - 1 << endl;

  return 0;
}
