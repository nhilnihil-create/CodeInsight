#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define int long long
#define _GLIBCXX_DEBUG

signed main() {
  int K, T; cin >> K >> T;
  vector<int> a(T);
  rep(i, T) cin >> a[i];
  
  sort(all(a));
  
  int ans = 0;
  
  int k = 0;
  rep(i, T-1) k += a[i];
  
  if(k < a[T-1]) ans = a[T-1] - k - 1;
  
  
  cout << ans << endl;

}