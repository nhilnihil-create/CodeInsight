#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main(void) {
  int n;cin >> n;
  int t[n];rep(i,n) cin >> t[i];
  int m;cin >> m;
  int p[m], x[m];rep(i,m) cin >> p[i] >> x[i];
  ll cnt = 0;
  rep(i,m) {
    cnt = 0;
    rep(j,n) {
      if(j == (p[i]-1)) cnt+=x[i];
      else cnt+= t[j];
    }
    cout << cnt << endl;
  }
}