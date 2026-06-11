#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
  int N,T;
  cin >> N >> T;
  vector<int>vec(N);
  int ans = 0;
  for(int i=0; i<N; i++){
    cin >> vec[i];
  }
  for(int i=0; i<N-1; i++){
    ans += min(T,vec[i+1]-vec[i]);
   }
   cout << ans+T << endl;
}