#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)n; i++)
using ll = long long;

int main(){
  int n;
  cin >> n;
  ll a[n];
  rep(i,n) cin >> a[i];
  ll ans = 0;
  ll p = 0, q = 0;
  ll c = 0, d = 0;
  rep(i,n) {
    if(i % 2) {
      if(p + a[i] < 0) p += a[i];
      else {
        c += p + a[i] + 1;
        p = -1;
      }
    } else {
      if(p + a[i] > 0) p += a[i];
      else {
        c += 1 - (p + a[i]);
        p = 1;
      }
    }
  }
  rep(i,n) {
    if(i % 2 == 0) {
      if(q + a[i] < 0) q += a[i];
      else {
        d += q + a[i] + 1;
        q = -1;
      }
    } else {
      if(q + a[i] > 0) q += a[i];
      else {
        d += 1 - (q + a[i]);
        q = 1;
      }
    }
  }
  cout << min(c,d) << endl;
  return 0;
}
