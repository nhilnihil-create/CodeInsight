#include <bits/stdc++.h>
using namespace std;

using P = pair<int, int>;
int k, t;
priority_queue<P> pq;

int main() {
  cin >> k >> t;
  for (int i = 0; i < t; ++i) {
    int a;
    cin >> a;
    pq.push(P(a, i));
  }
  int bf = -1, res = 0;
  for (int i = 0; i < k; ++i) {
    P now = pq.top();
    pq.pop();
    if (now.second == bf && pq.size()) {
      P dummy = pq.top();
      pq.pop();
      pq.push(now);
      now = dummy;
    }
    res += now.second == bf;
    bf = now.second;
    if (--now.first > 0) pq.push(now);
  }
  cout << res << endl;
  return 0;
}