#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin>>n;
  int t[n], a[n];
  for (int i=0; i<n; i++) cin>>t[i];
  for (int i=0; i<n; i++) cin>>a[i];
  int max_h1[n], min_h1[n];
  max_h1[0] = min_h1[0] = t[0];

  for (int i=1; i<n; i++) {
    if (t[i] == t[i-1]) {
      max_h1[i] = max_h1[i-1];
      min_h1[i] = 1;
    } else {
      max_h1[i] = t[i];
      min_h1[i] = t[i];
    }
  }
  int max_h2[n], min_h2[n];
  max_h2[n-1] = min_h2[n-1] = a[n-1];
  for (int i=n-2; i>=0; i--) {
    if (a[i] == a[i+1]) {
      max_h2[i] = max_h2[i+1];
      min_h2[i] = 1;
    } else {
      max_h2[i] = a[i];
      min_h2[i] = a[i];
    }
  }
  long long ans  = 1;
  long long MOD = (int)1e9 + 7;
  for (int i=0; i<n; i++) {
    int x = min(max_h1[i], max_h2[i]) - max(min_h1[i], min_h2[i]);
    if (x < 0) {
      ans = 0;
      break;
    }
    ans = (ans * (x + 1)) % MOD;
  }
  cout<<ans<<endl;
}