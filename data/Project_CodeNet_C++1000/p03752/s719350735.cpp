#include <bits/stdc++.h>
using namespace std;
using lint = long long;

signed main(){
  lint N, K; cin >> N >> K;
  vector<lint> a(N);
  lint ans = 1e18;
  for(lint i = 0; i < N; i++) cin >> a[i];
  
  for(lint bit = 0; bit < (1 << N - 1); bit++){
    lint counter = 0;
    for(lint i = 0; i < N - 1; i++){
      if(bit & 1 << i) counter++;
    }
    if(counter != K - 1) continue;
    lint ans1 = 0, bound = a[0];
    for(lint i = 0; i < N - 1; i++){
      if(bit & 1 << i){
        if(bound >= a[i + 1]){
          ans1 += bound - a[i + 1] + 1;
          bound++;
        }
        else bound = a[i + 1];
      }
      else{
        bound = max(bound, a[i + 1]);
      }
    }
    ans = min(ans, ans1);
  }
  cout << ans << endl;
}