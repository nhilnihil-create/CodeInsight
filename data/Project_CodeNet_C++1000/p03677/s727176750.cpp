#include <bits/stdc++.h>
#define inf (long long)(1e17)
using namespace std;
using P = pair<int, int>;

long long n, m;
vector<long long> a;
vector<vector<long long>> l, r;

long long solve();

int main() {
  cin >> n >> m;
  a.resize(n);
  for (auto &p : a) cin >> p;
  cout << solve() << endl;
  return 0;
}

long long solve() {
  long long res = 0, sum = 0, now = 0, cnt = 0;
  for (auto &p : a) --p;
  l.resize(m);
  r.resize(m);
  for (int i = 1; i < n; ++i) {
    long long nowl = (a[i - 1] + 1) % m, nowr = a[i];
    l[nowr].push_back(nowl);
    r[nowl].push_back(nowr);
    sum += (nowr + m - nowl + 1) % m;
    if (a[i - 1] > a[i]) now += m - 1 - a[i - 1], cnt += (a[i - 1] != m - 1);
  }
  for (int i = 0; i < m; ++i) {
    res = max(res, now);
    for (auto p : l[i]) {
      now -= (i + m - p) % m;
      --cnt;
    }
    cnt += r[i].size();
    now += cnt;
  }
  return sum - res;
}