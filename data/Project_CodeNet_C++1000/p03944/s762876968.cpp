#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main(void) {
  int w,h,n;
  cin >> w >> h >> n;
  int x[n], y[n], a[n];
  rep(i,n) {cin >> x[i] >> y[i] >> a[i]; }
  int p=0, q=w, r=0, s=h;
  rep(i,n) {
    if(a[i] == 1) {
      if(p < x[i]) p = x[i];
    } else if (a[i] == 2) {
      if(q > x[i]) q = x[i];
    } else if (a[i] == 3) {
      if (r < y[i]) r = y[i];
    } else {
      if (s > y[i]) s = y[i];
    }
  }
  if (p < q && r < s) {
    cout << (q-p)*(s-r) << endl;
  } else {
    cout << 0 << endl;
  }
}