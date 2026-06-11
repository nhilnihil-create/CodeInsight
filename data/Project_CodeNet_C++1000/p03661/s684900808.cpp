#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
  int N;
  cin >> N;

  vector<int> a(N);
  int sum = 0;
  for ( int i = 0; i < N; i++ ) {
    cin >> a[i];
    sum += a[i];
  }

  int ans = 1e15;
  int now = 0;  
  for ( int i = 0; i < N-1; i++ ) {
    now += a[i];
    sum -= a[i];    
    ans = min(ans, abs(sum-now));    
  }

  cout << ans << endl;
  
  return 0;  
}
