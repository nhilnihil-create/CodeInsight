#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int n; cin >> n;
  int k; cin >> k;
  vector<int> x(n);
  for (int i=0; i<n; i++) {
    cin >> x[i];
  }
  
  int ans = 0;
  
  for (int i=0; i<n; i++) {
    ans += min(x[i], k-x[i]) * 2;
  }
  
  cout << ans << endl;
  return 0;
}