#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define REP(i,n) for(int(i)=0;(i)<(n);++(i))

int main () {
  ll x, y;
  cin >> x >> y;
  if (x == 0) {
    if (y > 0) cout << y;
    else cout << -y + 1;
    return 0;
  }
  if (y == 0) {
    if (x > 0) cout << x + 1;
    else cout << -x;
    return 0;
  }
  
  if(abs(x - y) > abs(x + y)) {
    if (x + y > 0) cout << x + y + 1;
    else cout << -(x + y) + 1;
  } else {
    if (x - y > 0) cout << x - y + 2;
    else cout << -(x - y);
  } 
}
