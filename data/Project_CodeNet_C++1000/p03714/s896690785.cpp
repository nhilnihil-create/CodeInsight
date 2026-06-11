#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(3 * n);
  long long lsum = 0, rsum = 0;
  priority_queue<long long, vector<long long>, greater_equal<long long>> l;
  priority_queue<long long, vector<long long> ,less_equal<long long>> r;
  for (int i = 0; i < 3*n; i++) {
    cin >> a[i];
    if (i < n) {
      lsum += a[i];
      l.push(a[i]);
    }
    if (i >= 2 * n) {
      rsum += a[i];
      r.push(a[i]);
    }
  }
  
  vector<long long> lsuma;
  lsuma.push_back(lsum);
  for (int i = n; i < 2 * n; i++) {
    if (lsum < lsum - l.top() + a[i]) {
      lsum += a[i] - l.top();
      l.pop();
      l.push(a[i]);
    }
    lsuma.push_back(lsum);
  }
  long long rsumr = rsum;
  vector<long long> rsuma;
  for (int i = 2 * n - 1; i >= n; i--) {
    if (rsum > rsum - r.top() + a[i]) {
      rsum += a[i] - r.top();
      r.pop();
      r.push(a[i]);
    }
    rsuma.push_back(rsum);
  }
  reverse(rsuma.begin(), rsuma.end());
  rsuma.push_back(rsumr);
  
  long long ans = -1e18;
  
  for(int i = 0; i <= n; i++) {
    ans = max(ans, lsuma[i] - rsuma[i]);
  }
  
  cout << ans << endl;
  
  return 0;
}
