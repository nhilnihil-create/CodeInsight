#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n * 3);
  for (int i = 0; i < n * 3; i++) {
    cin >> a[i];
  }
  vector<ll> left(n + 1), right(n + 1);
  priority_queue<ll, vector<ll>, greater<ll>> q;
  ll sum = 0;
  for (int i = 0; i < n; i++) {
    sum += a[i];
    q.push(a[i]);
  }
  left[0] = sum;
  for (int i = n; i < n * 2; i++) {
    q.push(a[i]);
    int v = q.top();
    q.pop();
    sum = sum + a[i] - v;
    left[i - n + 1] = sum;
  }
  auto r = priority_queue<ll, vector<ll>, less<ll>>();
  sum = 0;
  for (int i = n * 3 - 1; i >= n * 2; i--) {
    sum += a[i];
    r.push(a[i]);
  }
  right[n] = sum;
  for (int i = n * 2 - 1; i >= n; i--) {
    r.push(a[i]);
    int v = r.top();
    r.pop();
    sum = sum + a[i] - v;
    right[i - n] = sum;
  }
  ll ans = -1e18;
  for (int i = 0; i <= n; i++) {
    ans = max(ans, left[i] - right[i]);
  }
  cout << ans << endl;
  return 0;
}