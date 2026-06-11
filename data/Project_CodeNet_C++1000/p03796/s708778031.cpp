#include <bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
signed main() {
  long long N;
  cin >> N;
  long long ans=1;
  for(int i=1; i<N+1; i++) {
    ans=ans*i%mod;
  }
  cout << ans << endl;
}