#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)n; i++)
using ll = long long;
const ll mod = 1e9+7;

ll query(int a,int b,int c,int d) {
  int l = max(a,c);
  int r = min(b,d);
  if(r-l < 0) return 0;
  else return r-l+1;
}

int main(){
  int n;
  cin >> n;
  int t[n], a[n];
  rep(i,n) cin >> t[i];
  rep(i,n) cin >> a[i];
  reverse(a,a+n);
  vector<int> lt(n,0), rt(n,0), la(n,0), ra(n,0);
  lt[0] = t[0]; rt[0] = t[0]; la[0] = a[0]; ra[0] = a[0];
  for(int i = 1; i < n; i++) {
    if(t[i] > t[i-1]) {
      lt[i] = t[i]; rt[i] = t[i];
    } else {
      lt[i] = 1; rt[i] = t[i];
    }
    if(a[i] > a[i-1]) {
      la[i] = a[i]; ra[i] = a[i];
    } else {
      la[i] = 1; ra[i] = a[i];
    }
  }
  reverse(la.begin(),la.end());
  reverse(ra.begin(),ra.end());
  ll ans = 1;
  rep(i,n) (ans *= query(lt[i],rt[i],la[i],ra[i])) %= mod;
  cout << ans << endl;
  return 0;
}