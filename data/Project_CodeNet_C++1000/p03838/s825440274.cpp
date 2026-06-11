#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep_(i, n, m) for (int i = n; i < (int)(m); i++)
#define all(v) v.begin(), v.end()
#define int long long
#define stoi stoll
//#define _GLIBCXX_DEBUG

signed main() {
  int x, y; cin >> x >> y;
  
  if(x < y) {
    if(x < 0 && y >= 0) cout << min(y-x, abs(y+x)+1) << endl;
    else cout << y-x << endl;
  } else {
    if(x < 0) cout << x-y+2 << endl;
    else if(x == 0) cout << -y+1 << endl;
    else if(y == 0) cout << x+y+1 << endl;
    else if(y > 0) cout << min(x+y+1, x-y+2) << endl;
    else cout << abs(x+y)+1 << endl;
  }
    
}