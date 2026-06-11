#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
  int N;
  cin >> N;
  vector<int>vec(N*3);
  for(int i=0; i<N*3; i++){
    cin >> vec[i];
  }
  sort(vec.begin(),vec.end());
  reverse(vec.begin(),vec.end());
  int ans = 0;
  for(int i=1; i<=N; i++){
    ans += vec[i*2-1];
  }
  cout << ans << endl;
}
