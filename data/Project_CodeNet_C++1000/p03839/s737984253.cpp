#include <bits/stdc++.h>
using namespace std;


int main() {
  int n, k;
  cin>>n>>k;
  vector<int> a(n);
  for (int i=0; i<n; i++) cin>>a[i];

  long long acc[n+1];
  long long plus_acc[n+1];
  acc[0] = 0;
  plus_acc[0] = 0;
  for (int i=0; i<n; i++) {
    acc[i+1] = acc[i] + a[i];
    if (a[i] > 0) {
      plus_acc[i+1] = plus_acc[i] + a[i];
    } else {
      plus_acc[i+1] = plus_acc[i];
    }
  }
  long long ans = -1e15;
  for (int i=0; i<=n-k; i++) {
    long long tmp = plus_acc[n] - plus_acc[i+k] + plus_acc[i];
    ans = max(tmp, ans);
    ans = max(tmp + acc[i+k] - acc[i], ans);
  }
  cout<<ans<<endl;
}