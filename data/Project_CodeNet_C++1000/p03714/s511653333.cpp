#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  int n;
  cin >> n;
  
  vector<ll> a(3 * n);
  for(int i = 0; i < 3 * n; i++) cin >> a.at(i);
  
  ll keep1, keep2;
  priority_queue<ll, vector<ll>, greater<ll>> pq1;
  priority_queue<ll> pq2;
  for(int i = 0; i < n; i++){
    keep1 += a.at(i);
    pq1.push(a.at(i));
    keep2 += a.at(3 * n - i - 1);
    pq2.push(a.at(3 * n - i - 1));
  }
  
  vector<ll> x(n + 1), y(n + 1);
  x.at(0) = keep1;
  y.at(n) = keep2;
  for(int i = 1; i <= n; i++){
    keep1 += a.at(n + i - 1);
    pq1.push(a.at(n + i - 1));
    keep1 -= pq1.top();
    pq1.pop();
    x.at(i) = keep1;
  }
  for(int i = n; i > 0; i--){
    keep2 += a.at(n + i - 1);
    pq2.push(a.at(n + i - 1));
    keep2 -= pq2.top();
    pq2.pop();
    y.at(i - 1) = keep2;
  }
  
  ll ans = -1e18;
  for(int i = 0; i <= n; i++){
    ans = max(ans, x.at(i) - y.at(i));
  }
  
  cout << ans << '\n';
}