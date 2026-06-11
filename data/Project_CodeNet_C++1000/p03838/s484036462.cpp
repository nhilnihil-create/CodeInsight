#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int x, y;
  cin >> x >> y;
  int ans;
  if(x==y) {
    cout << 0 << endl;
    return 0;
  }
  if(x==-y) {
    cout << 1 << endl;
    return 0;
  }
  if(abs(x)>abs(y)) {
    ans = abs(x)-abs(y);
    if(x>0) ans++;
    if(y>0) ans++;
    cout << ans << endl;
    return 0;
  }
  else {
    ans = abs(y)-abs(x);
    if(x<0) ans++;
    if(y<0) ans++;
    cout << ans << endl;
    return 0;
  }
}
