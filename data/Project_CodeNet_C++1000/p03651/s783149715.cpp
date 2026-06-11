#include <bits/stdc++.h>
using namespace std;
using lint  = long long;

signed main(){
  lint N, K; cin >> N >> K;
  vector<lint> a(N);
  for(lint i = 0; i < N; i++) cin >> a[i];
  lint g = a[0];
  for(lint i = 1; i < N; i++) g = __gcd(a[i - 1], a[i]);
  lint m = *max_element(a.begin(), a.end());
  if(K % g == 0 && K <= m) cout << "POSSIBLE" << endl;
  else cout << "IMPOSSIBLE" << endl;
}