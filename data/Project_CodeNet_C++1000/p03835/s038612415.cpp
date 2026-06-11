#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep_(i, n, m) for (int i = n; i < (int)(m); i++)
#define all(v) v.begin(), v.end()
#define int long long
#define stoi stoll
//#define _GLIBCXX_DEBUG

signed main() {
  int K, S; cin >> K >> S;
  
  int ans = 0;
  rep(x, K+1) rep(y, K+1) {
    int z = S-x-y;
    if(z >= 0 && z <= K) ans++;
  }
  cout << ans << endl;
  


}