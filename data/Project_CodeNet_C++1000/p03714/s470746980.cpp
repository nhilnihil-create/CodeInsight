#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int N;
  cin >> N;
  vector<ll> a(N * 3);
  for (int i = 0; i < N * 3; ++i) cin >> a[i];

  vector<ll> mx(3 * N + 1), mn(3 * N + 1);
  {
    priority_queue<ll, vector<ll>, greater<ll>> pq1;
    ll acc = 0;
    for (int i = 0; i < N; ++i) {
      pq1.push(a[i]);
      acc += a[i];
    }
    mx[N] = acc;
    for (int i = N; i < 3 * N; ++i) {
      acc -= pq1.top();
      acc += a[i];
      pq1.pop();
      pq1.push(a[i]);
      mx[i + 1] = max(mx[i], acc);
    }
  }

  {
    priority_queue<ll, vector<ll>, less<ll>> pq2;
    ll acc = 0;
    for (int i = 0; i < N; ++i) {
      pq2.push(a[3 * N - 1 - i]);
      acc += a[3 * N - 1 - i];
    }
    mn[2 * N] = acc;
    for (int i = 2 * N - 1; i >= 0; --i) {
      acc -= pq2.top();
      acc += a[i];
      pq2.pop();
      pq2.push(a[i]);
      mn[i] = min(mn[i + 1], acc);
    }
  }

  ll ans = -1e18;
  for (int i = N; i < 2 * N + 1; ++i) {
    ans = max(ans, mx[i] - mn[i]);
  }

  cout << ans << endl;

  return 0;
}
