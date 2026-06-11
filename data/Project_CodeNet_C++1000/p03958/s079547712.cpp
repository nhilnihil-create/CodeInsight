#include <bits/stdc++.h>
using namespace std;

signed main(){
  int K, T; cin >> K >> T;
  vector<int> a(T);
  for(int i = 0; i < T; i++) cin >> a[i];
  int x = *max_element(a.begin(), a.end());
  int ans = max(0, 2*x - 1 - K);
  cout << ans << endl;
}