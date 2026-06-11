#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define int long long
//#define _GLIBCXX_DEBUG


signed main() {
  string X; cin >> X;
  
  int ans = 0;
  int k = 0;
  rep(i, X.size()) {
    if(X[i] == 'T') {
      if(k == 0) ans++;
      else k--;
    } else {
      k++;
    }
  }
  ans += k;
  cout << ans << endl;
}
