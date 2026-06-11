#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n);i++)
#define sz(x) int(x.size())
typedef long long ll;
typedef pair<int,int> P;
const int mod = 1e9+7;


int main(){
  int n;
  cin >> n;
  vector<ll> t(n),a(n);
  rep(i,n) cin >> t[i];
  rep(i,n) cin >> a[i];

  vector<ll> l(n,0),r(n,0);
  if (t[n-1] != a[0]) {
    puts("0");
    return 0;
  }
  l[0] = 1;
  for (int i = 1; i < n ; i++) {
    if (t[i] > t[i-1]) {
      l[i] = 1;
      r[i] = t[i];
    } else {
      l[i] = t[i];
      r[i] = -1;
    }
  }
  l[n-1] = 1;
  bool ok = true;
  for (int i = n-2; i >= 0; i--) {
    if (r[i] != -1 && a[i] < r[i]) {
      ok = false;
      break;
    }
    if(a[i] > a[i+1]) l[i] = 1;
    else l[i] = min(l[i],a[i]);
  }
  ll res = 1;
  if(!ok) puts("0");
  else {
    rep(i,n) {
      res = (res * l[i]) % mod;
    }
    cout << res << endl;
  }
  return 0;
}