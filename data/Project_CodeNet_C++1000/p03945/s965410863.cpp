#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep_(i, n, m) for (int i = n; i < (int)(m); i++)
#define all(v) v.begin(), v.end()
#define int long long
#define stoi stoll
//#define _GLIBCXX_DEBUG


signed main() {
  string S; cin >> S;
  
  int ans = 0;
  char now = S[0];
  rep(i, S.size()) {
    if(S[i] != now) {
      ans++;
      now = S[i];
    }
  }
  cout << ans << endl;
}