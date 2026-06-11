#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int N; cin >> N;
  priority_queue<pair<int, int>> q;
  for (int i = 0; i < N; i++) {
    int x; cin >> x; q.emplace(x, i);
  }
  q.emplace(0, -1);
  priority_queue<int, vector<int>, greater<int>> index;
  vector<ll> res(N);
  while (q.top().first) {
    ll c = q.top().first;
    while (q.top().first == c) {
      index.push(q.top().second);
      q.pop();
    }
    res[index.top()] += (c - q.top().first) * ll(index.size());
  }
  for (int i = 0; i < N; i++) cout << res[i] << endl;
}
