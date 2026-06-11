#include <bits/stdc++.h>
using namespace std;

using P = pair<long long, long long>;
long long r, c;
vector<long long> p, q;
priority_queue<P, vector<P>, greater<P>> pq;

long long solve();

int main() {
  cin >> r >> c;
  p.resize(r);
  q.resize(c);
  for (auto &x : p) cin >> x;
  for (auto &x : q) cin >> x;
  cout << solve() << endl;
  return 0;
}

long long solve() {
  long long res = 0, cnt[2] = {c + 1, r + 1};
  for (auto x : p) pq.push(P(x, 0));
  for (auto x : q) pq.push(P(x, 1));
  while (pq.size()) {
    P now = pq.top();
    pq.pop();
    res += now.first * cnt[now.second];
    --cnt[1 - now.second];
  }
  return res;
}