#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep_(i, n, m) for (int i = n; i < (int)(m); i++)
#define all(v) v.begin(), v.end()
#define int long long
#define stoi stoll
//#define _GLIBCXX_DEBUG

signed main() {
  string s; cin >> s;
  string a = "abcdefghijklmnopqrstuvwxyz";
  
  if(s.size() == 1) {
    cout << 0 << endl;
    return 0;
  }
  
  vector<int> ans(26, 0);
  rep(i, 26) if(count(s.begin(), s.end(), a[i]) == 0) ans[i] = 1000000000;
  
  rep(i, 26) {
    int k = 0;
    rep(j, s.size()) {
      if(s[j] == a[i]) {
        ans[i] = max(ans[i], k);
        k = 0;
      } else {
        k++;
      }
    }
    ans[i] = max(ans[i], k);
  }
  //rep(i, 26) cout << a[i] << ans[i] << endl;
  sort(all(ans));
  cout << ans[0] << endl;
  
    
}