#include<bits/stdc++.h>
using namespace std;
using lint = long long;

signed main() {
  lint N; cin >> N;
  vector<lint> a(N);
  lint ans = 0, sum = 0;
  for(int i = 0; i < N; i++){
    cin >> a[i];
    if(a[i] == 0){
      ans += sum/2;
      sum = 0;
    }
    sum += a[i];
  }
  ans += sum/2;
  cout << ans << endl;
}