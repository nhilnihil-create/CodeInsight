#include <bits/stdc++.h>
using namespace std;

using P = pair<long long, long long>;
long long n;
vector<long long> a, res;
vector<P> v;

void solve();

int main() {
  cin >> n;
  a.resize(n);
  for (auto& p : a) cin >> p;
  solve();
  for (auto p : res) cout << p << endl;
  return 0;
}

void solve() {
  for (int i = 0; i < n; ++i) v.push_back(P(a[i], i));
  v.push_back(P(0, n));
  res.assign(n, 0);
  sort(v.begin(), v.end(), greater<P>());
  long long now = n + 1;
  for (int i = 0; i < n; ++i) {
    now = min(now, v[i].second);
    res[now] += (i + 1) * (v[i].first - v[i + 1].first);
  }
}