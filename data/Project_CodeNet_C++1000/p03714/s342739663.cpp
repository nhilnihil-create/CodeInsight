// review
#include <iostream>
#include <queue>
#include <algorithm>
#include <functional>
#include <vector>

using namespace std;
typedef long long ll;
int n;
ll a[300010];
ll former[100010], latter[100010];

void solve() {
  priority_queue<ll, vector<ll>, greater<ll> > pq;
  priority_queue<ll> pq2;
  ll sum = 0;
  for (int i=0;i<n;i++) {
    pq.push(a[i]);
    sum += a[i];
  }
  former[0] = sum;
  for (int i=n;i<2*n;i++) {
    pq.push(a[i]);
    sum -= pq.top();
    pq.pop();
    sum += a[i];
    former[i-n+1] = sum;
  }
  sum = 0;
  for (int i=2*n;i<3*n;i++) {
    pq2.push(a[i]);
    sum += a[i];
  }
  latter[n] = sum;
  for (int i=2*n-1;i>=n;i--) {
    pq2.push(a[i]);
    sum -= pq2.top();
    pq2.pop();
    sum += a[i];
    latter[i-n] = sum;
  }
  ll ans = -1e16-7;
  for (int i=0;i<=n;i++) {
    ans = max(ans, former[i] - latter[i]);
  }
  cout << ans << endl;
}

int main() {
  cin >> n;
  for (int i=0;i<n*3;i++) {
    cin >> a[i];
  }
  solve();
}
