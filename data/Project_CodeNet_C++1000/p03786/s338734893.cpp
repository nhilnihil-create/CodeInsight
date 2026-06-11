#include <bits/stdc++.h>
using namespace std;
using lint  = long long;

signed main(){
  lint N; cin >> N;
  vector<lint> a(N), sum(N, 0);
  for(lint i = 0; i < N; i++){
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  for(lint i = 0; i < N; i++){
    if(i == 0) sum[i] = a[i];
    else sum[i] = sum[i - 1] + a[i];
  }
  lint ans = N;
  for(lint i = N - 1; i >= 1; i--){
    if(a[i] > 2 * sum[i - 1]){
      ans = N - i; break;
    }
  }
  cout << ans << endl;
}