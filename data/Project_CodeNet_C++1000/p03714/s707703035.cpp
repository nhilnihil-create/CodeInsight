#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin>>n;
  int a[3*n];
  for (int i=0; i<3*n; i++) cin>>a[i];

  priority_queue<int, vector<int>, greater<int>> pq1;
  long long dp1[3*n];
  long long v1 = 0;
  for (int i=0; i<n; i++) {
    pq1.push(a[i]);
    v1 += a[i];
  }
  dp1[n-1] = v1;
  for (int i=n; i<3*n; i++) {
    if (a[i] > pq1.top()) {
      v1 = v1 - pq1.top() + a[i];
      pq1.pop();
      pq1.push(a[i]);
    }
    dp1[i] = v1;
  }
  priority_queue<int> pq2;
  long long dp2[3*n];
  long long v2 = 0;
  for (int i=3*n-1; i>=2*n; i--) {
    pq2.push(a[i]);
    v2 += a[i];
  }
  dp2[2*n] = v2;
  for (int i=2*n-1; i>=0; i--) {
    if (a[i] < pq2.top()) {
      v2 = v2 - pq2.top() + a[i];
      pq2.pop();
      pq2.push(a[i]);
    }
    dp2[i] = v2;
  }
  long long ans = -1e14;
  for (int i=n-1; i<2*n; i++) {
    if (dp1[i] - dp2[i+1] > ans) {
      ans = dp1[i] - dp2[i+1];
    }
  }
  cout<<ans<<endl;
}