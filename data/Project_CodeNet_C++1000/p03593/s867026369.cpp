#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define int long long
//#define _GLIBCXX_DEBUG

signed main() {
  int H, W; cin >> H >> W;
  unordered_map<char,int> a;
  rep(i, H*W) {
    char c; cin >> c;
    a[c]++;
  }
  
  int four=0, two=0, one=0;
  
  for(auto p : a) {
    if(p.second%4 == 0) four++;
    else if(p.second%2 == 0) two++;
    else one++;
  }
  
  if(H%2 == 0 && W%2 == 0) {
    if(two == 0 && one == 0) cout << "Yes" << endl;
    else cout << "No" << endl;
  } else if(H%2 == 0) {
    if(two <= H/2 && one == 0) cout << "Yes" << endl;
    else cout << "No" << endl;
  } else if(W%2 == 0) {
    if(two <= W/2 && one == 0) cout << "Yes" << endl;
    else cout << "No" << endl;
  } else {
    if(two <= (H-1)/2 + (W-1)/2  && one == 1) cout << "Yes" << endl;
    else cout << "No" << endl;
  }

}
